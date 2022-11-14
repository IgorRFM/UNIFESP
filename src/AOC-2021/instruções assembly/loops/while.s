#start .text segment
	.text
	.globl main

main:
	li $t0, 0
    li $t1, 0

while:
    beq $t0, 11, exit
    add $t1, $t1, $t0
    addi $t0, $t0, 1
    j while

exit:
    li $v0, 10 #Adicionar 10 no registrador v0 encerra o programa
	syscall
