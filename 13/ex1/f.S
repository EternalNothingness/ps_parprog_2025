f:
        push    rbp
        mov     rax, rdi
        lea     rbp, [rdi+8000]
        push    rbx
        mov     rbx, rdi
        sub     rsp, 8
        movdqa  xmm2, XMMWORD PTR .LC6[rip]
        movdqa  xmm4, XMMWORD PTR .LC7[rip]
        movapd  xmm3, XMMWORD PTR .LC8[rip]
.L19:
        pshufd  xmm0, xmm2, 238
        cvtdq2pd        xmm1, xmm2
        movupd  xmm6, XMMWORD PTR [rax]
        add     rax, 32
        cvtdq2pd        xmm0, xmm0
        divpd   xmm1, xmm3
        movupd  xmm5, XMMWORD PTR [rax-16]
        paddd   xmm2, xmm4
        divpd   xmm0, xmm3
        addpd   xmm1, xmm6
        movups  XMMWORD PTR [rax-32], xmm1
        addpd   xmm0, xmm5
        movups  XMMWORD PTR [rax-16], xmm0
        cmp     rax, rbp
        jne     .L19
f_solution:
        push    rbp
        mov     rax, rdi
        lea     rbp, [rdi+8000]
        push    rbx
        mov     rbx, rdi
        sub     rsp, 8
        movdqa  xmm2, XMMWORD PTR .LC6[rip]
        movdqa  xmm4, XMMWORD PTR .LC7[rip]
        movapd  xmm3, XMMWORD PTR .LC11[rip]
.L25:
        pshufd  xmm0, xmm2, 238
        cvtdq2pd        xmm1, xmm2
        movupd  xmm6, XMMWORD PTR [rax]
        add     rax, 32
        cvtdq2pd        xmm0, xmm0
        mulpd   xmm1, xmm3
        movupd  xmm5, XMMWORD PTR [rax-16]
        paddd   xmm2, xmm4
        mulpd   xmm0, xmm3
        addpd   xmm1, xmm6
        addpd   xmm0, xmm5
        movups  XMMWORD PTR [rax-32], xmm1
        movups  XMMWORD PTR [rax-16], xmm0
        cmp     rax, rbp
        jne     .L25
