%include "colon.inc"

%define offset 8
%define b_size 255

section .data
    %include "words.inc"
    buffer: times b_size db 0
    buffer_overflow_err: db 'There is not enough buffer size for the passed string.', 0
    word_not_found_err: db 'Word not found.', 0

extern find_word
extern read_word
extern print_string 
extern print_err
extern print_newline
extern exit

global _start

section .text

_start:
    xor rax, rax
    mov rdi, buffer 
    mov rsi, b_size 
    push rdi
    push rsi     
    call read_word
    pop rsi
    pop rdi
    test rax, rax
    jz .buffer_overflow
    push rdx
    mov rsi, current_node
    call find_word
    test rax, rax
    jz .word_not_found 
    pop rdx
    add rax, offset
    add rax, rdx
    add rax, 1 
    mov rdi, rax
    call print_string
    call print_newline
    jmp .exit

.word_not_found:
    mov rdi, word_not_found_err 
    call print_err
    call print_newline
    jmp .exit 

.buffer_overflow:
    mov rdi, buffer_overflow_err
    call print_err
    call print_newline

.exit:
    mov rdi, 0 
    call exit 

    
