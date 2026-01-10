/**
 * @file image.h
 * @brief Abstract image data structure and basic operations.
 * 
 * This module defines a minimal, generic image representation.
 * No assumptions are made about color space, pixel format,
 * or human-visibility of the data.
 */

#ifndef IMAGE_H
#define IMAGE_H

#include <stddef.h>
#include <stdint.h>

/**
 * @struct image
 * @brief Abstract image container.
 * 
 * Represents a 2D array with an arbitrary number of channels.
 * The interpretation of channels is left to higher-level code.
 */
struct image {
    size_t width;
    size_t height;
    size_t channels;
    uint8_t *data;
};

/**
 * @brief Allocate a new image.
 * 
 * Allocates memory for an image with the given dimensions and channels.
 * 
 * @param width image width
 * @param height image height
 * @param channels number of channels
 * 
 * @return Pointer to a newly allocated image, or nullptr on failure.
 */
struct image *create_image(size_t width, size_t height, size_t channels);

/**
 * @brief Free an image.
 * 
 * Frees the image data buffer and the image structure itself.
 * 
 * @param img Image to free (may be nullptr)
 */
void free_image(struct image *img);

#endif // IMAGE_H