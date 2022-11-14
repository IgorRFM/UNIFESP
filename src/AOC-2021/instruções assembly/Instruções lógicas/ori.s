#start .text segment
	.text
	.globl main

main:
	li $t1, 1
	ori $t0, $t1, 0
	li $v0, 10 #Adicionar 10 no registrador v0 encerra o programa
	syscall