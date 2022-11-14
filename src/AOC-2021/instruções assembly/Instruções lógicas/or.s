#start .text segment
	.text
	.globl main

main:
	li $t1, 0
	li $t2, 0
	or $t0, $t1, $t2
    li $t4, 1
	li $t5, 0
	or $t3, $t4, $t5

	li $v0, 10 #Adicionar 10 no registrador v0 encerra o programa
	syscall