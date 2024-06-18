.section .rdata
.LC0:
    .string "%d"
.LC1:
    .string "%d\n"
.section .data
.section .bss
.section .text
.globl sort
sort:
    pushq   %rbp
    movq    %rsp, %rbp
    subq    $32, %rsp
    movq    %rcx, -8(%rbp)
    movl    %edx, -12(%rbp)
    movl    $0, -16(%rbp)
    jmp     .L1
.L0:
    movl    -16(%rbp), %eax
    addl    $1, %eax
    movl    %eax, -20(%rbp)
    jmp     .L4
.L3:
    movl    -16(%rbp), %eax
    movq    -8(%rbp), %rbx
    movl    (%rbx, %rax, 4), %ecx
    movl    -20(%rbp), %eax
    movq    -8(%rbp), %rbx
    movl    (%rbx, %rax, 4), %edx
    cmpl    %edx, %ecx
    jge     .L7
.L6:
    movl    -16(%rbp), %eax
    movq    -8(%rbp), %rbx
    movl    (%rbx, %rax, 4), %ecx
    movl    %ecx, -24(%rbp)
    movl    -16(%rbp), %eax
    movl    -20(%rbp), %ebx
    movq    -8(%rbp), %rcx
    movl    (%rcx, %rbx, 4), %edx
    movq    -8(%rbp), %rbx
    movl    %edx, (%rbx, %rax, 4)
    movl    -20(%rbp), %eax
    movl    -24(%rbp), %ebx
    movq    -8(%rbp), %rcx
    movl    %ebx, (%rcx, %rax, 4)
.L7:
    movl    -20(%rbp), %eax
    addl    $1, %eax
    movl    %eax, -20(%rbp)
.L4:
    movl    -20(%rbp), %eax
    movl    -12(%rbp), %ebx
    cmpl    %ebx, %eax
    jl      .L3
.L5:
    movl    -16(%rbp), %eax
    addl    $1, %eax
    movl    %eax, -16(%rbp)
.L1:
    movl    -16(%rbp), %eax
    movl    -12(%rbp), %ebx
    subl    $1, %ebx
    cmpl    %ebx, %eax
    jl      .L0
.L2:
    leave
    ret
.globl param32_rec
param32_rec:
    pushq   %rbp
    movq    %rsp, %rbp
    subq    $16, %rsp
    movl    %ecx, -4(%rbp)
    movl    %edx, -8(%rbp)
    movl    %r8d, -12(%rbp)
    movl    %r9d, -16(%rbp)
    movl    -4(%rbp), %eax
    cmpl    $0, %eax
    jne     .L9
.L8:
    movl    -8(%rbp), %eax
    jmp     .L10
    jmp     .L11
.L9:
    push    $0
    movl    232(%rbp), %eax
    push    %rax
    movl    224(%rbp), %eax
    push    %rax
    movl    216(%rbp), %eax
    push    %rax
    movl    208(%rbp), %eax
    push    %rax
    movl    200(%rbp), %eax
    push    %rax
    movl    192(%rbp), %eax
    push    %rax
    movl    184(%rbp), %eax
    push    %rax
    movl    176(%rbp), %eax
    push    %rax
    movl    168(%rbp), %eax
    push    %rax
    movl    160(%rbp), %eax
    push    %rax
    movl    152(%rbp), %eax
    push    %rax
    movl    144(%rbp), %eax
    push    %rax
    movl    136(%rbp), %eax
    push    %rax
    movl    128(%rbp), %eax
    push    %rax
    movl    120(%rbp), %eax
    push    %rax
    movl    112(%rbp), %eax
    push    %rax
    movl    104(%rbp), %eax
    push    %rax
    movl    96(%rbp), %eax
    push    %rax
    movl    88(%rbp), %eax
    push    %rax
    movl    80(%rbp), %eax
    push    %rax
    movl    72(%rbp), %eax
    push    %rax
    movl    64(%rbp), %eax
    push    %rax
    movl    56(%rbp), %eax
    push    %rax
    movl    48(%rbp), %eax
    push    %rax
    movl    40(%rbp), %eax
    push    %rax
    movl    32(%rbp), %eax
    push    %rax
    movl    24(%rbp), %eax
    push    %rax
    movl    16(%rbp), %eax
    movl    -16(%rbp), %ebx
    movl    -8(%rbp), %ecx
    movl    -12(%rbp), %edx
    addl    %edx, %ecx
    movl    %eax, %edx
    movl    %ecx, %eax
    movl    %edx, %ecx
    cltd
    movl    $998244353, %esi
    idivl   %esi
    movl    -4(%rbp), %eax
    subl    $1, %eax
    movl    %ecx, %esi
    movl    %eax, %ecx
    movl    %ebx, %r8d
    movl    %esi, %r9d
    call    param32_rec
    addq    $224, %rsp
    jmp     .L10
.L11:
.L10:
    leave
    ret
.globl param32_arr
param32_arr:
    pushq   %rbp
    movq    %rsp, %rbp
    subq    $48, %rsp
    movq    %rcx, -8(%rbp)
    movq    %rdx, -16(%rbp)
    movq    %r8, -24(%rbp)
    movq    %r9, -32(%rbp)
    movq    -8(%rbp), %rax
    movl    (%rax), %ebx
    movq    -8(%rbp), %rax
    movl    4(%rax), %ecx
    addl    %ecx, %ebx
    movl    %ebx, -36(%rbp)
    movl    -36(%rbp), %eax
    movq    -16(%rbp), %rbx
    movl    (%rbx), %ecx
    addl    %ecx, %eax
    movq    -16(%rbp), %rbx
    movl    4(%rbx), %ecx
    addl    %ecx, %eax
    movl    %eax, -36(%rbp)
    movl    -36(%rbp), %eax
    movq    -24(%rbp), %rbx
    movl    (%rbx), %ecx
    addl    %ecx, %eax
    movq    -24(%rbp), %rbx
    movl    4(%rbx), %ecx
    addl    %ecx, %eax
    movl    %eax, -36(%rbp)
    movl    -36(%rbp), %eax
    movq    -32(%rbp), %rbx
    movl    (%rbx), %ecx
    addl    %ecx, %eax
    movq    -32(%rbp), %rbx
    movl    4(%rbx), %ecx
    addl    %ecx, %eax
    movl    %eax, -36(%rbp)
    movl    -36(%rbp), %eax
    movq    16(%rbp), %rbx
    movl    (%rbx), %ecx
    addl    %ecx, %eax
    movq    16(%rbp), %rbx
    movl    4(%rbx), %ecx
    addl    %ecx, %eax
    movl    %eax, -36(%rbp)
    movl    -36(%rbp), %eax
    movq    24(%rbp), %rbx
    movl    (%rbx), %ecx
    addl    %ecx, %eax
    movq    24(%rbp), %rbx
    movl    4(%rbx), %ecx
    addl    %ecx, %eax
    movl    %eax, -36(%rbp)
    movl    -36(%rbp), %eax
    movq    32(%rbp), %rbx
    movl    (%rbx), %ecx
    addl    %ecx, %eax
    movq    32(%rbp), %rbx
    movl    4(%rbx), %ecx
    addl    %ecx, %eax
    movl    %eax, -36(%rbp)
    movl    -36(%rbp), %eax
    movq    40(%rbp), %rbx
    movl    (%rbx), %ecx
    addl    %ecx, %eax
    movq    40(%rbp), %rbx
    movl    4(%rbx), %ecx
    addl    %ecx, %eax
    movl    %eax, -36(%rbp)
    movl    -36(%rbp), %eax
    movq    48(%rbp), %rbx
    movl    (%rbx), %ecx
    addl    %ecx, %eax
    movq    48(%rbp), %rbx
    movl    4(%rbx), %ecx
    addl    %ecx, %eax
    movl    %eax, -36(%rbp)
    movl    -36(%rbp), %eax
    movq    56(%rbp), %rbx
    movl    (%rbx), %ecx
    addl    %ecx, %eax
    movq    56(%rbp), %rbx
    movl    4(%rbx), %ecx
    addl    %ecx, %eax
    movl    %eax, -36(%rbp)
    movl    -36(%rbp), %eax
    movq    64(%rbp), %rbx
    movl    (%rbx), %ecx
    addl    %ecx, %eax
    movq    64(%rbp), %rbx
    movl    4(%rbx), %ecx
    addl    %ecx, %eax
    movl    %eax, -36(%rbp)
    movl    -36(%rbp), %eax
    movq    72(%rbp), %rbx
    movl    (%rbx), %ecx
    addl    %ecx, %eax
    movq    72(%rbp), %rbx
    movl    4(%rbx), %ecx
    addl    %ecx, %eax
    movl    %eax, -36(%rbp)
    movl    -36(%rbp), %eax
    movq    80(%rbp), %rbx
    movl    (%rbx), %ecx
    addl    %ecx, %eax
    movq    80(%rbp), %rbx
    movl    4(%rbx), %ecx
    addl    %ecx, %eax
    movl    %eax, -36(%rbp)
    movl    -36(%rbp), %eax
    movq    88(%rbp), %rbx
    movl    (%rbx), %ecx
    addl    %ecx, %eax
    movq    88(%rbp), %rbx
    movl    4(%rbx), %ecx
    addl    %ecx, %eax
    movl    %eax, -36(%rbp)
    movl    -36(%rbp), %eax
    movq    96(%rbp), %rbx
    movl    (%rbx), %ecx
    addl    %ecx, %eax
    movq    96(%rbp), %rbx
    movl    4(%rbx), %ecx
    addl    %ecx, %eax
    movl    %eax, -36(%rbp)
    movl    -36(%rbp), %eax
    movq    104(%rbp), %rbx
    movl    (%rbx), %ecx
    addl    %ecx, %eax
    movq    104(%rbp), %rbx
    movl    4(%rbx), %ecx
    addl    %ecx, %eax
    movl    %eax, -36(%rbp)
    movl    -36(%rbp), %eax
    movq    112(%rbp), %rbx
    movl    (%rbx), %ecx
    addl    %ecx, %eax
    movq    112(%rbp), %rbx
    movl    4(%rbx), %ecx
    addl    %ecx, %eax
    movl    %eax, -36(%rbp)
    movl    -36(%rbp), %eax
    movq    120(%rbp), %rbx
    movl    (%rbx), %ecx
    addl    %ecx, %eax
    movq    120(%rbp), %rbx
    movl    4(%rbx), %ecx
    addl    %ecx, %eax
    movl    %eax, -36(%rbp)
    movl    -36(%rbp), %eax
    movq    128(%rbp), %rbx
    movl    (%rbx), %ecx
    addl    %ecx, %eax
    movq    128(%rbp), %rbx
    movl    4(%rbx), %ecx
    addl    %ecx, %eax
    movl    %eax, -36(%rbp)
    movl    -36(%rbp), %eax
    movq    136(%rbp), %rbx
    movl    (%rbx), %ecx
    addl    %ecx, %eax
    movq    136(%rbp), %rbx
    movl    4(%rbx), %ecx
    addl    %ecx, %eax
    movl    %eax, -36(%rbp)
    movl    -36(%rbp), %eax
    movq    144(%rbp), %rbx
    movl    (%rbx), %ecx
    addl    %ecx, %eax
    movq    144(%rbp), %rbx
    movl    4(%rbx), %ecx
    addl    %ecx, %eax
    movl    %eax, -36(%rbp)
    movl    -36(%rbp), %eax
    movq    152(%rbp), %rbx
    movl    (%rbx), %ecx
    addl    %ecx, %eax
    movq    152(%rbp), %rbx
    movl    4(%rbx), %ecx
    addl    %ecx, %eax
    movl    %eax, -36(%rbp)
    movl    -36(%rbp), %eax
    movq    160(%rbp), %rbx
    movl    (%rbx), %ecx
    addl    %ecx, %eax
    movq    160(%rbp), %rbx
    movl    4(%rbx), %ecx
    addl    %ecx, %eax
    movl    %eax, -36(%rbp)
    movl    -36(%rbp), %eax
    movq    168(%rbp), %rbx
    movl    (%rbx), %ecx
    addl    %ecx, %eax
    movq    168(%rbp), %rbx
    movl    4(%rbx), %ecx
    addl    %ecx, %eax
    movl    %eax, -36(%rbp)
    movl    -36(%rbp), %eax
    movq    176(%rbp), %rbx
    movl    (%rbx), %ecx
    addl    %ecx, %eax
    movq    176(%rbp), %rbx
    movl    4(%rbx), %ecx
    addl    %ecx, %eax
    movl    %eax, -36(%rbp)
    movl    -36(%rbp), %eax
    movq    184(%rbp), %rbx
    movl    (%rbx), %ecx
    addl    %ecx, %eax
    movq    184(%rbp), %rbx
    movl    4(%rbx), %ecx
    addl    %ecx, %eax
    movl    %eax, -36(%rbp)
    movl    -36(%rbp), %eax
    movq    192(%rbp), %rbx
    movl    (%rbx), %ecx
    addl    %ecx, %eax
    movq    192(%rbp), %rbx
    movl    4(%rbx), %ecx
    addl    %ecx, %eax
    movl    %eax, -36(%rbp)
    movl    -36(%rbp), %eax
    movq    200(%rbp), %rbx
    movl    (%rbx), %ecx
    addl    %ecx, %eax
    movq    200(%rbp), %rbx
    movl    4(%rbx), %ecx
    addl    %ecx, %eax
    movl    %eax, -36(%rbp)
    movl    -36(%rbp), %eax
    movq    208(%rbp), %rbx
    movl    (%rbx), %ecx
    addl    %ecx, %eax
    movq    208(%rbp), %rbx
    movl    4(%rbx), %ecx
    addl    %ecx, %eax
    movl    %eax, -36(%rbp)
    movl    -36(%rbp), %eax
    movq    216(%rbp), %rbx
    movl    (%rbx), %ecx
    addl    %ecx, %eax
    movq    216(%rbp), %rbx
    movl    4(%rbx), %ecx
    addl    %ecx, %eax
    movl    %eax, -36(%rbp)
    movl    -36(%rbp), %eax
    movq    224(%rbp), %rbx
    movl    (%rbx), %ecx
    addl    %ecx, %eax
    movq    224(%rbp), %rbx
    movl    4(%rbx), %ecx
    addl    %ecx, %eax
    movl    %eax, -36(%rbp)
    movl    -36(%rbp), %eax
    movq    232(%rbp), %rbx
    movl    (%rbx), %ecx
    addl    %ecx, %eax
    movq    232(%rbp), %rbx
    movl    4(%rbx), %ecx
    addl    %ecx, %eax
    movl    %eax, -36(%rbp)
    movl    -36(%rbp), %eax
    leave
    ret
.globl param16
param16:
    pushq   %rbp
    movq    %rsp, %rbp
    subq    $80, %rsp
    movl    %ecx, -4(%rbp)
    movl    %edx, -8(%rbp)
    movl    %r8d, -12(%rbp)
    movl    %r9d, -16(%rbp)
    movl    -4(%rbp), %eax
    movl    %eax, -80(%rbp)
    movl    -8(%rbp), %eax
    movl    %eax, -76(%rbp)
    movl    -12(%rbp), %eax
    movl    %eax, -72(%rbp)
    movl    -16(%rbp), %eax
    movl    %eax, -68(%rbp)
    movl    16(%rbp), %eax
    movl    %eax, -64(%rbp)
    movl    24(%rbp), %eax
    movl    %eax, -60(%rbp)
    movl    32(%rbp), %eax
    movl    %eax, -56(%rbp)
    movl    40(%rbp), %eax
    movl    %eax, -52(%rbp)
    movl    48(%rbp), %eax
    movl    %eax, -48(%rbp)
    movl    56(%rbp), %eax
    movl    %eax, -44(%rbp)
    movl    64(%rbp), %eax
    movl    %eax, -40(%rbp)
    movl    72(%rbp), %eax
    movl    %eax, -36(%rbp)
    movl    80(%rbp), %eax
    movl    %eax, -32(%rbp)
    movl    88(%rbp), %eax
    movl    %eax, -28(%rbp)
    movl    96(%rbp), %eax
    movl    %eax, -24(%rbp)
    movl    104(%rbp), %eax
    movl    %eax, -20(%rbp)
    leaq    -80(%rbp), %rcx
    movl    $16, %edx
    call    sort
    movl    104(%rbp), %eax
    push    %rax
    movl    96(%rbp), %eax
    push    %rax
    movl    88(%rbp), %eax
    push    %rax
    movl    80(%rbp), %eax
    push    %rax
    movl    72(%rbp), %eax
    push    %rax
    movl    64(%rbp), %eax
    push    %rax
    movl    56(%rbp), %eax
    push    %rax
    movl    48(%rbp), %eax
    push    %rax
    movl    40(%rbp), %eax
    push    %rax
    movl    32(%rbp), %eax
    push    %rax
    movl    24(%rbp), %eax
    push    %rax
    movl    16(%rbp), %eax
    push    %rax
    movl    -16(%rbp), %eax
    push    %rax
    movl    -12(%rbp), %eax
    push    %rax
    movl    -8(%rbp), %eax
    push    %rax
    movl    -4(%rbp), %eax
    push    %rax
    movl    -20(%rbp), %eax
    push    %rax
    movl    -24(%rbp), %eax
    push    %rax
    movl    -28(%rbp), %eax
    push    %rax
    movl    -32(%rbp), %eax
    push    %rax
    movl    -36(%rbp), %eax
    push    %rax
    movl    -40(%rbp), %eax
    push    %rax
    movl    -44(%rbp), %eax
    push    %rax
    movl    -48(%rbp), %eax
    push    %rax
    movl    -52(%rbp), %eax
    push    %rax
    movl    -56(%rbp), %eax
    push    %rax
    movl    -60(%rbp), %eax
    push    %rax
    movl    -64(%rbp), %eax
    push    %rax
    movl    -68(%rbp), %eax
    movl    -72(%rbp), %ebx
    movl    -76(%rbp), %ecx
    movl    -80(%rbp), %edx
    movl    %ecx, %esi
    movl    %edx, %ecx
    movl    %esi, %edx
    movl    %ebx, %r8d
    movl    %eax, %r9d
    call    param32_rec
    addq    $224, %rsp
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
    subq    $272, %rsp
    call    getint
    push    %rax
    call    getint
    push    %rax
    call    getint
    push    %rax
    call    getint
    push    %rax
    call    getint
    push    %rax
    call    getint
    push    %rax
    call    getint
    push    %rax
    call    getint
    push    %rax
    call    getint
    push    %rax
    call    getint
    push    %rax
    call    getint
    push    %rax
    call    getint
    push    %rax
    call    getint
    movl    %eax, %ebx
    push    %rbx
    call    getint
    pop     %rbx
    movl    %eax, %ecx
    push    %rbx
    push    %rcx
    call    getint
    pop     %rbx
    pop     %rcx
    movl    %eax, %edx
    push    %rbx
    push    %rcx
    push    %rdx
    call    getint
    pop     %rbx
    pop     %rcx
    pop     %rdx
    movl    %ecx, %esi
    movl    %eax, %ecx
    movl    %esi, %r8d
    movl    %ebx, %r9d
    call    param16
    addq    $96, %rsp
    movl    %eax, -256(%rbp)
    movl    $8848, -252(%rbp)
    movl    $0, %eax
    movl    $62, %ecx
    leaq    -248(%rbp), %rdi
    rep stosl
    movl    $1, -260(%rbp)
    jmp     .L13
.L12:
    movl    -260(%rbp), %eax
    imull   $2, %eax
    addl    $0, %eax
    movl    -260(%rbp), %ebx
    subl    $1, %ebx
    imull   $2, %ebx
    addl    $1, %ebx
    movl    -256(%rbp, %rbx, 4), %ecx
    subl    $1, %ecx
    movl    %ecx, -256(%rbp, %rax, 4)
    movl    -260(%rbp), %eax
    imull   $2, %eax
    addl    $1, %eax
    movl    -260(%rbp), %ebx
    subl    $1, %ebx
    imull   $2, %ebx
    addl    $0, %ebx
    movl    -256(%rbp, %rbx, 4), %ecx
    subl    $2, %ecx
    movl    %ecx, -256(%rbp, %rax, 4)
    movl    -260(%rbp), %eax
    addl    $1, %eax
    movl    %eax, -260(%rbp)
.L13:
    movl    -260(%rbp), %eax
    cmpl    $32, %eax
    jl      .L12
.L14:
    leaq    -8(%rbp), %rax
    pushq   %rax
    leaq    -16(%rbp), %rax
    pushq   %rax
    leaq    -24(%rbp), %rax
    pushq   %rax
    leaq    -32(%rbp), %rax
    pushq   %rax
    leaq    -40(%rbp), %rax
    pushq   %rax
    leaq    -48(%rbp), %rax
    pushq   %rax
    leaq    -56(%rbp), %rax
    pushq   %rax
    leaq    -64(%rbp), %rax
    pushq   %rax
    leaq    -72(%rbp), %rax
    pushq   %rax
    leaq    -80(%rbp), %rax
    pushq   %rax
    leaq    -88(%rbp), %rax
    pushq   %rax
    leaq    -96(%rbp), %rax
    pushq   %rax
    leaq    -104(%rbp), %rax
    pushq   %rax
    leaq    -112(%rbp), %rax
    pushq   %rax
    leaq    -120(%rbp), %rax
    pushq   %rax
    leaq    -128(%rbp), %rax
    pushq   %rax
    leaq    -136(%rbp), %rax
    pushq   %rax
    leaq    -144(%rbp), %rax
    pushq   %rax
    leaq    -152(%rbp), %rax
    pushq   %rax
    leaq    -160(%rbp), %rax
    pushq   %rax
    leaq    -168(%rbp), %rax
    pushq   %rax
    leaq    -176(%rbp), %rax
    pushq   %rax
    leaq    -184(%rbp), %rax
    pushq   %rax
    leaq    -192(%rbp), %rax
    pushq   %rax
    leaq    -200(%rbp), %rax
    pushq   %rax
    leaq    -208(%rbp), %rax
    pushq   %rax
    leaq    -216(%rbp), %rax
    pushq   %rax
    leaq    -224(%rbp), %rax
    pushq   %rax
    leaq    -256(%rbp), %rcx
    leaq    -248(%rbp), %rdx
    leaq    -240(%rbp), %r8
    leaq    -232(%rbp), %r9
    call    param32_arr
    addq    $224, %rsp
    leaq    .LC1(%rip), %rcx
    movl    %eax, %edx
    subq    $32, %rsp
    call    printf
    addq    $32, %rsp
    movl    $0, %eax
    leave
    ret
