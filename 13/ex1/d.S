d:
        mov     edi, edi
        pxor    xmm0, xmm0
        cvtsi2sdq       xmm0, rdi
        mulsd   xmm0, QWORD PTR .LC3[rip]
        cvttsd2si       rsi, xmm0
d_solution:
        mov     esi, edi
        shr     esi, 3
