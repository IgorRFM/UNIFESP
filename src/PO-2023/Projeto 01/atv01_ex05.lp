Maximize
z: 12 x11 + 10 x12 + 9 x13 + 12 x21 + 10 x22 + 9 x23 + 12 x31 + 10 x32 + 9 x31

Subject To
capacidade_fabrica_1: x11 + x12 + x13 <= 500
capacidade_fabrica_2: x21 + x22 + x23 <= 600
capacidade_fabrica_3: x31 + x32 + x33 <= 300
estocagem_fabrica_1: 20 x11 + 15 x12 + 12 x13 <= 9000
estocagem_fabrica_2: 20 x21 + 15 x22 + 12 x23 <= 8000
estocagem_fabrica_3: 20 x31 + 15 x32 + 12 x33 <= 3500
venda_grande: x11 + x21 + x31 <= 600
venda_media: x12 + x22 + x32 <= 800
venda_pequena: x13 + x23 + x33 <= 500
ociosidade_iguais1_2: x11/500 + x12/500 + x13/500 - x21/600 - x22/600 - x23/600 = 0
ociosidade_iguais1_3: x11/500 + x12/500 + x13/500 - x31/300 - x32/300 - x33/300 = 0

Bounds
x11 >= 0
x12 >= 0
x13 >= 0
x21 >= 0
x22 >= 0
x23 >= 0
x31 >= 0
x32 >= 0
x33 >= 0

end
