	.file	"main.c"
	.text
	.globl	time_elapsed
	.type	time_elapsed, @function
time_elapsed:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rsi, %rax
	movq	%rdi, %r8
	movq	%r8, %rsi
	movq	%r9, %rdi
	movq	%rax, %rdi
	movq	%rsi, -32(%rbp)
	movq	%rdi, -24(%rbp)
	movq	%rdx, -48(%rbp)
	movq	%rcx, -40(%rbp)
	movq	-48(%rbp), %rax
	movq	-32(%rbp), %rdx
	subq	%rdx, %rax
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%rax, %xmm0
	movsd	%xmm0, -8(%rbp)
	movq	-40(%rbp), %rax
	movq	-24(%rbp), %rdx
	subq	%rdx, %rax
	pxor	%xmm1, %xmm1
	cvtsi2sdq	%rax, %xmm1
	movsd	.LC0(%rip), %xmm0
	mulsd	%xmm1, %xmm0
	movsd	-8(%rbp), %xmm1
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -8(%rbp)
	movsd	-8(%rbp), %xmm0
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	time_elapsed, .-time_elapsed
	.section	.rodata
.LC1:
	.string	"time %lf \n"
.LC2:
	.string	"res : %ld\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	$0, -56(%rbp)
	leaq	-48(%rbp), %rax
	movq	%rax, %rsi
	movl	$0, %edi
	call	clock_gettime@PLT
	movl	$0, -64(%rbp)
	jmp	.L4
.L7:
	movl	$0, -60(%rbp)
	jmp	.L5
.L6:
	addq	$1, -56(%rbp)
	addl	$1, -60(%rbp)
.L5:
	cmpl	$999, -60(%rbp)
	jle	.L6
	addl	$1, -64(%rbp)
.L4:
	cmpl	$999, -64(%rbp)
	jle	.L7
	leaq	-32(%rbp), %rax
	movq	%rax, %rsi
	movl	$0, %edi
	call	clock_gettime@PLT
	movq	-32(%rbp), %rax
	movq	-24(%rbp), %rdx
	movq	-48(%rbp), %rdi
	movq	-40(%rbp), %rsi
	movq	%rdx, %rcx
	movq	%rax, %rdx
	call	time_elapsed
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$1, %eax
	call	printf@PLT
	movq	-56(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L9
	call	__stack_chk_fail@PLT
.L9:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC0:
	.long	-400107883
	.long	1041313291
	.ident	"GCC: (GNU) 11.2.0"
	.section	.note.GNU-stack,"",@progbits
