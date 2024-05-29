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
    movl    $0, -76(%rbp)
    movl    $0, -72(%rbp)
    movl    $0, -68(%rbp)
    movl    $0, -64(%rbp)
    movl    $0, -60(%rbp)
    movl    $0, -56(%rbp)
    movl    $0, -52(%rbp)
    movl    $0, -48(%rbp)
    movl    $0, -44(%rbp)
    movl    $0, -40(%rbp)
    movl    $0, -36(%rbp)
    movl    $0, -32(%rbp)
    movl    $0, -28(%rbp)
    movl    $0, -24(%rbp)
    movl    $0, -20(%rbp)
    movl    $0, -16(%rbp)
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
    movl    $0, -1052(%rbp)
    movl    $0, -1048(%rbp)
    movl    $0, -1044(%rbp)
    movl    $0, -1040(%rbp)
    movl    $0, -1036(%rbp)
    movl    $0, -1032(%rbp)
    movl    $0, -1028(%rbp)
    movl    $0, -1024(%rbp)
    movl    $0, -1020(%rbp)
    movl    $0, -1016(%rbp)
    movl    $0, -1012(%rbp)
    movl    $0, -1008(%rbp)
    movl    $0, -1004(%rbp)
    movl    $0, -1000(%rbp)
    movl    $0, -996(%rbp)
    movl    $0, -992(%rbp)
    movl    $0, -988(%rbp)
    movl    $0, -984(%rbp)
    movl    $0, -980(%rbp)
    movl    $0, -976(%rbp)
    movl    $0, -972(%rbp)
    movl    $0, -968(%rbp)
    movl    $0, -964(%rbp)
    movl    $0, -960(%rbp)
    movl    $0, -956(%rbp)
    movl    $0, -952(%rbp)
    movl    $0, -948(%rbp)
    movl    $0, -944(%rbp)
    movl    $0, -940(%rbp)
    movl    $0, -936(%rbp)
    movl    $0, -932(%rbp)
    movl    $0, -928(%rbp)
    movl    $0, -924(%rbp)
    movl    $0, -920(%rbp)
    movl    $0, -916(%rbp)
    movl    $0, -912(%rbp)
    movl    $0, -908(%rbp)
    movl    $0, -904(%rbp)
    movl    $0, -900(%rbp)
    movl    $0, -896(%rbp)
    movl    $0, -892(%rbp)
    movl    $0, -888(%rbp)
    movl    $0, -884(%rbp)
    movl    $0, -880(%rbp)
    movl    $0, -876(%rbp)
    movl    $0, -872(%rbp)
    movl    $0, -868(%rbp)
    movl    $0, -864(%rbp)
    movl    $0, -860(%rbp)
    movl    $0, -856(%rbp)
    movl    $0, -852(%rbp)
    movl    $0, -848(%rbp)
    movl    $0, -844(%rbp)
    movl    $0, -840(%rbp)
    movl    $0, -836(%rbp)
    movl    $0, -832(%rbp)
    movl    $0, -828(%rbp)
    movl    $0, -824(%rbp)
    movl    $0, -820(%rbp)
    movl    $0, -816(%rbp)
    movl    $0, -812(%rbp)
    movl    $0, -808(%rbp)
    movl    $0, -804(%rbp)
    movl    $0, -800(%rbp)
    movl    $0, -796(%rbp)
    movl    $0, -792(%rbp)
    movl    $0, -788(%rbp)
    movl    $0, -784(%rbp)
    movl    $0, -780(%rbp)
    movl    $0, -776(%rbp)
    movl    $0, -772(%rbp)
    movl    $0, -768(%rbp)
    movl    $0, -764(%rbp)
    movl    $0, -760(%rbp)
    movl    $0, -756(%rbp)
    movl    $0, -752(%rbp)
    movl    $0, -748(%rbp)
    movl    $0, -744(%rbp)
    movl    $0, -740(%rbp)
    movl    $0, -736(%rbp)
    movl    $0, -732(%rbp)
    movl    $0, -728(%rbp)
    movl    $0, -724(%rbp)
    movl    $0, -720(%rbp)
    movl    $0, -716(%rbp)
    movl    $0, -712(%rbp)
    movl    $0, -708(%rbp)
    movl    $0, -704(%rbp)
    movl    $0, -700(%rbp)
    movl    $0, -696(%rbp)
    movl    $0, -692(%rbp)
    movl    $0, -688(%rbp)
    movl    $0, -684(%rbp)
    movl    $0, -680(%rbp)
    movl    $0, -676(%rbp)
    movl    $0, -672(%rbp)
    movl    $0, -668(%rbp)
    movl    $0, -664(%rbp)
    movl    $0, -660(%rbp)
    movl    $0, -656(%rbp)
    movl    $0, -652(%rbp)
    movl    $0, -648(%rbp)
    movl    $0, -644(%rbp)
    movl    $0, -640(%rbp)
    movl    $0, -636(%rbp)
    movl    $0, -632(%rbp)
    movl    $0, -628(%rbp)
    movl    $0, -624(%rbp)
    movl    $0, -620(%rbp)
    movl    $0, -616(%rbp)
    movl    $0, -612(%rbp)
    movl    $0, -608(%rbp)
    movl    $0, -604(%rbp)
    movl    $0, -600(%rbp)
    movl    $0, -596(%rbp)
    movl    $0, -592(%rbp)
    movl    $0, -588(%rbp)
    movl    $0, -584(%rbp)
    movl    $0, -580(%rbp)
    movl    $0, -576(%rbp)
    movl    $0, -572(%rbp)
    movl    $0, -568(%rbp)
    movl    $0, -564(%rbp)
    movl    $0, -560(%rbp)
    movl    $0, -556(%rbp)
    movl    $0, -552(%rbp)
    movl    $0, -548(%rbp)
    movl    $0, -544(%rbp)
    movl    $0, -540(%rbp)
    movl    $0, -536(%rbp)
    movl    $0, -532(%rbp)
    movl    $0, -528(%rbp)
    movl    $0, -524(%rbp)
    movl    $0, -520(%rbp)
    movl    $0, -516(%rbp)
    movl    $0, -512(%rbp)
    movl    $0, -508(%rbp)
    movl    $0, -504(%rbp)
    movl    $0, -500(%rbp)
    movl    $0, -496(%rbp)
    movl    $0, -492(%rbp)
    movl    $0, -488(%rbp)
    movl    $0, -484(%rbp)
    movl    $0, -480(%rbp)
    movl    $0, -476(%rbp)
    movl    $0, -472(%rbp)
    movl    $0, -468(%rbp)
    movl    $0, -464(%rbp)
    movl    $0, -460(%rbp)
    movl    $0, -456(%rbp)
    movl    $0, -452(%rbp)
    movl    $0, -448(%rbp)
    movl    $0, -444(%rbp)
    movl    $0, -440(%rbp)
    movl    $0, -436(%rbp)
    movl    $0, -432(%rbp)
    movl    $0, -428(%rbp)
    movl    $0, -424(%rbp)
    movl    $0, -420(%rbp)
    movl    $0, -416(%rbp)
    movl    $0, -412(%rbp)
    movl    $0, -408(%rbp)
    movl    $0, -404(%rbp)
    movl    $0, -400(%rbp)
    movl    $0, -396(%rbp)
    movl    $0, -392(%rbp)
    movl    $0, -388(%rbp)
    movl    $0, -384(%rbp)
    movl    $0, -380(%rbp)
    movl    $0, -376(%rbp)
    movl    $0, -372(%rbp)
    movl    $0, -368(%rbp)
    movl    $0, -364(%rbp)
    movl    $0, -360(%rbp)
    movl    $0, -356(%rbp)
    movl    $0, -352(%rbp)
    movl    $0, -348(%rbp)
    movl    $0, -344(%rbp)
    movl    $0, -340(%rbp)
    movl    $0, -336(%rbp)
    movl    $0, -332(%rbp)
    movl    $0, -328(%rbp)
    movl    $0, -324(%rbp)
    movl    $0, -320(%rbp)
    movl    $0, -316(%rbp)
    movl    $0, -312(%rbp)
    movl    $0, -308(%rbp)
    movl    $0, -304(%rbp)
    movl    $0, -300(%rbp)
    movl    $0, -296(%rbp)
    movl    $0, -292(%rbp)
    movl    $0, -288(%rbp)
    movl    $0, -284(%rbp)
    movl    $0, -280(%rbp)
    movl    $0, -276(%rbp)
    movl    $0, -272(%rbp)
    movl    $0, -268(%rbp)
    movl    $0, -264(%rbp)
    movl    $0, -260(%rbp)
    movl    $0, -256(%rbp)
    movl    $0, -252(%rbp)
    movl    $0, -248(%rbp)
    movl    $0, -244(%rbp)
    movl    $0, -240(%rbp)
    movl    $0, -236(%rbp)
    movl    $0, -232(%rbp)
    movl    $0, -228(%rbp)
    movl    $0, -224(%rbp)
    movl    $0, -220(%rbp)
    movl    $0, -216(%rbp)
    movl    $0, -212(%rbp)
    movl    $0, -208(%rbp)
    movl    $0, -204(%rbp)
    movl    $0, -200(%rbp)
    movl    $0, -196(%rbp)
    movl    $0, -192(%rbp)
    movl    $0, -188(%rbp)
    movl    $0, -184(%rbp)
    movl    $0, -180(%rbp)
    movl    $0, -176(%rbp)
    movl    $0, -172(%rbp)
    movl    $0, -168(%rbp)
    movl    $0, -164(%rbp)
    movl    $0, -160(%rbp)
    movl    $0, -156(%rbp)
    movl    $0, -152(%rbp)
    movl    $0, -148(%rbp)
    movl    $0, -144(%rbp)
    movl    $0, -140(%rbp)
    movl    $0, -136(%rbp)
    movl    $0, -132(%rbp)
    movl    $0, -128(%rbp)
    movl    $0, -124(%rbp)
    movl    $0, -120(%rbp)
    movl    $0, -116(%rbp)
    movl    $0, -112(%rbp)
    movl    $0, -108(%rbp)
    movl    $0, -104(%rbp)
    movl    $0, -100(%rbp)
    movl    $0, -96(%rbp)
    movl    $0, -92(%rbp)
    movl    $0, -88(%rbp)
    movl    $0, -84(%rbp)
    movl    $0, -80(%rbp)
    movl    $0, -76(%rbp)
    movl    $0, -72(%rbp)
    movl    $0, -68(%rbp)
    movl    $0, -64(%rbp)
    movl    $0, -60(%rbp)
    movl    $0, -56(%rbp)
    movl    $0, -52(%rbp)
    movl    $0, -48(%rbp)
    movl    $0, -44(%rbp)
    movl    $0, -40(%rbp)
    movl    $0, -36(%rbp)
    movl    $0, -32(%rbp)
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
