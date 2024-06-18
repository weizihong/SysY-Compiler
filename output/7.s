.section .rdata
.LC0:
    .string "%d %d\n"
.LC1:
    .string "%d\n"
.LC2:
    .string "%d %d\n"
.section .data
a:
    .long -1
b:
    .long 1
.section .bss
.section .text
.globl inc_a
inc_a:
    pushq   %rbp
    movq    %rsp, %rbp
    subq    $16, %rsp
    movl    a(%rip), %eax
    movl    %eax, -4(%rbp)
    movl    -4(%rbp), %eax
    addl    $1, %eax
    movl    %eax, -4(%rbp)
    movl    -4(%rbp), %eax
    movl    %eax, a(%rip)
    movl    a(%rip), %eax
    leave
    ret
.globl main
main:
    pushq   %rbp
    movq    %rsp, %rbp
    subq    $16, %rsp
    movl    $5, -4(%rbp)
    jmp     .L1
.L0:
    call    inc_a
    cmpl    $0, %eax
    je     .L4
.L6:
    call    inc_a
    cmpl    $0, %eax
    je     .L4
.L5:
    call    inc_a
    cmpl    $0, %eax
    je     .L4
.L3:
    movl    b(%rip), %eax
    movl    a(%rip), %ebx
    leaq    .LC0(%rip), %rcx
    movl    %ebx, %edx
    movl    %eax, %r8d
    subq    $32, %rsp
    call    printf
    addq    $32, %rsp
.L4:
    call    inc_a
    cmpl    $14, %eax
    jl      .L7
.L9:
    call    inc_a
    cmpl    $0, %eax
    je     .L8
.L10:
    call    inc_a
    movl    %eax, %ebx
    push    %rbx
    call    inc_a
    pop     %rbx
    subl    %eax, %ebx
    addl    $1, %ebx
    cmpl    $0, %ebx
    je     .L8
.L7:
    movl    a(%rip), %eax
    leaq    .LC1(%rip), %rcx
    movl    %eax, %edx
    subq    $32, %rsp
    call    printf
    addq    $32, %rsp
    movl    b(%rip), %eax
    imull   $2, %eax
    movl    %eax, b(%rip)
    jmp     .L11
.L8:
    call    inc_a
.L11:
    movl    -4(%rbp), %eax
    subl    $1, %eax
    movl    %eax, -4(%rbp)
.L1:
    movl    -4(%rbp), %eax
    cmpl    $0, %eax
    jge     .L0
.L2:
    movl    b(%rip), %eax
    movl    a(%rip), %ebx
    leaq    .LC2(%rip), %rcx
    movl    %ebx, %edx
    movl    %eax, %r8d
    subq    $32, %rsp
    call    printf
    addq    $32, %rsp
    movl    a(%rip), %eax
    leave
    ret
