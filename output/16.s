.section .rdata
.LC0:
    .string "%d %d"
.LC1:
    .string "%d"
.LC2:
    .string "%d"
.LC3:
    .string "%d\n"
INF:
    .long 1061109567
inf:
    .long 1000000000
maxn:
    .long 20005
mod:
    .long 998244353
.section .data
.section .bss
    .lcomm a, 80020
    .lcomm dp, 3520880
    .lcomm g, 3520880
    .lcomm k, 4
    .lcomm n, 4
    .lcomm p, 80020
.section .text
.globl pw
pw:
    pushq   %rbp
    movq    %rsp, %rbp
    subq    $16, %rsp
    movl    %ecx, -4(%rbp)
    movl    %edx, -8(%rbp)
    movl    -8(%rbp), %eax
    cmpl    $0, %eax
    jne      .L1
.L0:
    movl    $1, %eax
    jmp     .L2
.L1:
    movl    -8(%rbp), %eax
    cmpl    $1, %eax
    jne     .L4
.L3:
    movl    -4(%rbp), %eax
    cltd
    movl    $998244353, %ebx
    idivl   %ebx
    movl    %edx, %eax
    jmp     .L2
.L4:
    movl    -8(%rbp), %eax
    cltd
    movl    $2, %ebx
    idivl   %ebx
    movl    -4(%rbp), %ebx
    movl    %ebx, %ecx
    movl    %eax, %edx
    call    pw
    movl    %eax, -12(%rbp)
    movl    -8(%rbp), %eax
    cltd
    movl    $2, %ebx
    idivl   %ebx
    cmpl    $1, %edx
    jne     .L6
.L5:
    movl    -12(%rbp), %eax
    movl    -12(%rbp), %ebx
    imull   %ebx, %eax
    cltd
    movl    $998244353, %ebx
    idivl   %ebx
    movl    -4(%rbp), %eax
    imull   %eax, %edx
    movl    %edx, %eax
    cltd
    movl    $998244353, %ebx
    idivl   %ebx
    movl    %edx, %eax
    jmp     .L2
.L6:
    movl    -12(%rbp), %eax
    movl    -12(%rbp), %ebx
    imull   %ebx, %eax
    cltd
    movl    $998244353, %ebx
    idivl   %ebx
    movl    %edx, %eax
.L2:
    leave
    ret
.globl min
min:
    pushq   %rbp
    movq    %rsp, %rbp
    subq    $16, %rsp
    movl    %ecx, -4(%rbp)
    movl    %edx, -8(%rbp)
    movl    -4(%rbp), %eax
    movl    -8(%rbp), %ebx
    cmpl    %ebx, %eax
    jge     .L8
.L7:
    movl    -4(%rbp), %eax
    jmp     .L9
    jmp     .L10
.L8:
    movl    -8(%rbp), %eax
    jmp     .L9
.L10:
.L9:
    leave
    ret
.globl main
main:
    pushq   %rbp
    movq    %rsp, %rbp
    subq    $16, %rsp
    leaq    .LC0(%rip), %rcx
    leaq    n(%rip), %rdx
    leaq    k(%rip), %r8
    subq    $32, %rsp
    call    scanf
    addq    $32, %rsp
    movl    $1, -4(%rbp)
    jmp     .L12
.L11:
    movl    -4(%rbp), %eax
    movl    n(%rip), %ebx
    cmpl    %ebx, %eax
    jle     .L15
.L14:
    jmp     .L13
.L15:
    movl    -4(%rbp), %eax
    leaq    .LC1(%rip), %rcx
    leaq    a(%rip), %rbx
    leaq    (%rbx, %rax, 4), %rdx
    subq    $32, %rsp
    call    scanf
    addq    $32, %rsp
    movl    -4(%rbp), %eax
    addl    $1, %eax
    movl    %eax, -4(%rbp)
.L12:
    jmp     .L11
    jne      .L11
.L13:
    movl    $1, -4(%rbp)
    jmp     .L17
.L16:
    movl    -4(%rbp), %eax
    movl    n(%rip), %ebx
    cmpl    %ebx, %eax
    jle     .L20
.L19:
    jmp     .L18
.L20:
    movl    -4(%rbp), %eax
    leaq    .LC2(%rip), %rcx
    leaq    p(%rip), %rbx
    leaq    (%rbx, %rax, 4), %rdx
    subq    $32, %rsp
    call    scanf
    addq    $32, %rsp
    movl    -4(%rbp), %eax
    addl    $1, %eax
    movl    %eax, -4(%rbp)
.L17:
    jmp     .L16
    jne      .L16
.L18:
    movl    $1, g(%rip)
    movl    $1, -4(%rbp)
    jmp     .L22
.L21:
    movl    -4(%rbp), %eax
    movl    n(%rip), %ebx
    cmpl    %ebx, %eax
    jle     .L25
.L24:
    jmp     .L23
.L25:
    movl    -4(%rbp), %eax
    imull   $22, %eax
    addl    $0, %eax
    imull   $2, %eax
    addl    $0, %eax
    leaq    dp(%rip), %rbx
    movl    $0, (%rbx, %rax, 4)
    movl    -4(%rbp), %eax
    imull   $22, %eax
    addl    $0, %eax
    imull   $2, %eax
    addl    $0, %eax
    movl    -4(%rbp), %ebx
    leaq    p(%rip), %rcx
    movl    (%rcx, %rbx, 4), %edx
    movl    $1, %ebx
    subl    %edx, %ebx
    addl    $998244353, %ebx
    movl    -4(%rbp), %ecx
    subl    $1, %ecx
    imull   $22, %ecx
    addl    $0, %ecx
    imull   $2, %ecx
    addl    $0, %ecx
    leaq    g(%rip), %rdx
    movl    (%rdx, %rcx, 4), %esi
    imull   %esi, %ebx
    movl    %eax, %ecx
    movl    %ebx, %eax
    cltd
    movl    $998244353, %ebx
    idivl   %ebx
    leaq    g(%rip), %rax
    movl    %edx, (%rax, %rcx, 4)
    movl    $1, -8(%rbp)
    jmp     .L27
.L26:
    movl    -8(%rbp), %eax
    movl    %eax, %ebx
    push    %rbx
    movl    -4(%rbp), %eax
    addl    $1, %eax
    cltd
    movl    $2, %ebx
    idivl   %ebx
    movl    k(%rip), %ebx
    movl    %ebx, %ecx
    movl    %eax, %edx
    call    min
    pop     %rbx
    cmpl    %eax, %ebx
    jle     .L30
.L29:
    jmp     .L28
.L30:
    movl    -4(%rbp), %eax
    imull   $22, %eax
    movl    -8(%rbp), %ebx
    addl    %ebx, %eax
    imull   $2, %eax
    addl    $0, %eax
    movl    -4(%rbp), %ebx
    imull   $22, %ebx
    movl    -8(%rbp), %ecx
    addl    %ecx, %ebx
    imull   $2, %ebx
    addl    $0, %ebx
    leaq    dp(%rip), %rcx
    movl    (%rcx, %rbx, 4), %edx
    movl    -4(%rbp), %ebx
    leaq    p(%rip), %rcx
    movl    (%rcx, %rbx, 4), %esi
    movl    $1, %ebx
    subl    %esi, %ebx
    addl    $998244353, %ebx
    movl    -4(%rbp), %ecx
    subl    $1, %ecx
    imull   $22, %ecx
    movl    -8(%rbp), %esi
    addl    %esi, %ecx
    imull   $2, %ecx
    addl    $1, %ecx
    leaq    dp(%rip), %rsi
    movl    (%rsi, %rcx, 4), %edi
    movl    -4(%rbp), %ecx
    subl    $1, %ecx
    imull   $22, %ecx
    movl    -8(%rbp), %esi
    addl    %esi, %ecx
    imull   $2, %ecx
    addl    $0, %ecx
    leaq    dp(%rip), %rsi
    movl    (%rsi, %rcx, 4), %r8d
    addl    %r8d, %edi
    imull   %edi, %ebx
    movl    %eax, %ecx
    movl    %ebx, %eax
    movl    %edx, %ebx
    cltd
    movl    $998244353, %esi
    idivl   %esi
    addl    %edx, %ebx
    leaq    dp(%rip), %rax
    movl    %ebx, (%rax, %rcx, 4)
    movl    -4(%rbp), %eax
    imull   $22, %eax
    movl    -8(%rbp), %ebx
    addl    %ebx, %eax
    imull   $2, %eax
    addl    $0, %eax
    movl    -4(%rbp), %ebx
    imull   $22, %ebx
    movl    -8(%rbp), %ecx
    addl    %ecx, %ebx
    imull   $2, %ebx
    addl    $0, %ebx
    leaq    dp(%rip), %rcx
    movl    (%rcx, %rbx, 4), %edx
    movl    %eax, %ebx
    movl    %edx, %eax
    cltd
    movl    $998244353, %ecx
    idivl   %ecx
    leaq    dp(%rip), %rax
    movl    %edx, (%rax, %rbx, 4)
    movl    -4(%rbp), %eax
    imull   $22, %eax
    movl    -8(%rbp), %ebx
    addl    %ebx, %eax
    imull   $2, %eax
    addl    $1, %eax
    movl    -4(%rbp), %ebx
    imull   $22, %ebx
    movl    -8(%rbp), %ecx
    addl    %ecx, %ebx
    imull   $2, %ebx
    addl    $1, %ebx
    leaq    dp(%rip), %rcx
    movl    (%rcx, %rbx, 4), %edx
    movl    -4(%rbp), %ebx
    leaq    p(%rip), %rcx
    movl    (%rcx, %rbx, 4), %esi
    movl    -4(%rbp), %ebx
    subl    $1, %ebx
    imull   $22, %ebx
    movl    -8(%rbp), %ecx
    subl    $1, %ecx
    addl    %ecx, %ebx
    imull   $2, %ebx
    addl    $0, %ebx
    leaq    dp(%rip), %rcx
    movl    (%rcx, %rbx, 4), %edi
    movl    -4(%rbp), %ebx
    subl    $1, %ebx
    imull   $22, %ebx
    movl    -8(%rbp), %ecx
    subl    $1, %ecx
    addl    %ecx, %ebx
    imull   $2, %ebx
    addl    $0, %ebx
    leaq    g(%rip), %rcx
    movl    (%rcx, %rbx, 4), %r8d
    imull   $1, %r8d
    movl    -4(%rbp), %ebx
    leaq    a(%rip), %rcx
    movl    (%rcx, %rbx, 4), %r9d
    imull   %r9d, %r8d
    movl    %eax, %ebx
    movl    %r8d, %eax
    movl    %edx, %ecx
    cltd
    movl    $998244353, %r8d
    idivl   %r8d
    addl    %edx, %edi
    imull   %edi, %esi
    movl    %esi, %eax
    cltd
    movl    $998244353, %esi
    idivl   %esi
    addl    %edx, %ecx
    leaq    dp(%rip), %rax
    movl    %ecx, (%rax, %rbx, 4)
    movl    -4(%rbp), %eax
    imull   $22, %eax
    movl    -8(%rbp), %ebx
    addl    %ebx, %eax
    imull   $2, %eax
    addl    $1, %eax
    movl    -4(%rbp), %ebx
    imull   $22, %ebx
    movl    -8(%rbp), %ecx
    addl    %ecx, %ebx
    imull   $2, %ebx
    addl    $1, %ebx
    leaq    dp(%rip), %rcx
    movl    (%rcx, %rbx, 4), %edx
    movl    %eax, %ebx
    movl    %edx, %eax
    cltd
    movl    $998244353, %ecx
    idivl   %ecx
    leaq    dp(%rip), %rax
    movl    %edx, (%rax, %rbx, 4)
    movl    -4(%rbp), %eax
    imull   $22, %eax
    movl    -8(%rbp), %ebx
    addl    %ebx, %eax
    imull   $2, %eax
    addl    $1, %eax
    movl    -4(%rbp), %ebx
    imull   $22, %ebx
    movl    -8(%rbp), %ecx
    addl    %ecx, %ebx
    imull   $2, %ebx
    addl    $1, %ebx
    leaq    dp(%rip), %rcx
    movl    (%rcx, %rbx, 4), %edx
    movl    -4(%rbp), %ebx
    leaq    p(%rip), %rcx
    movl    (%rcx, %rbx, 4), %esi
    movl    -4(%rbp), %ebx
    subl    $1, %ebx
    imull   $22, %ebx
    movl    -8(%rbp), %ecx
    addl    %ecx, %ebx
    imull   $2, %ebx
    addl    $1, %ebx
    leaq    dp(%rip), %rcx
    movl    (%rcx, %rbx, 4), %edi
    movl    -4(%rbp), %ebx
    subl    $1, %ebx
    imull   $22, %ebx
    movl    -8(%rbp), %ecx
    addl    %ecx, %ebx
    imull   $2, %ebx
    addl    $1, %ebx
    leaq    g(%rip), %rcx
    movl    (%rcx, %rbx, 4), %r8d
    imull   $1, %r8d
    movl    -4(%rbp), %ebx
    leaq    a(%rip), %rcx
    movl    (%rcx, %rbx, 4), %r9d
    imull   %r9d, %r8d
    movl    %eax, %ebx
    movl    %r8d, %eax
    movl    %edx, %ecx
    cltd
    movl    $998244353, %r8d
    idivl   %r8d
    addl    %edx, %edi
    imull   %edi, %esi
    movl    %esi, %eax
    cltd
    movl    $998244353, %esi
    idivl   %esi
    addl    %edx, %ecx
    leaq    dp(%rip), %rax
    movl    %ecx, (%rax, %rbx, 4)
    movl    -4(%rbp), %eax
    imull   $22, %eax
    movl    -8(%rbp), %ebx
    addl    %ebx, %eax
    imull   $2, %eax
    addl    $1, %eax
    movl    -4(%rbp), %ebx
    imull   $22, %ebx
    movl    -8(%rbp), %ecx
    addl    %ecx, %ebx
    imull   $2, %ebx
    addl    $1, %ebx
    leaq    dp(%rip), %rcx
    movl    (%rcx, %rbx, 4), %edx
    movl    %eax, %ebx
    movl    %edx, %eax
    cltd
    movl    $998244353, %ecx
    idivl   %ecx
    leaq    dp(%rip), %rax
    movl    %edx, (%rax, %rbx, 4)
    movl    -4(%rbp), %eax
    imull   $22, %eax
    movl    -8(%rbp), %ebx
    addl    %ebx, %eax
    imull   $2, %eax
    addl    $1, %eax
    movl    -4(%rbp), %ebx
    imull   $22, %ebx
    movl    -8(%rbp), %ecx
    addl    %ecx, %ebx
    imull   $2, %ebx
    addl    $0, %ebx
    leaq    g(%rip), %rcx
    movl    (%rcx, %rbx, 4), %edx
    movl    -4(%rbp), %ebx
    leaq    p(%rip), %rcx
    movl    (%rcx, %rbx, 4), %esi
    movl    -4(%rbp), %ebx
    subl    $1, %ebx
    imull   $22, %ebx
    movl    -8(%rbp), %ecx
    addl    %ecx, %ebx
    imull   $2, %ebx
    addl    $1, %ebx
    leaq    g(%rip), %rcx
    movl    (%rcx, %rbx, 4), %edi
    movl    -4(%rbp), %ebx
    subl    $1, %ebx
    imull   $22, %ebx
    movl    -8(%rbp), %ecx
    subl    $1, %ecx
    addl    %ecx, %ebx
    imull   $2, %ebx
    addl    $0, %ebx
    leaq    g(%rip), %rcx
    movl    (%rcx, %rbx, 4), %r8d
    addl    %r8d, %edi
    imull   %edi, %esi
    movl    %eax, %ebx
    movl    %esi, %eax
    movl    %edx, %ecx
    cltd
    movl    $998244353, %esi
    idivl   %esi
    addl    %edx, %ecx
    leaq    g(%rip), %rax
    movl    %ecx, (%rax, %rbx, 4)
    movl    -4(%rbp), %eax
    imull   $22, %eax
    movl    -8(%rbp), %ebx
    addl    %ebx, %eax
    imull   $2, %eax
    addl    $1, %eax
    movl    -4(%rbp), %ebx
    imull   $22, %ebx
    movl    -8(%rbp), %ecx
    addl    %ecx, %ebx
    imull   $2, %ebx
    addl    $1, %ebx
    leaq    g(%rip), %rcx
    movl    (%rcx, %rbx, 4), %edx
    movl    %eax, %ebx
    movl    %edx, %eax
    cltd
    movl    $998244353, %ecx
    idivl   %ecx
    leaq    g(%rip), %rax
    movl    %edx, (%rax, %rbx, 4)
    movl    -4(%rbp), %eax
    imull   $22, %eax
    movl    -8(%rbp), %ebx
    addl    %ebx, %eax
    imull   $2, %eax
    addl    $0, %eax
    movl    -4(%rbp), %ebx
    imull   $22, %ebx
    movl    -8(%rbp), %ecx
    addl    %ecx, %ebx
    imull   $2, %ebx
    addl    $0, %ebx
    leaq    g(%rip), %rcx
    movl    (%rcx, %rbx, 4), %edx
    movl    -4(%rbp), %ebx
    leaq    p(%rip), %rcx
    movl    (%rcx, %rbx, 4), %esi
    movl    $1, %ebx
    subl    %esi, %ebx
    addl    $998244353, %ebx
    movl    -4(%rbp), %ecx
    subl    $1, %ecx
    imull   $22, %ecx
    movl    -8(%rbp), %esi
    addl    %esi, %ecx
    imull   $2, %ecx
    addl    $1, %ecx
    leaq    g(%rip), %rsi
    movl    (%rsi, %rcx, 4), %edi
    movl    -4(%rbp), %ecx
    subl    $1, %ecx
    imull   $22, %ecx
    movl    -8(%rbp), %esi
    addl    %esi, %ecx
    imull   $2, %ecx
    addl    $0, %ecx
    leaq    g(%rip), %rsi
    movl    (%rsi, %rcx, 4), %r8d
    addl    %r8d, %edi
    imull   %edi, %ebx
    movl    %eax, %ecx
    movl    %ebx, %eax
    movl    %edx, %ebx
    cltd
    movl    $998244353, %esi
    idivl   %esi
    addl    %edx, %ebx
    leaq    g(%rip), %rax
    movl    %ebx, (%rax, %rcx, 4)
    movl    -4(%rbp), %eax
    imull   $22, %eax
    movl    -8(%rbp), %ebx
    addl    %ebx, %eax
    imull   $2, %eax
    addl    $0, %eax
    movl    -4(%rbp), %ebx
    imull   $22, %ebx
    movl    -8(%rbp), %ecx
    addl    %ecx, %ebx
    imull   $2, %ebx
    addl    $0, %ebx
    leaq    g(%rip), %rcx
    movl    (%rcx, %rbx, 4), %edx
    movl    %eax, %ebx
    movl    %edx, %eax
    cltd
    movl    $998244353, %ecx
    idivl   %ecx
    leaq    g(%rip), %rax
    movl    %edx, (%rax, %rbx, 4)
    movl    -8(%rbp), %eax
    addl    $1, %eax
    movl    %eax, -8(%rbp)
.L27:
    jmp     .L26
    jne      .L26
.L28:
    movl    -4(%rbp), %eax
    addl    $1, %eax
    movl    %eax, -4(%rbp)
.L22:
    jmp     .L21
    jne      .L21
.L23:
    movl    n(%rip), %eax
    imull   $22, %eax
    movl    k(%rip), %ebx
    addl    %ebx, %eax
    imull   $2, %eax
    addl    $1, %eax
    leaq    g(%rip), %rbx
    movl    (%rbx, %rax, 4), %ecx
    movl    n(%rip), %eax
    imull   $22, %eax
    movl    k(%rip), %ebx
    addl    %ebx, %eax
    imull   $2, %eax
    addl    $0, %eax
    leaq    g(%rip), %rbx
    movl    (%rbx, %rax, 4), %edx
    addl    %edx, %ecx
    movl    %ecx, %eax
    cltd
    movl    $998244353, %ebx
    idivl   %ebx
    movl    %edx, %ecx
    movl    $998244351, %edx
    call    pw
    movl    %eax, -12(%rbp)
    movl    n(%rip), %eax
    imull   $22, %eax
    movl    k(%rip), %ebx
    addl    %ebx, %eax
    imull   $2, %eax
    addl    $1, %eax
    leaq    dp(%rip), %rbx
    movl    (%rbx, %rax, 4), %ecx
    movl    n(%rip), %eax
    imull   $22, %eax
    movl    k(%rip), %ebx
    addl    %ebx, %eax
    imull   $2, %eax
    addl    $0, %eax
    leaq    dp(%rip), %rbx
    movl    (%rbx, %rax, 4), %edx
    addl    %edx, %ecx
    movl    %ecx, %eax
    cltd
    movl    $998244353, %ebx
    idivl   %ebx
    leaq    .LC3(%rip), %rcx
    subq    $32, %rsp
    call    printf
    addq    $32, %rsp
    movl    $0, %eax
    leave
    ret
