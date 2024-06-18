.section .rdata
.LC0:
    .string "%d\n"
.section .data
.section .bss
    .lcomm a, 12
    .lcomm cal, 800
    .lcomm sum, 4
.section .text
.globl next
next:
    pushq   %rbp
    movq    %rsp, %rbp
    subq    $0, %rsp
    movl    a+4(%rip), %eax
    movl    %eax, a(%rip)
    movl    a+8(%rip), %eax
    movl    %eax, a+4(%rip)
    movl    a(%rip), %eax
    movl    a+4(%rip), %ebx
    addl    %ebx, %eax
    cltd
    movl    $10000, %ebx
    idivl   %ebx
    movl    %edx, a+8(%rip)
    leave
    ret
.globl squrae
squrae:
    pushq   %rbp
    movq    %rsp, %rbp
    subq    $16, %rsp
    movl    a(%rip), %eax
    movl    a+4(%rip), %ebx
    imull   %ebx, %eax
    movl    a+4(%rip), %ebx
    movl    a+8(%rip), %ecx
    imull   %ecx, %ebx
    addl    %ebx, %eax
    cltd
    movl    $10000, %ebx
    idivl   %ebx
    movl    %edx, -4(%rbp)
    movl    a(%rip), %eax
    movl    a(%rip), %ebx
    imull   %ebx, %eax
    movl    a+4(%rip), %ebx
    movl    a+4(%rip), %ecx
    imull   %ecx, %ebx
    addl    %ebx, %eax
    cltd
    movl    $10000, %ebx
    idivl   %ebx
    movl    %edx, a(%rip)
    movl    a+4(%rip), %eax
    movl    a+4(%rip), %ebx
    imull   %ebx, %eax
    movl    a+8(%rip), %ebx
    movl    a+8(%rip), %ecx
    imull   %ecx, %ebx
    addl    %ebx, %eax
    cltd
    movl    $10000, %ebx
    idivl   %ebx
    movl    %edx, a+8(%rip)
    movl    -4(%rbp), %eax
    movl    %eax, a+4(%rip)
    leave
    ret
.globl main
main:
    pushq   %rbp
    movq    %rsp, %rbp
    subq    $32, %rsp
    movl    $1000, -4(%rbp)
    movl    $0, -8(%rbp)
    jmp     .L1
.L0:
    movl    $0, a(%rip)
    movl    $1, a+4(%rip)
    movl    $1, a+8(%rip)
    movl    $0, -12(%rbp)
    jmp     .L4
.L3:
    movl    -12(%rbp), %eax
    leaq    cal(%rip), %rbx
    movl    $0, (%rbx, %rax, 4)
    movl    -12(%rbp), %eax
    addl    $1, %eax
    movl    %eax, -12(%rbp)
.L4:
    movl    -12(%rbp), %eax
    cmpl    $200, %eax
    jl      .L3
.L5:
    movl    -8(%rbp), %eax
    movl    %eax, -16(%rbp)
    movl    $0, -20(%rbp)
    jmp     .L7
.L6:
    movl    -16(%rbp), %eax
    cltd
    movl    $2, %ebx
    idivl   %ebx
    cmpl    $0, %edx
    je     .L10
.L9:
    movl    -20(%rbp), %eax
    leaq    cal(%rip), %rbx
    movl    $0, (%rbx, %rax, 4)
    movl    -16(%rbp), %eax
    subl    $1, %eax
    movl    %eax, -16(%rbp)
    jmp     .L11
.L10:
    movl    -20(%rbp), %eax
    leaq    cal(%rip), %rbx
    movl    $1, (%rbx, %rax, 4)
    movl    -16(%rbp), %eax
    cltd
    movl    $2, %ebx
    idivl   %ebx
    movl    %eax, -16(%rbp)
.L11:
    movl    -20(%rbp), %eax
    addl    $1, %eax
    movl    %eax, -20(%rbp)
.L7:
    movl    -16(%rbp), %eax
    cmpl    $1, %eax
    jg      .L6
.L8:
    movl    -20(%rbp), %eax
    subl    $1, %eax
    movl    %eax, -12(%rbp)
    jmp     .L13
.L12:
    movl    -12(%rbp), %eax
    leaq    cal(%rip), %rbx
    movl    (%rbx, %rax, 4), %ecx
    cmpl    $0, %ecx
    jne      .L16
.L15:
    call    next
    jmp     .L17
.L16:
    call    squrae
.L17:
    movl    -12(%rbp), %eax
    subl    $1, %eax
    movl    %eax, -12(%rbp)
.L13:
    movl    -12(%rbp), %eax
    cmpl    $0, %eax
    jge     .L12
.L14:
    movl    sum(%rip), %eax
    movl    a+4(%rip), %ebx
    addl    %ebx, %eax
    movl    %eax, sum(%rip)
    movl    sum(%rip), %eax
    cltd
    movl    $10000, %ebx
    idivl   %ebx
    movl    %edx, sum(%rip)
    movl    -8(%rbp), %eax
    addl    $1, %eax
    movl    %eax, -8(%rbp)
.L1:
    movl    -8(%rbp), %eax
    movl    -4(%rbp), %ebx
    cmpl    %ebx, %eax
    jl      .L0
.L2:
    movl    sum(%rip), %eax
    leaq    .LC0(%rip), %rcx
    movl    %eax, %edx
    subq    $32, %rsp
    call    printf
    addq    $32, %rsp
    movl    $0, %eax
    leave
    ret
