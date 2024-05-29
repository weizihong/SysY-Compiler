.section .rdata
.LC0:
    .string "a<b\n"
.LC1:
    .string "a>=b\n"
.section .data
.section .bss
.section .text
.globl main
main:
    pushq   %rbp
    movq    %rsp, %rbp
    subq    $16, %rsp
    movl    $1, -4(%rbp)
    movl    $3, -8(%rbp)
    movl    -4(%rbp), %eax
    movl    -8(%rbp), %ebx
    cmpl    %ebx, %eax
    jge     .L3
.L2:
    movl    $1, %eax
    jmp     .L4
.L3:
    movl    $0, %eax
.L4:
    cmpl    $1, %eax
    jne     .L1
.L0:
    leaq    .LC0(%rip), %rcx
    subq    $32, %rsp
    call    printf
    addq    $32, %rsp
    jmp     .L5
.L1:
    leaq    .LC1(%rip), %rcx
    subq    $32, %rsp
    call    printf
    addq    $32, %rsp
.L5:
    movl    $0, %eax
    leave
    ret
