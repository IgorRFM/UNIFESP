#start .text segment
	.text
	.globl main

main:
	li $t2, 1
    move $t1, $t2    
	
	li $v0, 10 #Adicionar 10 no registrador v0 encerra o programa
	syscall

    value: .word 0x01