#start .text segment
	.text
	.globl main

main:
	li $t1, 25
	li $t2, 10
	mul $t0, $t1, $t2
	li $v0, 10
	syscall