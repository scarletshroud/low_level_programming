#include <stdio.h>

#include "image.h"
#include "errors.h"
#include "bmp_file.h"
#include "image_rotator.h"


void print_message(char* msg) {
	printf("%s\n", msg);
}

int main(int argc, char** argv) {

	if (argc != 3) {
		err("Inccorrect amount of arguments. Must be: bmp_rotator <SOURCE> <NEW>"); 
	} 

	struct image image = { 0 };

	enum read_status r_st = read_file(argv[1], &image);
	if (r_st != READ_OK) {
		err(get_read_status_message(r_st));
	}

	struct image rotated_image = rotate_image(image);

	enum write_status wr_st = write_file(argv[2], &rotated_image);
	if (wr_st != WRITE_OK) {
		err(get_write_status_message(wr_st));
	}

	print_message("Work has done successfully.");

	destroy_image(&image);
	destroy_image(&rotated_image);

	return 0; 
}