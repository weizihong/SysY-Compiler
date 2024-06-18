.section .rdata
.LC0:
    .string "%d\n"
.LC1:
    .string "%d\n"
.section .data
.section .bss
.section .text
.globl MAX
MAX:
    pushq   %rbp
    movq    %rsp, %rbp
    subq    $16, %rsp
    movl    %ecx, -4(%rbp)
    movl    %edx, -8(%rbp)
    movl    -4(%rbp), %eax
    movl    -8(%rbp), %ebx
    cmpl    %eax, %ebx
    jne     .L1
.L0:
    movl    -4(%rbp), %eax
    jmp     .L2
    jmp     .L3
.L1:
    movl    -4(%rbp), %eax
    movl    -8(%rbp), %ebx
    cmpl    %ebx, %eax
    jle     .L5
.L4:
    movl    -4(%rbp), %eax
    jmp     .L2
    jmp     .L6
.L5:
    movl    -8(%rbp), %eax
    jmp     .L2
.L6:
.L3:
.L2:
    leave
    ret
.globl max_sum_nonadjacent
max_sum_nonadjacent:
    pushq   %rbp
    movq    %rsp, %rbp
    subq    $80, %rsp
    movq    %rcx, -8(%rbp)
    movl    %edx, -12(%rbp)
    movl    $0, %eax
    movl    $16, %ecx
    leaq    -76(%rbp), %rdi
    rep stosl
    movq    -8(%rbp), %rax
    movl    (%rax), %ebx
    movl    %ebx, -76(%rbp)
    movq    -8(%rbp), %rax
    movl    4(%rax), %ebx
    movq    -8(%rbp), %rax
    movl    (%rax), %ecx
    movl    %ebx, %edx
    call    MAX
    movl    %eax, -72(%rbp)
    movl    $2, -80(%rbp)
    jmp     .L8
.L7:
    movl    -80(%rbp), %eax
    movl    %eax, %ebx
    push    %rbx
    movl    -80(%rbp), %eax
    subl    $1, %eax
    movl    -76(%rbp, %rax, 4), %ebx
    movl    -80(%rbp), %eax
    subl    $2, %eax
    movl    -76(%rbp, %rax, 4), %ecx
    movl    -80(%rbp), %eax
    movq    -8(%rbp), %rdx
    movl    (%rdx, %rax, 4), %esi
    addl    %esi, %ecx
    movl    %ebx, %edx
    call    MAX
    pop     %rbx
    movl    %eax, -76(%rbp, %rbx, 4)
    movl    -80(%rbp), %eax
    addl    $1, %eax
    movl    %eax, -80(%rbp)
.L8:
    movl    -80(%rbp), %eax
    movl    -12(%rbp), %ebx
    cmpl    %ebx, %eax
    jl      .L7
.L9:
    movl    -12(%rbp), %eax
    subl    $1, %eax
    movl    -76(%rbp, %rax, 4), %ebx
    movl    %ebx, %eax
    leave
    ret
.globl longest_common_subseq
longest_common_subseq:
    pushq   %rbp
    movq    %rsp, %rbp
    subq    $1072, %rsp
    movq    %rcx, -8(%rbp)
    movl    %edx, -12(%rbp)
    movq    %r8, -24(%rbp)
    movl    %r9d, -28(%rbp)
    movl    $0, %eax
    movl    $256, %ecx
    leaq    -1052(%rbp), %rdi
    rep stosl
    movl    $1, -1056(%rbp)
    jmp     .L11
.L10:
    movl    $1, -1060(%rbp)
    jmp     .L14
.L13:
    movl    -1056(%rbp), %eax
    subl    $1, %eax
    movq    -8(%rbp), %rbx
    movl    (%rbx, %rax, 4), %ecx
    movl    -1060(%rbp), %eax
    subl    $1, %eax
    movq    -24(%rbp), %rbx
    movl    (%rbx, %rax, 4), %edx
    cmpl    %ecx, %edx
    jne     .L17
.L16:
    movl    -1056(%rbp), %eax
    imull   $16, %eax
    movl    -1060(%rbp), %ebx
    addl    %ebx, %eax
    movl    -1056(%rbp), %ebx
    subl    $1, %ebx
    imull   $16, %ebx
    movl    -1060(%rbp), %ecx
    subl    $1, %ecx
    addl    %ecx, %ebx
    movl    -1052(%rbp, %rbx, 4), %ecx
    addl    $1, %ecx
    movl    %ecx, -1052(%rbp, %rax, 4)
    jmp     .L18
.L17:
    movl    -1056(%rbp), %eax
    imull   $16, %eax
    movl    -1060(%rbp), %ebx
    addl    %ebx, %eax
    movl    %eax, %ebx
    push    %rbx
    movl    -1056(%rbp), %eax
    imull   $16, %eax
    movl    -1060(%rbp), %ebx
    subl    $1, %ebx
    addl    %ebx, %eax
    movl    -1052(%rbp, %rax, 4), %ebx
    movl    -1056(%rbp), %eax
    subl    $1, %eax
    imull   $16, %eax
    movl    -1060(%rbp), %ecx
    addl    %ecx, %eax
    movl    -1052(%rbp, %rax, 4), %ecx
    movl    %ebx, %edx
    call    MAX
    pop     %rbx
    movl    %eax, -1052(%rbp, %rbx, 4)
.L18:
    movl    -1060(%rbp), %eax
    addl    $1, %eax
    movl    %eax, -1060(%rbp)
.L14:
    movl    -1060(%rbp), %eax
    movl    -28(%rbp), %ebx
    cmpl    %ebx, %eax
    jle     .L13
.L15:
    movl    -1056(%rbp), %eax
    addl    $1, %eax
    movl    %eax, -1056(%rbp)
.L11:
    movl    -1056(%rbp), %eax
    movl    -12(%rbp), %ebx
    cmpl    %ebx, %eax
    jle     .L10
.L12:
    movl    -12(%rbp), %eax
    imull   $16, %eax
    movl    -28(%rbp), %ebx
    addl    %ebx, %eax
    movl    -1052(%rbp, %rax, 4), %ebx
    movl    %ebx, %eax
    leave
    ret
.globl main
main:
    pushq   %rbp
    movq    %rsp, %rbp
    subq    $112, %rsp
    movl    $8, -60(%rbp)
    movl    $7, -56(%rbp)
    movl    $4, -52(%rbp)
    movl    $1, -48(%rbp)
    movl    $2, -44(%rbp)
    movl    $7, -40(%rbp)
    movl    $0, -36(%rbp)
    movl    $1, -32(%rbp)
    movl    $9, -28(%rbp)
    movl    $3, -24(%rbp)
    movl    $4, -20(%rbp)
    movl    $8, -16(%rbp)
    movl    $3, -12(%rbp)
    movl    $7, -8(%rbp)
    movl    $0, -4(%rbp)
    movl    $3, -112(%rbp)
    movl    $9, -108(%rbp)
    movl    $7, -104(%rbp)
    movl    $1, -100(%rbp)
    movl    $4, -96(%rbp)
    movl    $2, -92(%rbp)
    movl    $4, -88(%rbp)
    movl    $3, -84(%rbp)
    movl    $6, -80(%rbp)
    movl    $8, -76(%rbp)
    movl    $0, -72(%rbp)
    movl    $1, -68(%rbp)
    movl    $5, -64(%rbp)
    leaq    -60(%rbp), %rcx
    movl    $15, %edx
    call    max_sum_nonadjacent
    leaq    .LC0(%rip), %rcx
    movl    %eax, %edx
    subq    $32, %rsp
    call    printf
    addq    $32, %rsp
    leaq    -60(%rbp), %rcx
    movl    $15, %edx
    leaq    -112(%rbp), %r8
    movl    $13, %r9d
    call    longest_common_subseq
    leaq    .LC1(%rip), %rcx
    movl    %eax, %edx
    subq    $32, %rsp
    call    printf
    addq    $32, %rsp
    movl    $0, %eax
    leave
    ret
