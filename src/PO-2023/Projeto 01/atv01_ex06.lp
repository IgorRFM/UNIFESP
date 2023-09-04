Maximize
z: s5 + 1.4 a4 + 1.7 b3 + 2 c2 + 1.3 d5

Subject To
ano1: a1 + b1 + s1 = 10000
ano2: a2 + b2 + c2 + s2 -s1 = 0
ano3: a3 + b3 + s3 -s2 - 1.4 a1 = 0
ano4: a4 + s4 - s3 - 1.4 a2 - 1.7 b1 = 0
ano5: d5 + s5 - s4 - 1.4 a3 - 1.7 b2 = 0

Bounds
a1 >= 0
a2 >= 0
a3 >= 0
a4 >= 0
b1 >= 0
b2 >= 0
b3 >= 0
c2 >= 0
d5 >= 0
s1 >= 0
s2 >= 0
s3 >= 0
s4 >= 0
s5 >= 0

end
