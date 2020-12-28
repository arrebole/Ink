.section .data
msg: 
    .ascii "hello world\n"

.section .text
	.globl	main
main:
	leaq	msg, %rcx
	call	printf
	call    exit
