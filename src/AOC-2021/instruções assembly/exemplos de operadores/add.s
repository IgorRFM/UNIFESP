#start .text segment
	.text
	.globl main

main:
	li $t0, 25
	li $t1, 10
	add $t2, $t0, $t1
	li $v0, 10 #Adicionar 10 no registrador v0 encerra o programa
	syscall