.section .rdata
.LC0:
    .string "%d\n"
.section .data
count:
    .long 0
.section .bss
    .lcomm primes, 400000020
.section .text
.globl sieveOfEratosthenes
sieveOfEratosthenes:
    pushq   %rbp
    movq    %rsp, %rbp
    subq    $16, %rsp
    movl    %ecx, -4(%rbp)
    movl    $0, -8(%rbp)
    movl    $0, -12(%rbp)
    jmp     .L1
.L0:
    movl    -8(%rbp), %eax
    leaq    primes(%rip), %rbx
    movl    $1, (%rbx, %rax, 4)
    movl    -8(%rbp), %eax
    addl    $1, %eax
    movl    %eax, -8(%rbp)
.L1:
    movl    -8(%rbp), %eax
    movl    -4(%rbp), %ebx
    cmpl    %ebx, %eax
    jle     .L0
.L2:
    movl    $2, -8(%rbp)
    jmp     .L4
.L3:
    movl    -8(%rbp), %eax
    leaq    primes(%rip), %rbx
    movl    (%rbx, %rax, 4), %ecx
    cmpl    $1, %ecx
    jne     .L7
.L6:
    movl    -8(%rbp), %eax
    movl    -8(%rbp), %ebx
    imull   %ebx, %eax
    movl    %eax, -12(%rbp)
    jmp     .L9
.L8:
    movl    -12(%rbp), %eax
    leaq    primes(%rip), %rbx
    movl    $0, (%rbx, %rax, 4)
    movl    -12(%rbp), %eax
    movl    -8(%rbp), %ebx
    addl    %ebx, %eax
    movl    %eax, -12(%rbp)
.L9:
    movl    -12(%rbp), %eax
    movl    -4(%rbp), %ebx
    cmpl    %ebx, %eax
    jle     .L8
.L10:
.L7:
    movl    -8(%rbp), %eax
    addl    $1, %eax
    movl    %eax, -8(%rbp)
.L4:
    movl    -8(%rbp), %eax
    movl    -8(%rbp), %ebx
    imull   %ebx, %eax
    movl    -4(%rbp), %ebx
    cmpl    %ebx, %eax
    jle     .L3
.L5:
    movl    $2, -8(%rbp)
    jmp     .L12
.L11:
    movl    -8(%rbp), %eax
    leaq    primes(%rip), %rbx
    movl    (%rbx, %rax, 4), %ecx
    cmpl    $1, %ecx
    jne     .L15
.L14:
    movl    count(%rip), %eax
    addl    $1, %eax
    movl    %eax, count(%rip)
.L15:
    movl    -8(%rbp), %eax
    addl    $1, %eax
    movl    %eax, -8(%rbp)
.L12:
    movl    -8(%rbp), %eax
    movl    -4(%rbp), %ebx
    cmpl    %ebx, %eax
    jle     .L11
.L13:
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
    movl    $100, -4(%rbp)
    movl    -4(%rbp), %eax
    movl    %eax, %ecx
    call    sieveOfEratosthenes
    movl    $0, %eax
    leave
    ret
