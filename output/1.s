.section .rdata
.LC0:
    .string "%d\n"
.section .data
.section .bss
.section .text
.globl main
main:
    pushq   %rbp
    movq    %rsp, %rbp
    subq    $176, %rsp
    movl    $1, -32(%rbp)
    movl    $2, -28(%rbp)
    movl    $3, -24(%rbp)
    movl    $4, -20(%rbp)
    movl    $0, -16(%rbp)
    movl    $0, -12(%rbp)
    movl    $7, -8(%rbp)
    movl    $0, -4(%rbp)
    movl    $3, -36(%rbp)
    movl    $0, %eax
    movl    $8, %ecx
    leaq    -68(%rbp), %rdi
    rep stosl
    movl    $1, -100(%rbp)
    movl    $2, -96(%rbp)
    movl    $3, -92(%rbp)
    movl    $4, -88(%rbp)
    movl    $5, -84(%rbp)
    movl    $6, -80(%rbp)
    movl    $7, -76(%rbp)
    movl    $8, -72(%rbp)
    movl    $1, -132(%rbp)
    movl    $2, -128(%rbp)
    movl    $3, -124(%rbp)
    movl    $0, -120(%rbp)
    movl    $5, -116(%rbp)
    movl    $0, -112(%rbp)
    movl    $7, -108(%rbp)
    movl    $8, -104(%rbp)
    movl    -112(%rbp), %eax
    movl    %eax, -164(%rbp)
    movl    -80(%rbp), %eax
    movl    %eax, -160(%rbp)
    movl    $3, -156(%rbp)
    movl    $4, -152(%rbp)
    movl    $5, -148(%rbp)
    movl    $6, -144(%rbp)
    movl    $7, -140(%rbp)
    movl    $8, -136(%rbp)
    movl    -136(%rbp), %eax
    movl    -164(%rbp), %ebx
    addl    %ebx, %eax
    movl    -160(%rbp), %ebx
    addl    %ebx, %eax
    movl    -108(%rbp), %ebx
    addl    %ebx, %eax
    leaq    .LC0(%rip), %rcx
    movl    %eax, %edx
    subq    $32, %rsp
    call    printf
    addq    $32, %rsp
    movl    $0, %eax
    leave
    ret
