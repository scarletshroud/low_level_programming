CFLAGS=--std=c18 -Wall -pedantic -Isrc/ -ggdb -Wextra -Werror -DDEBUG
CC=gcc

all: bmp_rotator

main.o: main.c
		$(CC) -c $(CFLAGS) $< -o $@

bmp_file.o: bmp_file.c
		$(CC) -c $(CFLAGS) $< -o $@

errors.o: errors.c
		$(CC) -c $(CFLAGS) $< -o $@

image.o: image.c
		$(CC) -c $(CFLAGS) $< -o $@

bmp_rotator: main.o bmp_file.o errors.o image.o
		$(CC) -o bmp_rotator $^

clean:
		rm -f main.o image.o errors.o bmp_rotator.o bmp_rotator
