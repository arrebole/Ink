	.file	"main.cc"
	.text
	.globl	glob
	.data
glob:
	.byte	-1
	.globl	g2
	.align 4
g2:
	.long	12
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "glob: %p\12\0"
.LC1:
	.ascii "b: %p\12\0"
.LC2:
	.ascii "a: %p\12\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB28:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	call	__main
	movl	$0, -12(%rbp)
	movl	$4800, %ecx
	call	_Znay
	movq	%rax, -8(%rbp)
	leaq	g2(%rip), %rdx
	leaq	.LC0(%rip), %rcx
	call	printf
	movq	-8(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC1(%rip), %rcx
	call	printf
	leaq	-12(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC2(%rip), %rcx
	call	printf
	movl	$0, %eax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	_Znay;	.scl	2;	.type	32;	.endef
	.def	printf;	.scl	2;	.type	32;	.endef
