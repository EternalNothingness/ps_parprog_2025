e:
        lea     rax, [rdi+4000]
        xor     esi, esi
.L13:
        add     esi, DWORD PTR [rdi]
        add     rdi, 20
        cmp     rax, rdi
        jne     .L13
e_solution:
        lea     rax, [rdi+4000]
        xor     esi, esi
.L16:
        add     esi, DWORD PTR [rdi]
        add     rdi, 20
        cmp     rdi, rax
        jne     .L16
