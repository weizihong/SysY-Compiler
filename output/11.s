.section .rdata
.LC0:
    .string "%d\n"
.section .data

a:
    .long 1, 2, 3

b:
    .long 0, 0, 0

c:
    .long 0

i:
    .long 5
.section .bss
.section .text
.globl func
func:
    pushq   %rbp
    movq    %rsp, %rbp
    subq    $16, %rsp
    movl    %ecx, -4(%rbp)
    movl    %edx, -8(%rbp)
    movl    %r8d, -12(%rbp)
    movl    $4, i(%rip)
    movl    -4(%rbp), %eax
    movl    -8(%rbp), %ebx
    addl    %ebx, %eax
    movl    -12(%rbp), %ebx
    addl    %ebx, %eax
    leave
    ret
.globl main
main:
    pushq   %rbp
    movq    %rsp, %rbp
    subq    $0, %rsp
    jmp     __global_init__
.L0:
    movl    c(%rip), %eax
    leaq    .LC0(%rip), %rcx
    movl    %eax, %edx
    subq    $32, %rsp
    call    printf
    addq    $32, %rsp
    movl    $0, %eax
    leave
    ret
__global_init__:
    movl    $3, %ecx
    movl    $1, %edx
    movl    $2, %r8d
    call    func
    movl    %eax, b(%rip)
    movl    i(%rip), %eax
    movl    %eax, b+4(%rip)
    movl    a+8(%rip), %eax
    movl    %eax, b+8(%rip)
    movl    b+8(%rip), %eax
    movl    b+4(%rip), %ebx
    movl    b(%rip), %ecx
    movl    %ebx, %edx
    movl    %eax, %r8d
    call    func
    movl    %eax, c(%rip)
    jmp     .L0
