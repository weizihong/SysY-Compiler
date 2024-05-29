.section .rdata
.LC0:
    .string "%c"
.LC1:
    .string "%d\n"

.section .data

.section .bss
.section .text
.globl get_next
get_next:
    pushq   %rbp
    movq    %rsp, %rbp
    subq    $32, %rsp
    movq    %rcx, -8(%rbp)
    movq    %rdx, -16(%rbp)
    movq    -16(%rbp), %rax
    movl    $-1, (%rax)
    movl    $0, -20(%rbp)
    movl    $-1, -24(%rbp)
    jmp     .L1
.L0:
    movl    -24(%rbp), %eax
    cmpl    $-1, %eax
    je      .L3
.L5:
    movl    -20(%rbp), %eax
    movq    -8(%rbp), %rbx
    movl    (%rbx, %rax, 4), %ecx
    movl    -24(%rbp), %eax
    movq    -8(%rbp), %rbx
    movl    (%rbx, %rax, 4), %edx
    cmpl    %ecx, %edx
    jne     .L4
.L3:
    movl    -24(%rbp), %eax
    addl    $1, %eax
    movl    %eax, -24(%rbp)
    movl    -20(%rbp), %eax
    addl    $1, %eax
    movl    %eax, -20(%rbp)
    movl    -20(%rbp), %eax
    movl    -24(%rbp), %ebx
    movq    -16(%rbp), %rcx
    movl    %ebx, (%rcx, %rax, 4)
    jmp     .L6
.L4:
    movl    -24(%rbp), %eax
    movq    -16(%rbp), %rbx
    movl    (%rbx, %rax, 4), %ecx
    movl    %ecx, -24(%rbp)
.L6:
.L1:
    movl    -20(%rbp), %eax
    movq    -8(%rbp), %rbx
    movl    (%rbx, %rax, 4), %ecx
    cmpl    $0, %ecx
    jne      .L0
.L2:
    leave
    ret
.globl KMP
KMP:
    pushq   %rbp
    movq    %rsp, %rbp
    movl    $16416, %eax
    call    ___chkstk_ms
    subq    %rax, %rsp
    movq    %rcx, -8(%rbp)
    movq    %rdx, -16(%rbp)
    movq    -8(%rbp), %rax
    leaq    (%rax), %rcx
    leaq    -16400(%rbp), %rdx
    call    get_next
    movl    $0, -16404(%rbp)
    movl    $0, -16408(%rbp)
    jmp     .L8
.L7:
    movl    -16404(%rbp), %eax
    movq    -8(%rbp), %rbx
    movl    (%rbx, %rax, 4), %ecx
    movl    -16408(%rbp), %eax
    movq    -16(%rbp), %rbx
    movl    (%rbx, %rax, 4), %edx
    cmpl    %ecx, %edx
    jne     .L11
.L10:
    movl    -16404(%rbp), %eax
    addl    $1, %eax
    movl    %eax, -16404(%rbp)
    movl    -16408(%rbp), %eax
    addl    $1, %eax
    movl    %eax, -16408(%rbp)
    movl    -16404(%rbp), %eax
    movq    -8(%rbp), %rbx
    movl    (%rbx, %rax, 4), %ecx
    cmpl    $0, %ecx
    jne      .L13
.L12:
    movl    -16408(%rbp), %eax
    jmp     .L14
.L13:
    jmp     .L15
.L11:
    movl    -16404(%rbp), %eax
    movl    -16400(%rbp, %rax, 4), %ebx
    movl    %ebx, -16404(%rbp)
    movl    -16404(%rbp), %eax
    cmpl    $-1, %eax
    jne     .L17
.L16:
    movl    -16404(%rbp), %eax
    addl    $1, %eax
    movl    %eax, -16404(%rbp)
    movl    -16408(%rbp), %eax
    addl    $1, %eax
    movl    %eax, -16408(%rbp)
.L17:
.L15:
.L8:
    movl    -16408(%rbp), %eax
    movq    -16(%rbp), %rbx
    movl    (%rbx, %rax, 4), %ecx
    cmpl    $0, %ecx
    jne      .L7
.L9:
    movl    $-1, %eax
.L14:
    leave
    ret
.globl read_str
read_str:
    pushq   %rbp
    movq    %rsp, %rbp
    subq    $16, %rsp
    movq    %rcx, -8(%rbp)
    movl    $0, -12(%rbp)
    jmp     .L19
.L18:
    movl    -12(%rbp), %eax
    leaq    .LC0(%rip), %rcx
    movq    -8(%rbp), %rbx
    leaq    (%rbx, %rax, 4), %rdx
    subq    $32, %rsp
    call    scanf
    addq    $32, %rsp
    movl    -12(%rbp), %eax
    movq    -8(%rbp), %rbx
    movl    (%rbx, %rax, 4), %ecx
    cmpl    $10, %ecx
    jne     .L22
.L21:
    jmp     .L20
.L22:
    movl    -12(%rbp), %eax
    addl    $1, %eax
    movl    %eax, -12(%rbp)
.L19:
    jmp     .L18
    jne      .L18
.L20:
    movl    -12(%rbp), %eax
    movq    -8(%rbp), %rbx
    movl    $0, (%rbx, %rax, 4)
    movl    -12(%rbp), %eax
    leave
    ret
.globl main
main:
    pushq   %rbp
    movq    %rsp, %rbp
    movl    $32768, %eax
    call    ___chkstk_ms
    subq    %rax, %rsp
    leaq    -16384(%rbp), %rcx
    call    read_str
    leaq    -32768(%rbp), %rcx
    call    read_str
    leaq    -16384(%rbp), %rcx
    leaq    -32768(%rbp), %rdx
    call    KMP
    leaq    .LC1(%rip), %rcx
    movl    %eax, %edx
    subq    $32, %rsp
    call    printf
    addq    $32, %rsp
    movl    $8, %eax
    leave
    ret
