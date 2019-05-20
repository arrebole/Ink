	.file	"main.cc"
	.text
	.section .rdata,"dr"
	.align 8
.LC0:
	.ascii "\346\210\220\345\212\237\346\224\271\345\217\230\345\207\275\346\225\260\350\260\203\347\224\250\351\241\272\345\272\217\0"
	.text
	.globl	_Z4hackv
	.def	_Z4hackv;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z4hackv
_Z4hackv:
.LFB28:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
.L2:
	leaq	.LC0(%rip), %rcx
	call	puts
	jmp	.L2
	.seh_endproc
	.globl	_Z5startv
	.def	_Z5startv;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z5startv
_Z5startv:
.LFB29:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$64, %rsp
	.seh_stackalloc	64
	.seh_endprologue
	leaq	_Z4hackv(%rip), %rax
	movq	%rax, 8(%rbp)
	nop
	addq	$64, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB30:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	call	__main
	call	_Z5startv
	movl	$0, %eax
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	puts;	.scl	2;	.type	32;	.endef
