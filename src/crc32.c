#include "crc32.h"

#include <stddef.h>
#include <stdint.h>

static uint32_t crc32_table[256];

static void init_crc32_table(void)
{
    uint32_t crc32 = 1;
    for (uint32_t i = 128; i; i >>= 1) {
        crc32 = (crc32 >> 1) ^ (crc32 & 1 ? 0xEDB88320 : 0);
        for (uint32_t j = 0; j < 256; j += 2 * i) {
            crc32_table[i + j] = crc32 ^ crc32_table[j];
        }
    }
}

uint32_t crc32(const uint8_t *buffer, size_t length)
{
    uint32_t crc32 = 0xFFFFFFFF;

    if (crc32_table[255] == 0) {
        init_crc32_table();
    }

    for (size_t i = 0; i < length; i++) {
        crc32 ^= buffer[i];
        crc32 = (crc32 >> 8) ^ crc32_table[crc32 & 0xFF];
    }

    crc32 ^= 0xFFFFFFFF;
    return crc32;
}