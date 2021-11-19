#ifndef _ERRORS_H_
#define _ERRORS_H_

#include "bmp_file.h"

const char* get_read_status_message(enum read_status r_st);
const char* get_write_status_message(enum write_status w_st);

void err(const char* msg, ...);

#endif
