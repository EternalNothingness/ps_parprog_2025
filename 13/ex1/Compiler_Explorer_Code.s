	.file	"Compiler_Explorer_Code.c"
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"a): %u\n"
	.text
	.p2align 4
	.globl	a
	.type	a, @function
a:
.LFB22:
	.cfi_startproc
	movl	%edi, %esi
	xorl	%eax, %eax
	movl	$.LC0, %edi
	sall	$5, %esi
	jmp	printf
	.cfi_endproc
.LFE22:
	.size	a, .-a
	.p2align 4
	.globl	a_solution
	.type	a_solution, @function
a_solution:
.LFB23:
	.cfi_startproc
	movl	%edi, %esi
	xorl	%eax, %eax
	movl	$.LC0, %edi
	sall	$5, %esi
	jmp	printf
	.cfi_endproc
.LFE23:
	.size	a_solution, .-a_solution
	.section	.rodata.str1.1
.LC1:
	.string	"b): %u\n"
	.text
	.p2align 4
	.globl	b
	.type	b, @function
b:
.LFB24:
	.cfi_startproc
	movl	%edi, %esi
	xorl	%eax, %eax
	sall	$4, %esi
	subl	%edi, %esi
	movl	$.LC1, %edi
	jmp	printf
	.cfi_endproc
.LFE24:
	.size	b, .-b
	.p2align 4
	.globl	b_solution
	.type	b_solution, @function
b_solution:
.LFB25:
	.cfi_startproc
	movl	%edi, %esi
	xorl	%eax, %eax
	sall	$4, %esi
	subl	%edi, %esi
	movl	$.LC1, %edi
	jmp	printf
	.cfi_endproc
.LFE25:
	.size	b_solution, .-b_solution
	.section	.rodata.str1.1
.LC2:
	.string	"c): %u\n"
	.text
	.p2align 4
	.globl	c
	.type	c, @function
c:
.LFB26:
	.cfi_startproc
	leal	(%rdi,%rdi,2), %esi
	xorl	%eax, %eax
	movl	$.LC2, %edi
	sall	$5, %esi
	jmp	printf
	.cfi_endproc
.LFE26:
	.size	c, .-c
	.p2align 4
	.globl	c_solution
	.type	c_solution, @function
c_solution:
.LFB27:
	.cfi_startproc
	leal	6(%rdi), %ecx
	xorl	%eax, %eax
	sall	%cl, %edi
	movl	%edi, %esi
	movl	$.LC2, %edi
	sall	$5, %esi
	jmp	printf
	.cfi_endproc
.LFE27:
	.size	c_solution, .-c_solution
	.section	.rodata.str1.1
.LC4:
	.string	"d): %u\n"
	.text
	.p2align 4
	.globl	d
	.type	d, @function
d:
.LFB28:
	.cfi_startproc
	movl	%edi, %edi
	pxor	%xmm0, %xmm0
	xorl	%eax, %eax
	cvtsi2sdq	%rdi, %xmm0
	mulsd	.LC3(%rip), %xmm0
	movl	$.LC4, %edi
	cvttsd2siq	%xmm0, %rsi
	jmp	printf
	.cfi_endproc
.LFE28:
	.size	d, .-d
	.p2align 4
	.globl	d_solution
	.type	d_solution, @function
d_solution:
.LFB29:
	.cfi_startproc
	movl	%edi, %esi
	xorl	%eax, %eax
	movl	$.LC4, %edi
	shrl	$3, %esi
	jmp	printf
	.cfi_endproc
.LFE29:
	.size	d_solution, .-d_solution
	.section	.rodata.str1.1
.LC5:
	.string	"e): %u\n"
	.text
	.p2align 4
	.globl	e
	.type	e, @function
e:
.LFB30:
	.cfi_startproc
	leaq	4000(%rdi), %rax
	xorl	%esi, %esi
	.p2align 4
	.p2align 4
	.p2align 3
.L13:
	addl	(%rdi), %esi
	addq	$20, %rdi
	cmpq	%rdi, %rax
	jne	.L13
	movl	$.LC5, %edi
	xorl	%eax, %eax
	jmp	printf
	.cfi_endproc
.LFE30:
	.size	e, .-e
	.p2align 4
	.globl	e_solution
	.type	e_solution, @function
e_solution:
.LFB31:
	.cfi_startproc
	leaq	4000(%rdi), %rax
	xorl	%esi, %esi
	.p2align 4
	.p2align 4
	.p2align 3
.L16:
	addl	(%rdi), %esi
	addq	$20, %rdi
	cmpq	%rdi, %rax
	jne	.L16
	movl	$.LC5, %edi
	xorl	%eax, %eax
	jmp	printf
	.cfi_endproc
.LFE31:
	.size	e_solution, .-e_solution
	.section	.rodata.str1.1
.LC10:
	.string	"f):"
.LC11:
	.string	"%lf, "
	.text
	.p2align 4
	.globl	f
	.type	f, @function
f:
.LFB32:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movl	$4, %edx
	leaq	8000(%rdi), %rbp
	movq	%rdi, %rax
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	movd	%edx, %xmm4
	movq	%rdi, %rbx
	pshufd	$0, %xmm4, %xmm4
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	movsd	.LC9(%rip), %xmm3
	movdqa	.LC6(%rip), %xmm2
	unpcklpd	%xmm3, %xmm3
	.p2align 6
	.p2align 4
	.p2align 3
.L19:
	movdqa	%xmm2, %xmm0
	movupd	(%rax), %xmm6
	addq	$32, %rax
	paddd	%xmm4, %xmm2
	pshufd	$238, %xmm0, %xmm1
	cvtdq2pd	%xmm0, %xmm0
	movupd	-16(%rax), %xmm5
	divpd	%xmm3, %xmm0
	cvtdq2pd	%xmm1, %xmm1
	divpd	%xmm3, %xmm1
	addpd	%xmm6, %xmm0
	movups	%xmm0, -32(%rax)
	addpd	%xmm5, %xmm1
	movups	%xmm1, -16(%rax)
	cmpq	%rbp, %rax
	jne	.L19
	movl	$.LC10, %edi
	xorl	%eax, %eax
	call	printf
	.p2align 4
	.p2align 3
.L20:
	movsd	(%rbx), %xmm0
	movl	$.LC11, %edi
	movl	$1, %eax
	addq	$8, %rbx
	call	printf
	cmpq	%rbp, %rbx
	jne	.L20
	addq	$8, %rsp
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE32:
	.size	f, .-f
	.p2align 4
	.globl	f_solution
	.type	f_solution, @function
f_solution:
.LFB33:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movl	$4, %edx
	leaq	8000(%rdi), %rbp
	movq	%rdi, %rax
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	movd	%edx, %xmm4
	movq	%rdi, %rbx
	pshufd	$0, %xmm4, %xmm4
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	movsd	.LC13(%rip), %xmm3
	movdqa	.LC6(%rip), %xmm2
	unpcklpd	%xmm3, %xmm3
	.p2align 6
	.p2align 4
	.p2align 3
.L25:
	movdqa	%xmm2, %xmm0
	movupd	(%rax), %xmm6
	addq	$32, %rax
	paddd	%xmm4, %xmm2
	pshufd	$238, %xmm0, %xmm1
	cvtdq2pd	%xmm0, %xmm0
	movupd	-16(%rax), %xmm5
	mulpd	%xmm3, %xmm0
	cvtdq2pd	%xmm1, %xmm1
	mulpd	%xmm3, %xmm1
	addpd	%xmm6, %xmm0
	addpd	%xmm5, %xmm1
	movups	%xmm0, -32(%rax)
	movups	%xmm1, -16(%rax)
	cmpq	%rbp, %rax
	jne	.L25
	movl	$.LC10, %edi
	xorl	%eax, %eax
	call	printf
	.p2align 4
	.p2align 3
.L26:
	movsd	(%rbx), %xmm0
	movl	$.LC11, %edi
	movl	$1, %eax
	addq	$8, %rbx
	call	printf
	cmpq	%rbp, %rbx
	jne	.L26
	addq	$8, %rsp
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE33:
	.size	f_solution, .-f_solution
	.section	.rodata.str1.1
.LC15:
	.string	"g): %u\n"
	.text
	.p2align 4
	.globl	g
	.type	g, @function
g:
.LFB34:
	.cfi_startproc
	xorps	.LC14(%rip), %xmm0
	movl	$.LC15, %edi
	movl	$1, %eax
	cvtss2sd	%xmm0, %xmm0
	jmp	printf
	.cfi_endproc
.LFE34:
	.size	g, .-g
	.p2align 4
	.globl	g_solution
	.type	g_solution, @function
g_solution:
.LFB35:
	.cfi_startproc
	movd	%xmm0, %eax
	movl	$.LC15, %edi
	addl	$-2147483648, %eax
	movd	%eax, %xmm0
	movl	$1, %eax
	cvtss2sd	%xmm0, %xmm0
	jmp	printf
	.cfi_endproc
.LFE35:
	.size	g_solution, .-g_solution
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB36:
	.cfi_startproc
	xorl	%eax, %eax
	ret
	.cfi_endproc
.LFE36:
	.size	main, .-main
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC3:
	.long	0
	.long	1069547520
	.section	.rodata.cst16,"aM",@progbits,16
	.align 16
.LC6:
	.long	0
	.long	1
	.long	2
	.long	3
	.section	.rodata.cst8
	.align 8
.LC9:
	.long	858993459
	.long	1075131187
	.align 8
.LC13:
	.long	972445426
	.long	1070081700
	.section	.rodata.cst16
	.align 16
.LC14:
	.long	-2147483648
	.long	0
	.long	0
	.long	0
	.ident	"GCC: (GNU) 14.3.1 20250523 (Red Hat 14.3.1-1)"
	.section	.note.GNU-stack,"",@progbits
