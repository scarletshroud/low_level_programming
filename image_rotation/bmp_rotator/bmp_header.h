#ifndef _BMP_HEADER_H_
#define _BMP_HEADER_H_

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "image.h"

#define BF_TYPE 0x4D42
#define BF_RESERVED 0
#define BI_SIZE 40
#define BI_PLANES 1
#define BI_BIT_COUNT 24
#define BI_COMPRESSION 0
#define BI_X_PELS_PER_METER 0
#define BI_Y_PELS_PER_METER 0
#define BI_CLR_USED 0
#define BI_CLR_IMPORTANT 0

#pragma pack(push, 1)
struct bmp_header
{
    uint16_t bfType;
    uint32_t  bfileSize;
    uint32_t bfReserved;
    uint32_t bOffBits;
    uint32_t biSize;
    uint32_t biWidth;
    uint32_t  biHeight;
    uint16_t  biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    uint32_t biXPelsPerMeter;
    uint32_t biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t  biClrImportant;
};
#pragma pack(pop)

bool validate_bmp_header(const struct bmp_header header);
struct bmp_header create_bmp_header(const struct image image);

#endif
