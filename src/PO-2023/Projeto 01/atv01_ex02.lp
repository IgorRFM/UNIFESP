Minimize
z: 13 x01 + 25 x00 + 25 x11 + 16 x10 + 15 x21 + 40 x20

Subject To
bh: x01 + x00 <= 70
rp: x11 + x10 <= 130
sj: x21 + x20 <= 120
consumo_rj: x01 + x11 + x21 = 180
consumo_sp: x00 + x10 + x20 = 140

Bounds
x01 >= 0
x00 >= 0
x11 >= 0
x10 >= 0
x21 >= 0
x20 >= 0

end