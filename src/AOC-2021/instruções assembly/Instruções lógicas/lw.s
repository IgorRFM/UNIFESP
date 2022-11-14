#start .text segment
	.text
	.globl main

main:
	li $t2, 10
    lw $t3, value
    add $t4,$t2,$t3
    
	
	li $v0, 10 #Adicionar 10 no registrador v0 encerra o programa
	syscall

    value: .word 20