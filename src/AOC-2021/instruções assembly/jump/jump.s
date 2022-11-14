#start .text segment
	.text
	.globl main

main:
	li $t1, 3
    li $t2, 3

    j jump_aqui
    
jump_aqui:
    li $t3, 6

end:
    li $v0, 10 #Adicionar 10 no registrador v0 encerra o programa
	syscall
