	.file	"main.cc"
	.text
	.globl	glob
	.data
	.align 4
glob:
	.long	-1
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "%p\12 %d\12\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB4718:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	call	__main
	movl	$0, %r9d
	movl	$0, %r8d
	movl	$0, %edx
	movl	$0, %ecx
	movq	__imp_MessageBoxA(%rip), %rax
	call	*%rax
	movl	glob(%rip), %eax
	movl	%eax, %r8d
	leaq	glob(%rip), %rdx
	leaq	.LC0(%rip), %rcx
	call	printf
	movl	$0, %eax
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	printf;	.scl	2;	.type	32;	.endef
