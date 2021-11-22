section .data
%include "words.inc"
b_size: equ 255
buffer: times b_size db 0
buffer_overflow_err: 'There is not enough buffer size for the passed string.', 0
word_not_found_err: 'Word not found.', 0
section .text
%include "lib.inc"
%include "dict.asm"

extern read_word
extern print_err
extern print_string
extern string_length
extern find_word
extern exit

global start
_start:
    xor rax, rax
    mov rdi, buffer 
    mov rsi, b_size    
    call read_word
    test rax, rax
    jz .buffer_overflow
    mov rdi, buffer
    mov rsi, ;start dict
    call find_word
    test rax, rax
    jz .word_not_found  
    mov rdi, rax
    call print_string
    jmp .exit
.word_not_found:
    mov rdi, word_not_found_err 
    call print_err
    jmp .exit 
.buffer_overflow:
    mov rdi, buffer_overflow_err
    call print_err
.exit:
    mov rdi, 0 
    call exit 

    
