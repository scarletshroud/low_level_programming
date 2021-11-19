#include "bmp_header.h"

bool validate_bmp_header(const struct bmp_header header) {
	return (
		header.bfType == BF_TYPE
		&& header.bfReserved == BF_RESERVED
		&& header.biSize == BI_SIZE
		&& header.biPlanes == BI_PLANES
		&& header.biBitCount == BI_BIT_COUNT
		&& header.biCompression == BI_COMPRESSION
		&& header.biClrUsed == BI_CLR_USED
		&& header.biClrImportant == BI_CLR_IMPORTANT
		);
}

struct bmp_header create_bmp_header(const struct image image) {
	return (struct bmp_header) {
		.bfType = BF_TYPE,
			.bfileSize = sizeof(struct bmp_header) + image.height * padding(image.width),
			.bfReserved = BF_RESERVED,
			.bOffBits = sizeof(struct bmp_header),
			.biSize = BI_SIZE,
			.biWidth = image.width,
			.biHeight = image.height,
			.biPlanes = BI_PLANES,
			.biBitCount = BI_BIT_COUNT,
			.biCompression = BI_COMPRESSION,
			.biSizeImage = image.height * (image.width + padding(image.width)),
			.biXPelsPerMeter = BI_X_PELS_PER_METER,
			.biYPelsPerMeter = BI_Y_PELS_PER_METER,
			.biClrUsed = BI_CLR_USED,
			.biClrImportant = BI_CLR_IMPORTANT
	};
}