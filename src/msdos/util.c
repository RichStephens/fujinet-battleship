#include <stdlib.h>
#include <stdint.h>
#include "../fujinet-fuji.h"
#include "../platform-specific/graphics.h"

#include "../fujinet-fuji.h"
#include "../fujinet-network.h"

#define FUJI_HOST_SLOT_COUNT 8
#define FUJI_DEVICE_SLOT_COUNT 8

HostSlot host_slots[FUJI_HOST_SLOT_COUNT];
DeviceSlot device_slots[FUJI_DEVICE_SLOT_COUNT];

void resetTimer()
{
}

uint16_t getTime()
{
    return 0;
}

/// @brief Invokes the CoCo BASIC RUNM command
/// @param filename
void runm(char *filename)
{
}

void mount()
{
}

void quit()
{
    resetGraphics();
    exit(0);
}

void housekeeping()
{
    // Not needed on CoCo
}

uint8_t getJiffiesPerSecond()
{
    return 60;
}

uint8_t getRandomNumber(uint8_t maxExclusive)
{
    return 0;
}
