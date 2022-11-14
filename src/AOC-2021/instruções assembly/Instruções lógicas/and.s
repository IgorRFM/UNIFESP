#start .text segment
	.text
	.globl main

main:
	li $t1, 1
	li $t2, 1
	and $t0, $t1, $t2
    li $t4, 1
	li $t5, 0
	and $t3, $t4, $t5

	li $v0, 10 #Adicionar 10 no registrador v0 encerra o programa
	syscall