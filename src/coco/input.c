#include <coco.h>

#define JOY_CENTER   31
#define JOY_HALF     16

#define JOY_LOW_TH   (JOY_CENTER - JOY_HALF)   /* 15 */
#define JOY_HIGH_TH  (JOY_CENTER + JOY_HALF)   /* 47 */

static char lastKey = 0;

uint8_t kbhit(void)
{
    return (char)(lastKey || (lastKey = inkey()) || (lastKey = inkey()));
}

char cgetc(void)
{
    char key = lastKey;

    lastKey = 0;

    while (!key)
    {
        key = (char)inkey();
    }

    return key;
}

byte readJoystick(void)
{
    byte value = 0;

    const byte *joy = readJoystickPositions();
    byte buttons = readJoystickButtons();   /* active-high */

    /* Only reading left joystick. */
    /* There doesn't appear to be reliable way to */
    /* determine if a joystick is connected or not */

    /* NOTE: As of right now, the enum in the coco.h */
    /* header file is incorrect for the button values. */
    BOOL btn1  = (buttons & 0x02 ) == 0;
    BOOL btn2  = (buttons & 0x08 ) == 0;

    byte h = joy[JOYSTK_LEFT_HORIZ];
    byte v = joy[JOYSTK_LEFT_VERT];

    /* Direction bits: UP, DOWN, LEFT, RIGHT
       Vertical: 0 = UP, 63 = DOWN */
    if (v <= JOY_LOW_TH)   value |= 1;   /* up */
    if (v >= JOY_HIGH_TH)  value |= 2;   /* down */
    if (h <= JOY_LOW_TH)   value |= 4;   /* left */
    if (h >= JOY_HIGH_TH)  value |= 8;   /* right */

    /* Button bits */
    if (btn1) value |= 16;  /* bit 4 = button 1 */
    if (btn2) value |= 32;  /* bit 5 = button 2 */

    return value;
}

