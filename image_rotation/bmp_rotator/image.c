#include <stdlib.h>

#include "image.h"

uint32_t padding(uint32_t width) {
	return (4 - width * sizeof(struct pixel) % 4) % 4;
}

struct image create_image(uint32_t width, uint32_t height) {
	struct pixel* pixels = (struct pixel*)malloc(sizeof(struct pixel) * width * height);

	return (struct image) {
		.width = width,
			.height = height,
			.pixels = pixels
	};
}

void destroy_image(struct image* image) {
	free(image->pixels);
}