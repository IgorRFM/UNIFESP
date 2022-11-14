#start .text segment
	.text
	.globl main

main:
	li $t1, 2
    li $t2, 3
    
    slti $t3, $t1, 100 #se t1<t2, t3 vira 1
	slti $t4, $t2, 2 #se t1<t2, t4 vira 1

	li $v0, 10 #Adicionar 10 no registrador v0 encerra o programa
	syscall

    value: .word 0x01