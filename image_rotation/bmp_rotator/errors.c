#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "errors.h"

static const char* const read_status_messages[] = {
    [READ_OK] = "Reading data from the file successfully completed.",
    [READ_INVALID_BITS] = "An error occured while reading image data.",
    [READ_INVALID_HEADER] = "Read an invalid header. Please, check the file.",
    [READ_ERROR] = "An error occured while reading the data."
};

static const char* const write_status_messages[] = {
    [WRITE_OK] = "Writing the data to the file successfully completed.",
    [WRITE_ERROR] = "An error occured while writing data to the file.",
    [UNABLE_WRITE_IMAGE] = "Unable to write image data to the file.",
    [WRITE_INVALID_BITS] = "An error occure while writing pixels data to the file."
};

const char* get_read_status_message(enum read_status r_st) {
    return write_status_messages[r_st];
}

const char* get_write_status_message(enum write_status w_st) {
    return write_status_messages[w_st];
}

void err(const char* msg, ...) {
	va_list args;
	va_start(args, msg);
	vfprintf(stderr, msg, args);
	va_end(args);
	exit(1);
}