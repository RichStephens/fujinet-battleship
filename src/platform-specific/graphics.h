/*
 Platform specific graphics commands
*/

#ifndef GRAPHICS_H
#define GRAPHICS_H

#define PARTIAL_LEFT 1
#define PARTIAL_RIGHT 2
#define FULL_CARD 3

#include <stdint.h>
#include <stdbool.h>
#include "../misc.h"

// Call to clear the screen, passing true to preserve borders
void resetScreen();

uint8_t cycleNextColor();

void drawText(uint8_t x, uint8_t y, const char *s);
void drawTextAlt(uint8_t x, uint8_t y, const char *s);

void drawIcon(uint8_t x, uint8_t y, uint8_t icon);

void drawShip(uint8_t size, uint8_t pos, bool hide);
void drawLegendShip(uint8_t player, uint8_t index, uint8_t size, uint8_t status);
void drawPlayerName(uint8_t player, const char *name, bool active);

void drawGamefield(uint8_t quadrant, uint8_t *field);
void drawGamefieldUpdate(uint8_t quadrant, uint8_t *gamefield, uint8_t attackPos, uint8_t blink);
void drawGamefieldCursor(uint8_t quadrant, uint8_t x, uint8_t y, uint8_t *gamefield, uint8_t blink);

void drawClock();
void drawConnectionIcon(bool show);
void drawBlank(uint8_t x, uint8_t y);
void drawSpace(uint8_t x, uint8_t y, uint8_t w);
void drawLine(uint8_t x, uint8_t y, uint8_t w);
void drawBox(uint8_t x, uint8_t y, uint8_t w, uint8_t h);
void drawBoard(uint8_t playerCount);

// Call to save screen buffer for later restore. Returns false
// if screen buffer not supported
bool saveScreenBuffer();
void restoreScreenBuffer();

void initGraphics();
void resetGraphics();
void waitvsync();
#endif /* GRAPHICS_H */