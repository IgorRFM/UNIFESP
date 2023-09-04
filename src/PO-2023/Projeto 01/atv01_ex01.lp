Minimize
z: 30 x1 + 48 x2 + 44 x3 + 56 x4

Subject To
qtde: x1 + x2 + x3 + x4 = 10000
prot: 0.069 x1 + 0.085 x2 + 0.09 x3 + 0.271 x4 = 1500
fibra: 0.06 x1 + 0.11 x2 + 0.11 x3 + 0.11 x4 >= 800
mincal: 1760 x1 + 1700 x2 + 1056 x3 + 1400 x4 >= 11000000
maxcal: 1760 x1 + 1700 x2 + 1056 x3 + 1400 x4 <= 22500000
soja: x3 <= 1200
proteina: x4 >= 2000

Bounds
x1 >= 0
x2 >= 0
x3 >= 0
x4 >= 0
x3 >= 0

end