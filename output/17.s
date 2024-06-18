.section .rdata
.LC0:
    .string "%d"
.LC1:
    .string "%d\n"
N:
    .long 1024
.section .data
.section .bss
    .lcomm A, 4194304
    .lcomm B, 4194304
    .lcomm C, 4194304
.section .text
.globl mm
mm:
    pushq   %rbp
    movq    %rsp, %rbp
    subq    $48, %rsp
    movl    %ecx, -4(%rbp)
    movq    %rdx, -16(%rbp)
    movq    %r8, -24(%rbp)
    movq    %r9, -32(%rbp)
    movl    $0, -36(%rbp)
    movl    $0, -40(%rbp)
    jmp     .L1
.L0:
    movl    $0, -40(%rbp)
    jmp     .L4
.L3:
    movl    -36(%rbp), %eax
    imull   $1024, %eax
    movl    -40(%rbp), %ebx
    addl    %ebx, %eax
    movq    -32(%rbp), %rbx
    movl    $0, (%rbx, %rax, 4)
    movl    -40(%rbp), %eax
    addl    $1, %eax
    movl    %eax, -40(%rbp)
.L4:
    movl    -40(%rbp), %eax
    movl    -4(%rbp), %ebx
    cmpl    %ebx, %eax
    jl      .L3
.L5:
    movl    -36(%rbp), %eax
    addl    $1, %eax
    movl    %eax, -36(%rbp)
.L1:
    movl    -36(%rbp), %eax
    movl    -4(%rbp), %ebx
    cmpl    %ebx, %eax
    jl      .L0
.L2:
    movl    $0, -36(%rbp)
    movl    $0, -40(%rbp)
    movl    $0, -44(%rbp)
    jmp     .L7
.L6:
    movl    $0, -36(%rbp)
    jmp     .L10
.L9:
    movl    -36(%rbp), %eax
    imull   $1024, %eax
    movl    -44(%rbp), %ebx
    addl    %ebx, %eax
    movq    -16(%rbp), %rbx
    movl    (%rbx, %rax, 4), %ecx
    cmpl    $0, %ecx
    jne     .L13
.L12:
    movl    -36(%rbp), %eax
    addl    $1, %eax
    movl    %eax, -36(%rbp)
    jmp     .L10
.L13:
    movl    $0, -40(%rbp)
    jmp     .L15
.L14:
    movl    -36(%rbp), %eax
    imull   $1024, %eax
    movl    -40(%rbp), %ebx
    addl    %ebx, %eax
    movl    -36(%rbp), %ebx
    imull   $1024, %ebx
    movl    -40(%rbp), %ecx
    addl    %ecx, %ebx
    movq    -32(%rbp), %rcx
    movl    (%rcx, %rbx, 4), %edx
    movl    -36(%rbp), %ebx
    imull   $1024, %ebx
    movl    -44(%rbp), %ecx
    addl    %ecx, %ebx
    movq    -16(%rbp), %rcx
    movl    (%rcx, %rbx, 4), %esi
    movl    -44(%rbp), %ebx
    imull   $1024, %ebx
    movl    -40(%rbp), %ecx
    addl    %ecx, %ebx
    movq    -24(%rbp), %rcx
    movl    (%rcx, %rbx, 4), %edi
    imull   %edi, %esi
    addl    %esi, %edx
    movq    -32(%rbp), %rbx
    movl    %edx, (%rbx, %rax, 4)
    movl    -40(%rbp), %eax
    addl    $1, %eax
    movl    %eax, -40(%rbp)
.L15:
    movl    -40(%rbp), %eax
    movl    -4(%rbp), %ebx
    cmpl    %ebx, %eax
    jl      .L14
.L16:
    movl    -36(%rbp), %eax
    addl    $1, %eax
    movl    %eax, -36(%rbp)
.L10:
    movl    -36(%rbp), %eax
    movl    -4(%rbp), %ebx
    cmpl    %ebx, %eax
    jl      .L9
.L11:
    movl    -44(%rbp), %eax
    addl    $1, %eax
    movl    %eax, -44(%rbp)
.L7:
    movl    -44(%rbp), %eax
    movl    -4(%rbp), %ebx
    cmpl    %ebx, %eax
    jl      .L6
.L8:
    leave
    ret
.globl getint
getint:
    pushq   %rbp
    movq    %rsp, %rbp
    subq    $16, %rsp
    leaq    .LC0(%rip), %rcx
    leaq    -4(%rbp), %rdx
    subq    $32, %rsp
    call    scanf
    addq    $32, %rsp
    movl    -4(%rbp), %eax
    leave
    ret
.globl main
main:
    pushq   %rbp
    movq    %rsp, %rbp
    subq    $16, %rsp
    call    getint
    movl    %eax, -4(%rbp)
    movl    $0, -8(%rbp)
    movl    $0, -12(%rbp)
    jmp     .L18
.L17:
    movl    $0, -12(%rbp)
    jmp     .L21
.L20:
    movl    -8(%rbp), %eax
    imull   $1024, %eax
    movl    -12(%rbp), %ebx
    addl    %ebx, %eax
    movl    %eax, %ebx
    push    %rbx
    call    getint
    pop     %rbx
    leaq    A(%rip), %rcx
    movl    %eax, (%rcx, %rbx, 4)
    movl    -12(%rbp), %eax
    addl    $1, %eax
    movl    %eax, -12(%rbp)
.L21:
    movl    -12(%rbp), %eax
    movl    -4(%rbp), %ebx
    cmpl    %ebx, %eax
    jl      .L20
.L22:
    movl    -8(%rbp), %eax
    addl    $1, %eax
    movl    %eax, -8(%rbp)
.L18:
    movl    -8(%rbp), %eax
    movl    -4(%rbp), %ebx
    cmpl    %ebx, %eax
    jl      .L17
.L19:
    movl    $0, -8(%rbp)
    movl    $0, -12(%rbp)
    jmp     .L24
.L23:
    movl    $0, -12(%rbp)
    jmp     .L27
.L26:
    movl    -8(%rbp), %eax
    imull   $1024, %eax
    movl    -12(%rbp), %ebx
    addl    %ebx, %eax
    movl    %eax, %ebx
    push    %rbx
    call    getint
    pop     %rbx
    leaq    B(%rip), %rcx
    movl    %eax, (%rcx, %rbx, 4)
    movl    -12(%rbp), %eax
    addl    $1, %eax
    movl    %eax, -12(%rbp)
.L27:
    movl    -12(%rbp), %eax
    movl    -4(%rbp), %ebx
    cmpl    %ebx, %eax
    jl      .L26
.L28:
    movl    -8(%rbp), %eax
    addl    $1, %eax
    movl    %eax, -8(%rbp)
.L24:
    movl    -8(%rbp), %eax
    movl    -4(%rbp), %ebx
    cmpl    %ebx, %eax
    jl      .L23
.L25:
    movl    $0, -8(%rbp)
    jmp     .L30
.L29:
    movl    -4(%rbp), %eax
    movl    %eax, %ecx
    leaq    A(%rip), %rdx
    leaq    B(%rip), %r8
    leaq    C(%rip), %r9
    call    mm
    movl    -4(%rbp), %eax
    movl    %eax, %ecx
    leaq    A(%rip), %rdx
    leaq    C(%rip), %r8
    leaq    B(%rip), %r9
    call    mm
    movl    -8(%rbp), %eax
    addl    $1, %eax
    movl    %eax, -8(%rbp)
.L30:
    movl    -8(%rbp), %eax
    cmpl    $5, %eax
    jl      .L29
.L31:
    movl    $0, -16(%rbp)
    movl    $0, -8(%rbp)
    jmp     .L33
.L32:
    movl    $0, -12(%rbp)
    jmp     .L36
.L35:
    movl    -16(%rbp), %eax
    movl    -8(%rbp), %ebx
    imull   $1024, %ebx
    movl    -12(%rbp), %ecx
    addl    %ecx, %ebx
    leaq    B(%rip), %rcx
    movl    (%rcx, %rbx, 4), %edx
    addl    %edx, %eax
    movl    %eax, -16(%rbp)
    movl    -12(%rbp), %eax
    addl    $1, %eax
    movl    %eax, -12(%rbp)
.L36:
    movl    -12(%rbp), %eax
    movl    -4(%rbp), %ebx
    cmpl    %ebx, %eax
    jl      .L35
.L37:
    movl    -8(%rbp), %eax
    addl    $1, %eax
    movl    %eax, -8(%rbp)
.L33:
    movl    -8(%rbp), %eax
    movl    -4(%rbp), %ebx
    cmpl    %ebx, %eax
    jl      .L32
.L34:
    movl    -16(%rbp), %eax
    leaq    .LC1(%rip), %rcx
    movl    %eax, %edx
    subq    $32, %rsp
    call    printf
    addq    $32, %rsp
    movl    $0, %eax
    leave
    ret
