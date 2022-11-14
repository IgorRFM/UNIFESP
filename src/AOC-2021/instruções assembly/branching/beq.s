#start .text segment
	.text
	.globl main

main:
	li $t1, 3
    li $t2, 3
    
    beq $t1,$t2, end
    addi $t1, $t1, 1
    
end:
    li $v0, 10 #Adicionar 10 no registrador v0 encerra o programa
	syscall
