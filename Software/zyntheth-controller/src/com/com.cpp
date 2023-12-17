#include "com.hpp"
#include "log.hpp"

Com::Com(ValueContainer& valueCon) : vc{valueCon}
{
}

void Com::Send()
{
    CAN_message_t msg;
    msg.buf[0] = 0x01;
    msg.len    = 1;
    msg.id     = 0x10;
    Can0.write(msg);
    LOG_DEBUG("Sent CAN message.");
}
