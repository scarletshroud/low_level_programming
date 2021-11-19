#ifndef _BMP_FILE_H_
#define _BMP_FILE_H_

enum read_status {
    READ_OK = 0,
    READ_INVALID_BITS,
    READ_INVALID_HEADER, 
    READ_ERROR
};

enum file_status {
    FILE_READ_OK = 0,
    FILE_READ_ERROR, 
    FILE_WRITE_OK, 
    FILE_WRITE_ERROR,
    FILE_BAD_PATH, 
    FILE_CLOSE_OK,
    FILE_CLOSE_ERROR
};

enum  write_status {
    WRITE_OK = 0,
    WRITE_ERROR, 
    UNABLE_WRITE_IMAGE, 
    WRITE_INVALID_BITS
};

enum file_status read_file(const char*, struct image*);
enum file_status write_file(const char*, struct image const*);

#endif 