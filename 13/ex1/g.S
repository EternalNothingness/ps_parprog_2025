g:
        xorps   xmm0, XMMWORD PTR .LC12[rip]
g_solution:
        movd    eax, xmm0
        add     eax, -2147483648
        mov     DWORD PTR [rsp-12], eax
