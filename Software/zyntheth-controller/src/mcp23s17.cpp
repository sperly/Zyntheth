#include "mcp23s17.hpp"
#include "log.hpp"

//MCP23S17::MCP23S17()
//{

//}

void MCP23S17::Init(short csPin)
{
    Init(csPin, 255, 255);
}

void MCP23S17::Init(short csPin, short intPinA)
{
    Init(csPin, intPinA, 255);
}

void MCP23S17::Init(short csPin, short intPinA, short intPinB)
{
    LOG_DEBUG("Initializing...");
    slaveSelectPin = csPin;
    pinMode(slaveSelectPin, OUTPUT);
    digitalWrite(slaveSelectPin, HIGH);

    SPI1.begin();

    IOCON_t iocon;
    if (intPinA != 255 && intPinB != 255)
    {
        iocon.MIRROR = 0;
        pinMode(intPinA, INPUT);
        pinMode(intPinB, INPUT);
        LOG_DEBUG("Using INT A & B as interrupt pin");
    }
    else if (intPinA != 255)
    {
        iocon.MIRROR = 1;

        LOG_DEBUG("Using INT A as interrupt pin");
    }
    else
    {
        iocon.MIRROR = 0;
        pinMode(intPinA, OUTPUT);
        pinMode(intPinB, OUTPUT);
        LOG_DEBUG("Using no interrupt pin");
    }

    iocon.HAEN   = 0;
    iocon.ODR    = 0;
    iocon.INTPOL = 0;
    writeByte(IOCON_A, iocon.IOCON);

    IPOL_t ipol;
    ipol.IPO = 0xFF;
    writeByte(IPOL_A, ipol.IPO);
    writeByte(IPOL_B, ipol.IPO);

    GPINTEN_t gpinten;
    gpinten.GPINT = 0xFF;
    writeByte(GPINTEN_A, gpinten.GPINT);
    writeByte(GPINTEN_B, gpinten.GPINT);

    INTCON_t intcon;
    intcon.IOC = 0x00;
    writeByte(INTCON_A, intcon.IOC);
    writeByte(INTCON_B, intcon.IOC);

    GPPU_t gppu;
    gppu.PU = 0xFF;
    writeByte(GPPU_A, gppu.PU);
    writeByte(GPPU_B, gppu.PU);
    LOG_DEBUG("Initializing done.");
}

void MCP23S17::SetPortDirection(char port, char direction)
{
    IODIR_t iodir = {direction, direction, direction, direction, direction, direction, direction, direction};
    writeByte((port ? IODIR_B : IODIR_A), iodir.IOD);
}

void MCP23S17::SetPinDirection(char port, char pin, char direction)
{
    IODIR_t dir_conf;
    dir_conf.IOD = readByte((port ? IODIR_B : IODIR_A));
    if (direction == 0)
    {
        dir_conf.IOD &= ~(1 << pin);
    }
    else
    {
        dir_conf.IOD |= (1 << pin);
    }
    writeByte((port ? IODIR_B : IODIR_A), dir_conf.IOD);
}

void MCP23S17::writeByte(char address, char data)
{
    digitalWrite(slaveSelectPin, LOW);
    SPI1.beginTransaction(spiSettingsMcp23s17);
    SPI1.transfer(WRITE_MCP);
    SPI1.transfer(address);
    SPI1.transfer(data);
    SPI1.endTransaction();
    digitalWrite(slaveSelectPin, HIGH);
    //LOG_DEBUG("Wrote 0x%02X to 0x%02X", data, address);
}

char MCP23S17::readByte(char address)
{
    char retval;
    digitalWrite(slaveSelectPin, LOW);
    SPI1.beginTransaction(spiSettingsMcp23s17);
    SPI1.transfer(READ_MCP);
    SPI1.transfer(address);
    retval = SPI1.transfer(0);
    SPI1.endTransaction();
    digitalWrite(slaveSelectPin, HIGH);
    //LOG_DEBUG("Read 0x%02X from 0x%02X", retval, address);
    return retval;
}

char MCP23S17::ReadPortA()
{
    return readByte(GPIO_A);
}

char MCP23S17::ReadPortB()
{
    return readByte(GPIO_B);
}

void MCP23S17::WritePortB(char data)
{
    writeByte(OLAT_B, data);
}

void MCP23S17::SetPin(char port, char pin, char state)
{
    char curState = readByte((port ? GPIO_B : GPIO_A));
    if (state == 0)
    {
        curState &= ~(1 << pin);
    }
    else
    {
        curState |= (1 << pin);
    }
    writeByte((port ? GPIO_B : GPIO_A), curState);
}

char MCP23S17::GetIntStatus(char port)
{
    return (port ? readByte(INTF_B) : readByte(INTF_A));
}

// void readSpiData(int address, int value) {
//   // gain control of the SPI port
//   // and configure settings
//   SPI.beginTransaction(SPISettings(4000000, MSBFIRST, SPI_MODE0));
//   // take the SS pin low to select the chip:
//   digitalWrite(slaveSelectPin,LOW);
//   //  send in the address and value via SPI:
//   SPI.transfer(address);
//   SPI.transfer(value);
//   // take the SS pin high to de-select the chip:
//   digitalWrite(slaveSelectPin,HIGH);
//   // release control of the SPI port
//   SPI.endTransaction();
// }

// pinMode(ENC_INT_A, INPUT); // sets the digital pin as output
//     attachInterrupt(ENC_INT_A, ISR_EncIntA, FALLING); // interrrupt 1 is data ready

//     // set the slaveSelectPin as an output:
//
//     // initialize SPI:
//     SPI.begin();