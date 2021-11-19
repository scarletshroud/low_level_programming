#include "image_rotator.h"

struct image rotate_image(struct image const source) {
	struct image new_image = create_image(source.height, source.width);

	for (uint32_t i = 0; i < source.height; ++i) {
		for (uint32_t j = 0; j < source.width; ++j) {
			new_image.pixels[(source.height - 1) - i + source.height * j]
				= source.pixels[j + source.width * i];
		}
	}

	return new_image;
}