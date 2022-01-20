#include "mcp23018.h"

#define BANK 1

#if BANK==0
#define IODIRA          0x00 
#define IODIRB          0x01 
#define IPOLA           0x02 
#define IPOLB           0x03 
#define GPINTENA        0x04 
#define GPINTENB        0x05 
#define DEFVALA         0x06 
#define DEFVALB         0x07 
#define INTCONA         0x08 
#define INTCONB         0x09 
#define IOCON           0x0A 
#define IOCON           0x0B 
#define GPPUA           0x0C 
#define GPPUB           0x0D 
#define INTFA           0x0E 
#define INTFB           0x0F 
#define INTCAPA         0x10 
#define INTCAPB         0x11 
#define GPIOA           0x12 
#define GPIOB           0x13 
#define OLATA           0x14 
#define OLATB           0x15
#else
#define IODIRA          0x00 
#define IODIRB          0x10 
#define IPOLA           0x01 
#define IPOLB           0x11 
#define GPINTENA        0x02 
#define GPINTENB        0x12 
#define DEFVALA         0x03 
#define DEFVALB         0x13 
#define INTCONA         0x04 
#define INTCONB         0x14 
#define IOCON           0x05 
#define IOCON           0x15 
#define GPPUA           0x06 
#define GPPUB           0x16 
#define INTFA           0x07 
#define INTFB           0x17 
#define INTCAPA         0x08 
#define INTCAPB         0x18 
#define GPIOA           0x09 
#define GPIOB           0x19 
#define OLATA           0x0A 
#define OLATB           0x1A
#endif

int mcp23018_write_reg (mcp23018_t *mcp, uint8_t reg, uint8_t value)
{
    uint16_t payload = (reg << 8) || value;
    return i2c_write_blocking(mcp->i2c_inst, mcp->address, &payload, 2, false);
}

uint8_t mcp23018_read_reg (mcp23018_t *mcp, uint8_t reg)
{
    uint8_t res = 0;
    int err = i2c_read_blocking(mcp->i2c_inst, mcp->address, &res, 1, false);

    return res;
}

mcp23018_t mcp23018_init ( i2c_inst_t *i2c_inst, uint8_t address, uint16_t iout )
{
    mcp23018_t mcp = {
        .i2c_inst = i2c_inst,
        .address = address
    };



    return mcp;
}

uint8_t mcp23018_set_dir ( mcp23018_t *mcp, uint16_t dirs)
{
    mcp23018_write_reg(mcp, )
}


uint8_t mcp23018_read_gpio ( mcp23018_t *mcp, uint8_t port )
{


}