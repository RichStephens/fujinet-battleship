

#include <string.h>
#include <stdint.h>
#include <conio.h>
#include "../platform-specific/sound.h"
#include "hires.h"

extern uint8_t charset[];
uint8_t background = 0;

/*-----------------------------------------------------------------------*/
void hires_putc(uint8_t x, uint8_t y, uint8_t rop, uint8_t c)
{
    hires_Draw(x, y, 1, 8, rop, &charset[(uint16_t)c << 3]);
}

/*-----------------------------------------------------------------------*/
void hires_putcc(uint8_t x, uint8_t y, uint8_t rop, uint16_t cc)
{
    hires_putc(x, y, rop, (uint8_t)(cc >> 8));
    hires_putc(++x, y, rop, (uint8_t)cc);
}

void hires_Mask(uint8_t x, uint8_t y, uint8_t xlen, uint8_t ylen, uint8_t c)
{
    uint8_t *pos = (uint8_t *)SCREEN + (uint16_t)y * 32 + x;
    ylen++;
    while (--ylen)
    {
        memset(pos, c, xlen);
        pos += 32;
    }
}

void hires_Draw(uint8_t x, uint8_t y, uint8_t xlen, uint8_t ylen, uint8_t rop, uint8_t *src)
{
    uint8_t *pos = (uint8_t *)SCREEN + (uint16_t)y * 32 + x;
    uint8_t c;
    if (background)
    {
        for (c = 0; c < ylen; ++c)
        {
            memset(pos, (background ^ *(src + (c % 8))) | (*(src + (c % 8)) & rop), xlen);
            pos += 32;
        }
    }
    else
    {
        for (c = 0; c < ylen; ++c)
        {
            memset(pos, (*(src + (c % 8)) & rop), xlen);
            pos += 32;
        }
    }
}
