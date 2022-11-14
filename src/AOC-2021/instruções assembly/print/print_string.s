#start .text segment
	.text
	.globl main

main:
	li $v0, 4
    la $a0, msg
    syscall
    li $v0, 10 #Adicionar 10 no registrador v0 encerra o programa
	syscall

    .data
msg: .asciiz "Hello World!\n"   