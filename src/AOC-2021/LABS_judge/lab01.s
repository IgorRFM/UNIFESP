#start .text segment
	.text
	.globl main

loop_mes:
    li $v0, 4 #print_string syscall code = 4
    la $a0, in_mes_msg
    syscall

    li $v0, 5 # ler teclado, syscall code = 5
    syscall
    move $t0, $v0

    slti $t1, $t0, 1 #se t0<1, t1 vira 1

    li $t4, 12
	slt $t2, $t4, $t0 #se 12<t0, t2 vira 1

    li $t3, 0
    or $t3, $t1, $t2 # se t1==1 OU t2==1, t3==1
    beq $t3, 1, erro_mes # se t3==1, vai pra erro_mes
    add $s0, $v0, $zero #s0 recebe o mês digitado

loop_dia:
    li $v0, 4 #print_string syscall code = 4
    la $a0, in_dia_msg
    syscall

    li $v0, 5 # ler teclado, syscall code = 5
    syscall
    move $t0, $v0

    slti $t1, $t0, 1 #se t0<1, t1 vira 1

    li $t4, 31
	slt $t2, $t4, $t0 #se 31<t0, t2 vira 1

    li $t3, 0
    or $t3, $t1, $t2 # se t1==1 OU t2==1, t3==1
    beq $t3, 1, erro_dia # se t3==1, vai pra erro_dia
    move $s1, $v0


loop_ano:
    li $v0, 4 #print_string syscall code = 4
    la $a0, in_ano_msg
    syscall

    li $v0, 5 # ler teclado, syscall code = 5
    syscall
    move $t0, $v0

    slti $t1, $t0, 1980 #se t0<1980, t1 vira 1

    li $t4, 2050
	slt $t2, $t4, $t0 #se 2050<t0, t2 vira 1

    li $t3, 0
    or $t3, $t1, $t2 # se t1==1 OU t2==1, t3==1
    beq $t3, 1, erro_ano
    move $s2, $v0

end:
    li $v0, 4 #print_string syscall code = 4
    la $a0, res_msg
    syscall

    li $v0, 1 #print_int syscall code = 1
    move $a0, $s0
    syscall

    li $v0, 4 #print_string syscall code = 4
    la $a0, barra_msg
    syscall
    
    li $v0, 1 #print_int syscall code = 1
    move $a0, $s1
    syscall

    li $v0, 4 #print_string syscall code = 4
    la $a0, barra_msg
    syscall

    li $v0, 1 #print_int syscall code = 1
    move $a0, $s2
    syscall

    li $v0, 10 #Adicionar 10 no registrador v0 encerra o programa
	syscall

erro_mes:
    li $v0, 4 #print_string syscall code = 4
    la $a0, err_mes_msg
    syscall
    j loop_mes

erro_dia:
    li $v0, 4 #print_string syscall code = 4
    la $a0, err_dia_msg
    syscall
    j loop_dia

erro_ano:
    li $v0, 4 #print_string syscall code = 4
    la $a0, err_ano_msg
    syscall
    j loop_ano

    .data
in_mes_msg: .asciiz "Entre com o mes (MM): "
err_mes_msg: .asciiz "Mes invalido.\n"
in_dia_msg: .asciiz "Entre com o dia (DD): "
err_dia_msg: .asciiz "Dia invalido.\n"
in_ano_msg: .asciiz "Entre com o ano (AAAA): "
err_ano_msg: .asciiz "Ano invalido.\n"
res_msg: .asciiz "Data atual: "
barra_msg: .asciiz "/"