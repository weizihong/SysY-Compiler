.section .rdata
.LC0:
    .string "%d\n"
.LC1:
    .string "%d\n"
.LC2:
    .string "%d\n"
.LC3:
    .string "%d\n"
.section .data

N:
    .long 10000
.section .bss
.section .text
.globl long_array
long_array:
    pushq   %rbp
    movq    %rsp, %rbp
    movl    $120032, %eax
    call    ___chkstk_ms
    subq    %rax, %rsp
    movl    %ecx, -4(%rbp)
    movl    $0, -120008(%rbp)
    jmp     .L1
.L0:
    movl    -120008(%rbp), %eax
    movl    -120008(%rbp), %ebx
    movl    -120008(%rbp), %ecx
    imull   %ecx, %ebx
    movl    %eax, %ecx
    movl    %ebx, %eax
    cltd
    movl    $10, %ebx
    idivl   %ebx
    movl    %edx, -40004(%rbp, %rcx, 4)
    movl    -120008(%rbp), %eax
    addl    $1, %eax
    movl    %eax, -120008(%rbp)
.L1:
    movl    -120008(%rbp), %eax
    cmpl    $10000, %eax
    jl      .L0
.L2:
    movl    $0, -120008(%rbp)
    jmp     .L4
.L3:
    movl    -120008(%rbp), %eax
    movl    -120008(%rbp), %ebx
    movl    -40004(%rbp, %rbx, 4), %ecx
    movl    -120008(%rbp), %ebx
    movl    -40004(%rbp, %rbx, 4), %edx
    imull   %edx, %ecx
    movl    %eax, %ebx
    movl    %ecx, %eax
    cltd
    movl    $10, %ecx
    idivl   %ecx
    movl    %edx, -80004(%rbp, %rbx, 4)
    movl    -120008(%rbp), %eax
    addl    $1, %eax
    movl    %eax, -120008(%rbp)
.L4:
    movl    -120008(%rbp), %eax
    cmpl    $10000, %eax
    jl      .L3
.L5:
    movl    $0, -120008(%rbp)
    jmp     .L7
.L6:
    movl    -120008(%rbp), %eax
    movl    -120008(%rbp), %ebx
    movl    -80004(%rbp, %rbx, 4), %ecx
    movl    -120008(%rbp), %ebx
    movl    -80004(%rbp, %rbx, 4), %edx
    imull   %edx, %ecx
    movl    %eax, %ebx
    movl    %ecx, %eax
    cltd
    movl    $100, %ecx
    idivl   %ecx
    movl    -120008(%rbp), %eax
    movl    -40004(%rbp, %rax, 4), %ecx
    addl    %ecx, %edx
    movl    %edx, -120004(%rbp, %rbx, 4)
    movl    -120008(%rbp), %eax
    addl    $1, %eax
    movl    %eax, -120008(%rbp)
.L7:
    movl    -120008(%rbp), %eax
    cmpl    $10000, %eax
    jl      .L6
.L8:
    movl    $0, -120012(%rbp)
    movl    $0, -120008(%rbp)
    jmp     .L10
.L9:
    movl    -120008(%rbp), %eax
    cmpl    $10, %eax
    jge     .L13
.L12:
    movl    -120012(%rbp), %eax
    movl    -120008(%rbp), %ebx
    movl    -120004(%rbp, %rbx, 4), %ecx
    addl    %ecx, %eax
    cltd
    movl    $1333, %ebx
    idivl   %ebx
    movl    %edx, -120012(%rbp)
    movl    -120012(%rbp), %eax
    leaq    .LC0(%rip), %rcx
    movl    %eax, %edx
    subq    $32, %rsp
    call    printf
    addq    $32, %rsp
    jmp     .L14
.L13:
    movl    -120008(%rbp), %eax
    cmpl    $20, %eax
    jge     .L16
.L15:
    movl    $5000, -120016(%rbp)
    jmp     .L18
.L17:
    movl    -120012(%rbp), %eax
    movl    -120008(%rbp), %ebx
    movl    -120004(%rbp, %rbx, 4), %ecx
    addl    %ecx, %eax
    movl    -120016(%rbp), %ebx
    movl    -40004(%rbp, %rbx, 4), %ecx
    subl    %ecx, %eax
    movl    %eax, -120012(%rbp)
    movl    -120016(%rbp), %eax
    addl    $1, %eax
    movl    %eax, -120016(%rbp)
.L18:
    movl    -120016(%rbp), %eax
    cmpl    $10000, %eax
    jl      .L17
.L19:
    movl    -120012(%rbp), %eax
    leaq    .LC1(%rip), %rcx
    movl    %eax, %edx
    subq    $32, %rsp
    call    printf
    addq    $32, %rsp
    jmp     .L20
.L16:
    movl    -120008(%rbp), %eax
    cmpl    $30, %eax
    jge     .L22
.L21:
    movl    $5000, -120020(%rbp)
    jmp     .L24
.L23:
    movl    -120020(%rbp), %eax
    cmpl    $2233, %eax
    jle     .L27
.L26:
    movl    -120012(%rbp), %eax
    movl    -120008(%rbp), %ebx
    movl    -80004(%rbp, %rbx, 4), %ecx
    addl    %ecx, %eax
    movl    -120020(%rbp), %ebx
    movl    -40004(%rbp, %rbx, 4), %ecx
    subl    %ecx, %eax
    movl    %eax, -120012(%rbp)
    movl    -120020(%rbp), %eax
    addl    $1, %eax
    movl    %eax, -120020(%rbp)
    jmp     .L28
.L27:
    movl    -120012(%rbp), %eax
    movl    -120008(%rbp), %ebx
    movl    -40004(%rbp, %rbx, 4), %ecx
    addl    %ecx, %eax
    movl    -120020(%rbp), %ebx
    movl    -120004(%rbp, %rbx, 4), %ecx
    addl    %ecx, %eax
    cltd
    movl    $13333, %ebx
    idivl   %ebx
    movl    %edx, -120012(%rbp)
    movl    -120020(%rbp), %eax
    addl    $2, %eax
    movl    %eax, -120020(%rbp)
.L28:
.L24:
    movl    -120020(%rbp), %eax
    cmpl    $10000, %eax
    jl      .L23
.L25:
    movl    -120012(%rbp), %eax
    leaq    .LC2(%rip), %rcx
    movl    %eax, %edx
    subq    $32, %rsp
    call    printf
    addq    $32, %rsp
    jmp     .L29
.L22:
    movl    -120012(%rbp), %eax
    movl    -120008(%rbp), %ebx
    movl    -120004(%rbp, %rbx, 4), %ecx
    movl    -4(%rbp), %ebx
    imull   %ebx, %ecx
    addl    %ecx, %eax
    cltd
    movl    $99988, %ebx
    idivl   %ebx
    movl    %edx, -120012(%rbp)
.L29:
.L20:
.L14:
    movl    -120008(%rbp), %eax
    addl    $1, %eax
    movl    %eax, -120008(%rbp)
.L10:
    movl    -120008(%rbp), %eax
    cmpl    $10000, %eax
    jl      .L9
.L11:
    movl    -120012(%rbp), %eax
    leave
    ret
.globl main
main:
    pushq   %rbp
    movq    %rsp, %rbp
    subq    $0, %rsp
    movl    $9, %ecx
    call    long_array
    leaq    .LC3(%rip), %rcx
    movl    %eax, %edx
    subq    $32, %rsp
    call    printf
    addq    $32, %rsp
    movl    $0, %eax
    leave
    ret
