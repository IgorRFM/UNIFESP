Minimize
z: t1 + t2 + t3 + t4 + t5 + t6

Subject To
turno1_6: t1 + t6 >= 4
turno1_2: t1 + t2 >= 8
turno2_3: t2 + t3 >= 10
turno3_4: t3 + t4 >= 7
turno4_5: t4 + t5 >= 12
turno5_6: t5 + t6 >= 4

Bounds
t1 >= 0
t2 >= 0
t3 >= 0
t4 >= 0
t5 >= 0
t6 >= 0

end