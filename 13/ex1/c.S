c:
        lea     esi, [rdi+rdi*2]
        sal     esi, 5
c_solution:
        lea     ecx, [rdi+6]
        sal     edi, cl
        mov     esi, edi
        sal     esi, 5
