#start .text segment
	.text
	.globl main

main:
	li $t1, 2
    li $t2, 3
    
    slt $t3, $t1, $t2 #se t1<t2, t3 vira 1
	slt $t4, $t2, $t1 #se t2<t1, t4 vira 1
	li $v0, 10 #Adicionar 10 no registrador v0 encerra o programa
	syscall

    value: .word 0x01