.section .rdata
.LC0:
    .string "Total solutions: %d\n"
.section .data
count:
    .long 0
.section .bss
    .lcomm board, 784
.section .text
.globl isSafe
isSafe:
    pushq   %rbp
    movq    %rsp, %rbp
    subq    $32, %rsp
    movl    %ecx, -4(%rbp)
    movl    %edx, -8(%rbp)
    movl    %r8d, -12(%rbp)
    movl    $0, -16(%rbp)
    movl    $0, -20(%rbp)
    jmp     .L1
.L0:
    movl    -4(%rbp), %eax
    imull   $14, %eax
    movl    -16(%rbp), %ebx
    addl    %ebx, %eax
    leaq    board(%rip), %rbx
    movl    (%rbx, %rax, 4), %ecx
    cmpl    $0, %ecx
    je     .L4
.L3:
    movl    $0, %eax
    jmp     .L5
.L4:
    movl    -16(%rbp), %eax
    addl    $1, %eax
    movl    %eax, -16(%rbp)
.L1:
    movl    -16(%rbp), %eax
    movl    -8(%rbp), %ebx
    cmpl    %ebx, %eax
    jl      .L0
.L2:
    movl    -4(%rbp), %eax
    movl    %eax, -16(%rbp)
    movl    -8(%rbp), %eax
    movl    %eax, -20(%rbp)
    jmp     .L7
.L6:
    movl    -16(%rbp), %eax
    imull   $14, %eax
    movl    -20(%rbp), %ebx
    addl    %ebx, %eax
    leaq    board(%rip), %rbx
    movl    (%rbx, %rax, 4), %ecx
    cmpl    $0, %ecx
    je     .L10
.L9:
    movl    $0, %eax
    jmp     .L5
.L10:
    movl    -16(%rbp), %eax
    subl    $1, %eax
    movl    %eax, -16(%rbp)
    movl    -20(%rbp), %eax
    subl    $1, %eax
    movl    %eax, -20(%rbp)
.L7:
    movl    -16(%rbp), %eax
    cmpl    $0, %eax
    jl      .L8
.L11:
    movl    -20(%rbp), %eax
    cmpl    $0, %eax
    jge     .L6
.L8:
    movl    -4(%rbp), %eax
    movl    %eax, -16(%rbp)
    movl    -8(%rbp), %eax
    movl    %eax, -20(%rbp)
    jmp     .L13
.L12:
    movl    -16(%rbp), %eax
    imull   $14, %eax
    movl    -20(%rbp), %ebx
    addl    %ebx, %eax
    leaq    board(%rip), %rbx
    movl    (%rbx, %rax, 4), %ecx
    cmpl    $0, %ecx
    je     .L16
.L15:
    movl    $0, %eax
    jmp     .L5
.L16:
    movl    -16(%rbp), %eax
    addl    $1, %eax
    movl    %eax, -16(%rbp)
    movl    -20(%rbp), %eax
    subl    $1, %eax
    movl    %eax, -20(%rbp)
.L13:
    movl    -20(%rbp), %eax
    cmpl    $0, %eax
    jl      .L14
.L17:
    movl    -16(%rbp), %eax
    movl    -12(%rbp), %ebx
    cmpl    %ebx, %eax
    jl      .L12
.L14:
    movl    $1, %eax
.L5:
    leave
    ret
.globl solveNQUtil
solveNQUtil:
    pushq   %rbp
    movq    %rsp, %rbp
    subq    $16, %rsp
    movl    %ecx, -4(%rbp)
    movl    %edx, -8(%rbp)
    movl    -4(%rbp), %eax
    movl    -8(%rbp), %ebx
    cmpl    %ebx, %eax
    jl      .L19
.L18:
    movl    count(%rip), %eax
    addl    $1, %eax
    movl    %eax, count(%rip)
    jmp     .L20
.L19:
    movl    $0, -12(%rbp)
    jmp     .L22
.L21:
    movl    -8(%rbp), %eax
    movl    -4(%rbp), %ebx
    movl    -12(%rbp), %ecx
    movl    %ebx, %edx
    movl    %eax, %r8d
    call    isSafe
    cmpl    $0, %eax
    je     .L25
.L24:
    movl    -12(%rbp), %eax
    imull   $14, %eax
    movl    -4(%rbp), %ebx
    addl    %ebx, %eax
    leaq    board(%rip), %rbx
    movl    $1, (%rbx, %rax, 4)
    movl    -8(%rbp), %eax
    movl    -4(%rbp), %ebx
    addl    $1, %ebx
    movl    %ebx, %ecx
    movl    %eax, %edx
    call    solveNQUtil
    movl    -12(%rbp), %eax
    imull   $14, %eax
    movl    -4(%rbp), %ebx
    addl    %ebx, %eax
    leaq    board(%rip), %rbx
    movl    $0, (%rbx, %rax, 4)
.L25:
    movl    -12(%rbp), %eax
    addl    $1, %eax
    movl    %eax, -12(%rbp)
.L22:
    movl    -12(%rbp), %eax
    movl    -8(%rbp), %ebx
    cmpl    %ebx, %eax
    jl      .L21
.L23:
.L20:
    leave
    ret
.globl solveNQ
solveNQ:
    pushq   %rbp
    movq    %rsp, %rbp
    subq    $16, %rsp
    movl    %ecx, -4(%rbp)
    movl    $0, -8(%rbp)
    movl    $0, -12(%rbp)
    jmp     .L27
.L26:
    movl    $0, -12(%rbp)
    jmp     .L30
.L29:
    movl    -8(%rbp), %eax
    imull   $14, %eax
    movl    -12(%rbp), %ebx
    addl    %ebx, %eax
    leaq    board(%rip), %rbx
    movl    $0, (%rbx, %rax, 4)
    movl    -12(%rbp), %eax
    addl    $1, %eax
    movl    %eax, -12(%rbp)
.L30:
    movl    -12(%rbp), %eax
    movl    -4(%rbp), %ebx
    cmpl    %ebx, %eax
    jl      .L29
.L31:
    movl    -8(%rbp), %eax
    addl    $1, %eax
    movl    %eax, -8(%rbp)
.L27:
    movl    -8(%rbp), %eax
    movl    -4(%rbp), %ebx
    cmpl    %ebx, %eax
    jl      .L26
.L28:
    movl    -4(%rbp), %eax
    movl    $0, %ecx
    movl    %eax, %edx
    call    solveNQUtil
    movl    count(%rip), %eax
    leaq    .LC0(%rip), %rcx
    movl    %eax, %edx
    subq    $32, %rsp
    call    printf
    addq    $32, %rsp
    leave
    ret
.globl main
main:
    pushq   %rbp
    movq    %rsp, %rbp
    subq    $16, %rsp
    movl    $6, -4(%rbp)
    movl    -4(%rbp), %eax
    movl    %eax, %ecx
    call    solveNQ
    movl    $0, %eax
    leave
    ret
