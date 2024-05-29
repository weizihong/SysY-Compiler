.section .rdata
.section .data
.section .text
.globl main
main:
    pushq   %rbp
    movq    %rsp, %rbp
    subq    $0, %rsp
    movl    $3, %eax
    leave
    ret
