#include "image.h"

#include <stdlib.h>

struct image *create_image(size_t width, size_t height, size_t channels)
{
    // Validate input parameters
    if (width == 0 || height == 0 || channels == 0) {
        return nullptr;
    }

    // Allocate the image structure
    struct image *img = malloc(sizeof(struct image));
    if (!img) {
        return nullptr;
    }

    // Initialize image properties
    img->width = width;
    img->height = height;
    img->channels = channels;
    
    // Allocate the image data buffer
    img->data = malloc(sizeof(uint8_t) * width * height * channels);
    if (!img->data) {
        free(img);
        return nullptr;
    }

    return img;
}


void free_image(struct image *img)
{
    // Check for nullptr
    if (!img) {
        return;
    }

    // Free the data buffer and the image structure
    free(img->data);
    free(img);
}