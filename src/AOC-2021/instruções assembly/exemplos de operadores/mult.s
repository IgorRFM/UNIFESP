#start .text segment
	.text
	.globl main

main:
	li $t1, 25
	li $t2, 10
	#A diferença do mul, é que o resultado vai pra $lo,$high
	mult $t1, $t2
	li $v0, 10
	syscall