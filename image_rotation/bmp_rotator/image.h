#ifndef _IMAGE_H_
#define _IMAGE_H_

#include <stdint.h>

struct pixel {
	uint8_t b; 
	uint8_t g; 
	uint8_t r; 
};

struct image {
	uint32_t width; 
	uint32_t height; 
	struct pixel* pixels; 
};

uint32_t padding(uint32_t width);
struct image create_image(uint32_t, uint32_t); 
void destroy_image(struct image*);

#endif