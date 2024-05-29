.section .rdata
.LC0:
    .string "%d\n"
.section .data
.section .bss
.section .text
.globl foo
foo:
    pushq   %rbp
    movq    %rsp, %rbp
    subq    $144, %rsp
    movl    $0, -64(%rbp)
    movl    $1, -60(%rbp)
    movl    $2, -56(%rbp)
    movl    $3, -52(%rbp)
    movl    $0, -48(%rbp)
    movl    $1, -44(%rbp)
    movl    $2, -40(%rbp)
    movl    $3, -36(%rbp)
    movl    $0, -32(%rbp)
    movl    $1, -28(%rbp)
    movl    $2, -24(%rbp)
    movl    $3, -20(%rbp)
    movl    $0, -16(%rbp)
    movl    $1, -12(%rbp)
    movl    $2, -8(%rbp)
    movl    $3, -4(%rbp)
    movl    $3, -68(%rbp)
    movl    $7, -72(%rbp)
    movl    $5, -76(%rbp)
    movl    $6, -80(%rbp)
    movl    $1, -84(%rbp)
    movl    $0, -88(%rbp)
    movl    $3, -92(%rbp)
    movl    $5, -96(%rbp)
    movl    $4, -100(%rbp)
    movl    $2, -104(%rbp)
    movl    $7, -108(%rbp)
    movl    $9, -112(%rbp)
    movl    $8, -116(%rbp)
    movl    $1, -120(%rbp)
    movl    $4, -124(%rbp)
    movl    $6, -128(%rbp)
    movl    -68(%rbp), %eax
    movl    -72(%rbp), %ebx
    addl    %ebx, %eax
    movl    -76(%rbp), %ebx
    addl    %ebx, %eax
    movl    -80(%rbp), %ebx
    addl    %ebx, %eax
    movl    -84(%rbp), %ebx
    addl    %ebx, %eax
    movl    -88(%rbp), %ebx
    addl    %ebx, %eax
    movl    -92(%rbp), %ebx
    addl    %ebx, %eax
    movl    -96(%rbp), %ebx
    addl    %ebx, %eax
    movl    %eax, -132(%rbp)
    movl    -100(%rbp), %eax
    movl    -104(%rbp), %ebx
    addl    %ebx, %eax
    movl    -108(%rbp), %ebx
    addl    %ebx, %eax
    movl    -112(%rbp), %ebx
    addl    %ebx, %eax
    movl    -116(%rbp), %ebx
    addl    %ebx, %eax
    movl    -120(%rbp), %ebx
    addl    %ebx, %eax
    movl    -124(%rbp), %ebx
    addl    %ebx, %eax
    movl    -128(%rbp), %ebx
    addl    %ebx, %eax
    movl    %eax, -136(%rbp)
    movl    -132(%rbp), %eax
    movl    -136(%rbp), %ebx
    addl    %ebx, %eax
    movl    -68(%rbp), %ebx
    movl    -64(%rbp, %rbx, 4), %ecx
    addl    %ecx, %eax
    leave
    ret
.globl main
main:
    pushq   %rbp
    movq    %rsp, %rbp
    subq    $112, %rsp
    movl    $3, -4(%rbp)
    movl    $7, -8(%rbp)
    movl    $5, -12(%rbp)
    movl    $6, -16(%rbp)
    movl    $1, -20(%rbp)
    movl    $0, -24(%rbp)
    movl    $3, -28(%rbp)
    movl    $5, -32(%rbp)
    movl    $4, -36(%rbp)
    movl    $2, -40(%rbp)
    movl    $7, -44(%rbp)
    movl    $9, -48(%rbp)
    movl    $8, -52(%rbp)
    movl    $1, -56(%rbp)
    movl    $4, -60(%rbp)
    movl    $6, -64(%rbp)
    movl    -4(%rbp), %eax
    movl    -8(%rbp), %ebx
    addl    %ebx, %eax
    movl    -12(%rbp), %ebx
    addl    %ebx, %eax
    movl    -16(%rbp), %ebx
    addl    %ebx, %eax
    movl    -20(%rbp), %ebx
    addl    %ebx, %eax
    movl    -24(%rbp), %ebx
    addl    %ebx, %eax
    movl    -28(%rbp), %ebx
    addl    %ebx, %eax
    movl    -32(%rbp), %ebx
    addl    %ebx, %eax
    movl    %eax, -68(%rbp)
    movl    -36(%rbp), %eax
    movl    -40(%rbp), %ebx
    addl    %ebx, %eax
    movl    -44(%rbp), %ebx
    addl    %ebx, %eax
    movl    -48(%rbp), %ebx
    addl    %ebx, %eax
    movl    -52(%rbp), %ebx
    addl    %ebx, %eax
    movl    -56(%rbp), %ebx
    addl    %ebx, %eax
    movl    -60(%rbp), %ebx
    addl    %ebx, %eax
    movl    -64(%rbp), %ebx
    addl    %ebx, %eax
    movl    %eax, -72(%rbp)
    movl    -68(%rbp), %eax
    movl    %eax, %ebx
    push    %rbx
    call    foo
    pop     %rbx
    addl    %eax, %ebx
    movl    %ebx, -68(%rbp)
    movl    $4, -76(%rbp)
    movl    $7, -80(%rbp)
    movl    $2, -84(%rbp)
    movl    $5, -88(%rbp)
    movl    $8, -92(%rbp)
    movl    $0, -96(%rbp)
    movl    $6, -100(%rbp)
    movl    $3, -104(%rbp)
    movl    -72(%rbp), %eax
    movl    %eax, %ebx
    push    %rbx
    call    foo
    pop     %rbx
    addl    %eax, %ebx
    movl    %ebx, -72(%rbp)
    movl    -36(%rbp), %eax
    movl    %eax, -4(%rbp)
    movl    -40(%rbp), %eax
    movl    %eax, -8(%rbp)
    movl    -44(%rbp), %eax
    movl    %eax, -12(%rbp)
    movl    -48(%rbp), %eax
    movl    %eax, -16(%rbp)
    movl    -52(%rbp), %eax
    movl    %eax, -20(%rbp)
    movl    -56(%rbp), %eax
    movl    %eax, -24(%rbp)
    movl    -60(%rbp), %eax
    movl    %eax, -28(%rbp)
    movl    -64(%rbp), %eax
    movl    %eax, -32(%rbp)
    movl    -76(%rbp), %eax
    movl    -80(%rbp), %ebx
    addl    %ebx, %eax
    movl    -84(%rbp), %ebx
    addl    %ebx, %eax
    movl    -88(%rbp), %ebx
    addl    %ebx, %eax
    movl    -92(%rbp), %ebx
    addl    %ebx, %eax
    movl    -96(%rbp), %ebx
    addl    %ebx, %eax
    movl    -100(%rbp), %ebx
    addl    %ebx, %eax
    movl    -104(%rbp), %ebx
    addl    %ebx, %eax
    movl    %eax, -108(%rbp)
    movl    -68(%rbp), %eax
    movl    -72(%rbp), %ebx
    addl    %ebx, %eax
    movl    -108(%rbp), %ebx
    addl    %ebx, %eax
    movl    %eax, -112(%rbp)
    movl    -112(%rbp), %eax
    leaq    .LC0(%rip), %rcx
    movl    %eax, %edx
    subq    $32, %rsp
    call    printf
    addq    $32, %rsp
    movl    $0, %eax
    leave
    ret
