main: main.o dict.o lib.o
	ld -o main main.o dict.o lib.o

main.o: main.asm colon.inc words.inc
	nasm -g -felf64  main.asm 

dict.o: dict.asm
	nasm -g -felf64 dict.asm

lib.o: lib.asm
	nasm -g -felf64 lib.asm 
	
clean:
	rm -f *.o
