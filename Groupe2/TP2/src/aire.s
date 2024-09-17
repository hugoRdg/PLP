	.file	"aire.c"
	.text
	.section .rdata,"dr"
	.align 8
.LC0:
	.ascii "L'aire du cercle de rayon %.2f est %.2f\12\0"
	.text
	.p2align 4
	.def	printf.constprop.0;	.scl	3;	.type	32;	.endef
	.seh_proc	printf.constprop.0
printf.constprop.0:
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movl	$1, %ecx
	leaq	72(%rsp), %rbx
	movq	%rdx, 72(%rsp)
	movq	%r8, 80(%rsp)
	movq	%r9, 88(%rsp)
	movq	%rbx, 40(%rsp)
	call	*__imp___acrt_iob_func(%rip)
	movq	%rbx, %r8
	leaq	.LC0(%rip), %rdx
	movq	%rax, %rcx
	call	__mingw_vfprintf
	addq	$48, %rsp
	popq	%rbx
	ret
	.seh_endproc
	.p2align 4
	.globl	calculer_aire
	.def	calculer_aire;	.scl	2;	.type	32;	.endef
	.seh_proc	calculer_aire
calculer_aire:
	.seh_endprologue
	pxor	%xmm1, %xmm1
	cvtss2sd	%xmm0, %xmm1
	movsd	.LC1(%rip), %xmm0
	mulsd	%xmm1, %xmm0
	mulsd	%xmm1, %xmm0
	cvtsd2ss	%xmm0, %xmm0
	ret
	.seh_endproc
	.section	.text.startup,"x"
	.p2align 4
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	subq	$40, %rsp
	.seh_stackalloc	40
	.seh_endprologue
	call	__main
	leaq	.LC0(%rip), %rcx
	movabsq	$4635227165284106240, %r8
	movabsq	$4617315517961601024, %rdx
	movq	%r8, %xmm2
	movq	%rdx, %xmm1
	call	printf.constprop.0
	xorl	%eax, %eax
	addq	$40, %rsp
	ret
	.seh_endproc
	.section .rdata,"dr"
	.align 8
.LC1:
	.long	1413754136
	.long	1074340347
	.def	__main;	.scl	2;	.type	32;	.endef
	.ident	"GCC: (Rev1, Built by MSYS2 project) 14.2.0"
	.def	__mingw_vfprintf;	.scl	2;	.type	32;	.endef
