# system call __x64_sys_write

.data					
msg:
	.ascii	"Hello, world!\n"	
	len = . - msg			

.text				
    .global _start	

_start:

# write our string to stdout
	movq	$len, %rdx	# third argument: message length
	movq	$msg, %rsi	# second argument: pointer to message to write
	movq	$1,   %rdi	# first argument: file handle (stdout)
	movq	$1,   %rax	# system call number (__x64_sys_write)
	syscall		    # call kernel

# and exit
	movq	$0, %rdi	# first argument: exit code
	movq	$60, %rax	# system call number (sys_exit)
	syscall		        # call kernel
