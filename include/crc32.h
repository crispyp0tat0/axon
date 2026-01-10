/**
 * @file crc32.h
 * @brief CRC32 checksum calculation
 * 
 * CRC-32 implementation as defined by ISO/IEC 13239:2022 (formerly ISO/IEC 3309:1993) and ITU-T V.42.
 * Provides a function to compute the CRC32 checksum of a given buffer.
 * 
 * @author Gian Carlo Bata
 * @date 2026-01-11
 * @version 1.0
 * @copyright GPL-2.0
 * @see https://en.wikipedia.org/wiki/Cyclic_redundancy_check
 * @see https://www.iso.org/standard/37010.html
 * @see https://www.itu.int/rec/T-REC-V.42-200203-I/en
 */

#ifndef CRC32_H
#define CRC32_H

#include <stddef.h>
#include <stdint.h>

/**
 * @brief Calculate the CRC-32 checksum of a buffer.
 * 
 * Calculates the CRC32 checksum for the given input buffer using the standard polynomial 0xEDB88320.
 * 
 * @param buffer Pointer to the input data buffer.
 * @param length Length of the input data buffer in bytes.
 * @return The computed CRC32 checksum.
 */
uint32_t crc32(const uint8_t *buffer, size_t length);

#endif // CRC32_H