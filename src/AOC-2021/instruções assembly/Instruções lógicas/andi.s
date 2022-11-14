#start .text segment
	.text
	.globl main

main:
	li $t1, 1
	andi $t0, $t1, 1
	li $v0, 10 #Adicionar 10 no registrador v0 encerra o programa
	syscall