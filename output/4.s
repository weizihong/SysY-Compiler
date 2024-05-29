.section .rdata
.LC0:
    .string "%d\n"

.section .data

.section .bss
.section .text
.globl exgcd
exgcd:
    pushq   %rbp
    movq    %rsp, %rbp
    subq    $32, %rsp
    movl    %ecx, -4(%rbp)
    movl    %edx, -8(%rbp)
    movq    %r8, -16(%rbp)
    movq    %r9, -24(%rbp)
    movl    -8(%rbp), %eax
    cmpl    $0, %eax
    jne     .L1
.L0:
    movq    -16(%rbp), %rax
    movl    $1, (%rax)
    movq    -24(%rbp), %rax
    movl    $0, (%rax)
    movl    -4(%rbp), %eax
    jmp     .L2
    jmp     .L3
.L1:
    movl    -4(%rbp), %eax
    movl    -8(%rbp), %ebx
    cltd
    idivl   %ebx
    movl    -8(%rbp), %eax
    movl    %eax, %ecx
    movq    -16(%rbp), %rax
    leaq    (%rax), %r8
    movq    -24(%rbp), %rax
    leaq    (%rax), %r9
    call    exgcd
    movl    %eax, -28(%rbp)
    movq    -16(%rbp), %rax
    movl    (%rax), %ebx
    movl    %ebx, -32(%rbp)
    movq    -24(%rbp), %rax
    movl    (%rax), %ebx
    movq    -16(%rbp), %rax
    movl    %ebx, (%rax)
    movl    -32(%rbp), %eax
    movl    -4(%rbp), %ebx
    movl    -8(%rbp), %ecx
    movl    %eax, %edx
    movl    %ebx, %eax
    movl    %edx, %ebx
    cltd
    idivl   %ecx
    movq    -24(%rbp), %rcx
    movl    (%rcx), %edx
    imull   %edx, %eax
    subl    %eax, %ebx
    movq    -24(%rbp), %rax
    movl    %ebx, (%rax)
    movl    -28(%rbp), %eax
    jmp     .L2
.L3:
.L2:
    leave
    ret
.globl main
main:
    pushq   %rbp
    movq    %rsp, %rbp
    subq    $16, %rsp
    movl    $7, -4(%rbp)
    movl    $15, -8(%rbp)
    movl    $1, -12(%rbp)
    movl    $1, -16(%rbp)
    movl    -8(%rbp), %eax
    movl    -4(%rbp), %ebx
    movl    %ebx, %ecx
    movl    %eax, %edx
    leaq    -12(%rbp), %r8
    leaq    -16(%rbp), %r9
    call    exgcd
    movl    -12(%rbp), %eax
    movl    -8(%rbp), %ebx
    cltd
    idivl   %ebx
    movl    -8(%rbp), %eax
    addl    %eax, %edx
    movl    -8(%rbp), %eax
    movl    %eax, %ebx
    movl    %edx, %eax
    cltd
    idivl   %ebx
    movl    %edx, -12(%rbp)
    movl    -12(%rbp), %eax
    leaq    .LC0(%rip), %rcx
    movl    %eax, %edx
    subq    $32, %rsp
    call    printf
    addq    $32, %rsp
    movl    $0, %eax
    leave
    ret
