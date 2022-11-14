#start .text segment
	.text
	.globl main

main:
	li $t2, 0x01
    li $t8, 0x10010010   
    lw $t3, value

    add $t4,$t2,$t3
    sw		$t5, 0($t8)		# 
    
    
	
	li $v0, 10 #Adicionar 10 no registrador v0 encerra o programa
	syscall

    value: .word 0x01