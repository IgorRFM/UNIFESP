#start .text segment
	.text
	.globl main

main:
	li $t1, 23
    li $t2, 10
    div $t1, $t2
    mfhi $t5
    mflo $t6
	
	li $v0, 10 #Adicionar 10 no registrador v0 encerra o programa
	syscall

    value: .word 0x01