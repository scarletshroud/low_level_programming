extern string_equals

global find_word

section .text

find_word:
.loop:
    push rsi 
    call string_equals
    test rax, rax
    jz .loop
.word_found:
    pop rsi
    mov rax, rsi
    jmp .end 
.word_not_found: 
    
.end: 
    ret  
