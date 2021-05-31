#pragma once

#include <SPI.h>
#include "Arduino.h"

#define IOCON_A 0x0A
#define IOCON_B 0x0B
#define IODIR_A 0x00
#define IODIR_B 0x01
#define GPPU_A 0x0C
#define GPPU_B 0x0D
#define GPIO_A 0x12
#define GPIO_B 0x13
#define GPINTEN_A 0x04
#define GPINTEN_B 0x05
#define IPOL_A 0x02
#define IPOL_B 0x03
#define DEFVAL_A 0x06
#define DEFVAL_B 0x07
#define INTF_A 0x0E
#define INTF_B 0x0F
#define INTCAP_A 0x10
#define INTCAP_B 0x11
#define OLAT_A 0x14
#define OLAT_B 0x15
#define INTCON_A 0x08
#define INTCON_B 0x09

#define PORT_INPUT 1
#define PORT_OUTPUT 0

#define PORT_A 0
#define PORT_B 1

#define WRITE_MCP 0b001000000
#define READ_MCP 0b001000001

class MCP23S17
{
 public:
    union IODIR_t
    {
        struct
        {
            unsigned char IOD0 : 1;
            unsigned char IOD1 : 1;
            unsigned char IOD2 : 1;
            unsigned char IOD3 : 1;
            unsigned char IOD4 : 1;
            unsigned char IOD5 : 1;
            unsigned char IOD6 : 1;
            unsigned char IOD7 : 1;
        };
        unsigned char IOD;
    };

    union IPOL_t
    {
        struct
        {
            unsigned char IOP0 : 1;
            unsigned char IOP1 : 1;
            unsigned char IOP2 : 1;
            unsigned char IOP3 : 1;
            unsigned char IOP4 : 1;
            unsigned char IOP5 : 1;
            unsigned char IOP6 : 1;
            unsigned char IOP7 : 1;
        };
        unsigned char IPO;
    };

    union GPINTEN_t
    {
        struct
        {
            unsigned char GPINT0 : 1;
            unsigned char GPINT1 : 1;
            unsigned char GPINT2 : 1;
            unsigned char GPINT3 : 1;
            unsigned char GPINT4 : 1;
            unsigned char GPINT5 : 1;
            unsigned char GPINT6 : 1;
            unsigned char GPINT7 : 1;
        };
        unsigned char GPINT;
    };

    union DEFVAL_t
    {
        struct
        {
            unsigned char DEF0 : 1;
            unsigned char DEF1 : 1;
            unsigned char DEF2 : 1;
            unsigned char DEF3 : 1;
            unsigned char DEF4 : 1;
            unsigned char DEF5 : 1;
            unsigned char DEF6 : 1;
            unsigned char DEF7 : 1;
        };
        unsigned char DEF;
    };

    union INTCON_t
    {
        struct
        {
            unsigned char IOC0 : 1;
            unsigned char IOC1 : 1;
            unsigned char IOC2 : 1;
            unsigned char IOC3 : 1;
            unsigned char IOC4 : 1;
            unsigned char IOC5 : 1;
            unsigned char IOC6 : 1;
            unsigned char IOC7 : 1;
        };
        unsigned char IOC;
    };

    union IOCON_t
    {
        struct
        {
            unsigned char : 1;
            unsigned char INTPOL : 1;
            unsigned char ODR : 1;
            unsigned char HAEN : 1;
            unsigned char DISSLW : 1;
            unsigned char SEQOP : 1;
            unsigned char MIRROR : 1;
            unsigned char BANK : 1;
        };
        unsigned char IOCON;
    };

    union GPPU_t
    {
        struct
        {
            unsigned char PU0 : 1;
            unsigned char PU1 : 1;
            unsigned char PU2 : 1;
            unsigned char PU3 : 1;
            unsigned char PU4 : 1;
            unsigned char PU5 : 1;
            unsigned char PU6 : 1;
            unsigned char PU7 : 1;
        };
        unsigned char PU;
    };

    union INTF_t
    {
        struct
        {
            unsigned char INT0 : 1;
            unsigned char INT1 : 1;
            unsigned char INT2 : 1;
            unsigned char INT3 : 1;
            unsigned char INT4 : 1;
            unsigned char INT5 : 1;
            unsigned char INT6 : 1;
            unsigned char INT7 : 1;
        };
        unsigned char INT;
    };

    union INTCAP_t
    {
        struct
        {
            unsigned char ICP0 : 1;
            unsigned char ICP1 : 1;
            unsigned char ICP2 : 1;
            unsigned char ICP3 : 1;
            unsigned char ICP4 : 1;
            unsigned char ICP5 : 1;
            unsigned char ICP6 : 1;
            unsigned char ICP7 : 1;
        };
        unsigned char ICP;
    };

    union GPIO_t
    {
        struct
        {
            unsigned char IO0 : 1;
            unsigned char IO1 : 1;
            unsigned char IO2 : 1;
            unsigned char IO3 : 1;
            unsigned char IO4 : 1;
            unsigned char IO5 : 1;
            unsigned char IO6 : 1;
            unsigned char IO7 : 1;
        };
        unsigned char IO;
    };

    union OLAT_t
    {
        struct
        {
            unsigned char OL0 : 1;
            unsigned char OL1 : 1;
            unsigned char OL2 : 1;
            unsigned char OL3 : 1;
            unsigned char OL4 : 1;
            unsigned char OL5 : 1;
            unsigned char OL6 : 1;
            unsigned char OL7 : 1;
        };
        unsigned char OL;
    };

    //MCP23S17();
    //virtual ~MCP23S17();

    void Init(short csPin);
    void Init(short csPin, short intPinA);
    void Init(short csPin, short intPinA, short intPinB);
    char ReadPortA();
    char ReadPortB();
    void WritePortA(char data);
    void WritePortB(char data);
    void SetPin(char port, char pin, char state);
    char GetIntStatus(char port);
    void SetPortDirection(char port, char direction);
    void SetPinDirection(char port, char pin, char direction);

 private:
    short slaveSelectPin;
    int speed;
    SPISettings spiSettingsMcp23s17{1000000, MSBFIRST, SPI_MODE0};

    void writeByte(char data, char address);
    char readByte(char address);
    char readSpiData(char address);
};
