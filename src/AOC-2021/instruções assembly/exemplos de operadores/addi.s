#start .text segment
	.text
	.globl main

main:
	li $t0, 0x25
	addi $t2, $t0, 0x300
	li $v0, 10
	syscall