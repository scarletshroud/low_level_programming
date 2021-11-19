#include <stdbool.h>

#include "bmp_file.h"
#include "bmp_header.h"
#include "errors.h"

bool read_header(FILE* in, struct bmp_header* header) {
	return fread(header, sizeof(struct bmp_header), 1, in);
}

bool write_header(FILE* out, struct bmp_header* const header) {
	return fwrite(header, sizeof(struct bmp_header), 1, out); 
}

enum read_status read_body(FILE* in, const struct bmp_header header, struct image* image) {
	for (uint32_t i = 0; i < header.biHeight; ++i) {
		uint32_t amount = fread(image->pixels + i * image->width, sizeof(struct pixel), header.biWidth, in); 

		if (amount != image->width) {
			return READ_INVALID_BITS; 
		}

		if (fseek(in, padding(header.biWidth), 1) != 0) {
			return READ_INVALID_BITS; 
		}
	}

	return READ_OK;
}

enum write_status write_body(FILE* out, const struct image image) {
	uint32_t padding_value = 0; 
	for (uint32_t i = 0; i < image.height; ++i) {
		uint32_t amount = fwrite(&(image.pixels[i * image.width]), sizeof(struct pixel), image.width, out);

		if (amount != image.width) {
			return WRITE_INVALID_BITS;
		}

		amount = fwrite(&padding_value, 1, padding(image.width), out);

		if (amount != padding(image.width)) {
			return WRITE_INVALID_BITS;
		}
	}

	return WRITE_OK;
}

enum read_status from_bmp(FILE* in, struct image* image) {
	struct bmp_header header = { 0 };
	if (!read_header(in, &header)) {
		return READ_ERROR;
	}

	if (!validate_bmp_header(header)) {
		return READ_INVALID_HEADER; 
	}

	*image = create_image(header.biWidth, header.biHeight);

	enum read_status r_body_st = read_body(in, header, image);
	if (r_body_st != READ_OK) {
		destroy_image(image);
		return r_body_st;
	}
	
	return READ_OK;
}

enum write_status to_bmp(FILE* out, struct image const* image) {
	if (image == NULL) {
		return UNABLE_WRITE_IMAGE; 
	}

	struct bmp_header bmp_header = create_bmp_header(*image); 

	if (!write_header(out, &bmp_header)) {
		return WRITE_ERROR;
	}

	return write_body(out, *image);
}

enum file_status close_file(FILE* f) {
	if (f == NULL) {
		return FILE_CLOSE_ERROR;
	}

	fclose(f);
	return FILE_CLOSE_OK;
}

enum read_status read_file(const char* path, struct image* image) {
	if (path == NULL) {
		return READ_ERROR; 
	}

	FILE* f = fopen(path, "rb"); 
	if (f == NULL) {
		return READ_ERROR; 
	}

	enum read_status r_st = from_bmp(f, image); 
	if (r_st != READ_OK) {
		return r_st;
	}

	enum file_status c_st = close_file(f);
	if (c_st != FILE_CLOSE_OK) {
		return READ_ERROR;
	}

	return FILE_READ_OK;
}

enum write_status write_file(const char* path, struct image const* image) {
	if (path == NULL) {
		return WRITE_ERROR;
	}

	FILE* f = fopen(path, "wb");
	if (f == NULL) {
		return WRITE_ERROR;
	}

	enum write_status wr_st = to_bmp(f, image);
	if (wr_st != WRITE_OK) {
		return wr_st;
	}

	enum file_status c_st = close_file(f);
	if (c_st != FILE_CLOSE_OK) {
		return WRITE_ERROR;
	}

	return WRITE_OK;
}
