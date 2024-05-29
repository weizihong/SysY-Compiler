.section .rdata
.LC0:
    .string "%d\n"

.section .data

a:

a0:
    .long 0, 0, 0

b:
    .long 0, 0, 0, 0, 0, 0, 0, 0
    .long 0, 0, 0, 0, 0, 0, 0

b0:
    .long 0, 1, 0, 0

c:
    .long 1, 2, 3, 4, 5, 6, 7, 8
    .long 9, 10, 11, 12, 13, 14, 15

c0:
    .long 2, 8, 6, 3, 9, 1, 5

d:
    .long 1, 2, 3, 4, 5, 6, 7, 8
    .long 9, 10, 11, 12, 13, 14, 15

d0:

e:
    .long 1, 2, 3, 4, 5, 6, 7, 8
    .long 9, 10, 11, 12, 13, 14, 15

e0:
    .long 22, 33

f:

f0:

g:
    .long 1, 2, 3, 4, 0, 0, 7, 0
    .long 0, 10, 11, 12, 0, 0, 0

g0:
    .long 85, 0, 1, 29, 0, 0, 0, 0
    .long 0

h:

i:
    .long 1, 2, 3, 4, 5, 0, 0, 0
    .long 0, 0, 0, 0, 0, 0, 0, 0
    .long 0, 0, 0, 0, 0, 0, 0, 0

scj82c9s0j:
    .long 9

.section .bss
.section .text
.globl main
main:
    pushq   %rbp
    movq    %rsp, %rbp
    subq    $0, %rsp
    movl    c0+8(%rip), %eax
    movl    g0+12(%rip), %ebx
    addl    %ebx, %eax
    movl    scj82c9s0j(%rip), %ebx
    addl    %ebx, %eax
    leaq    .LC0(%rip), %rcx
    movl    %eax, %edx
    subq    $32, %rsp
    call    printf
    addq    $32, %rsp
    movl    $5, %eax
    leave
    ret
