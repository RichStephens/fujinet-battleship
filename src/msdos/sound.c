/*
  Platform specific sound functions
*/

#include <stdint.h>
#include <stdlib.h>
#include "../misc.h"
#include "../platform-specific/sound.h"

uint16_t ii;

void tone(uint8_t period, uint8_t dur, uint8_t wait)
{
}

// // Keeping this here in case I need it
// void toneFinder() {
//   clearCommonInput();
//   while (input.key != KEY_RETURN || i<2) {
//     while (!kbhit());
//     input.key = cgetc();
//     switch (input.key) {
//       case KEY_DOWN_ARROW: i--; break;
//       case KEY_UP_ARROW: i++; break;
//       case KEY_RIGHT_ARROW: i+=20; break;
//       case KEY_LEFT_ARROW: i-=20; break;
//       case KEY_ESCAPE: return;
//     }

//     printf("%d ",i);
//     tone(i,1,0);
//   }
// }

void initSound() {}

void soundJoinGame()
{
}

void soundFujitzee()
{
}

void soundMyTurn()
{
}

void soundGameDone()
{
}

void soundCursor()
{
}

void soundPlaceShip()
{
}

void soundTick()
{
}

void soundSelect()
{
}

void soundMiss()
{
}

void soundInvalid()
{
}

void soundAttack()
{
}

void soundHit()
{
}

// Not applicable to CoCo
void soundStop() {}
void disableKeySounds() {}
void enableKeySounds() {}
