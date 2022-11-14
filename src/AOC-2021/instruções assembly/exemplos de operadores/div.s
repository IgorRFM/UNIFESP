#start .text segment
	.text
	.globl main

main:
	li $t1, 30
	li $t2, 6
	div $t1, $t2
	li $v0, 10
	syscall