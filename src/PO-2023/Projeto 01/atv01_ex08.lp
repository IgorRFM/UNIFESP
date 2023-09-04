Minimize
z: 8.5 minerio1 + 6 minerio2 + 8.9 minerio3 + 5.7 minerio4 + 8.8 minerio5

Subject To
qtde_minerio1: 0.3 minerio1 + 0.1 minerio2 + 0.5 minerio3 + 0.1 minerio4 + 0.5 minerio5 >= 0.3
qtde_minerio2: 0.6 minerio1 + 0.2 minerio2 + 0.2 minerio3 + 0.1 minerio4 + 0.1 minerio5 >= 0.2
qtde_minerio3: 0.1 minerio1 + 0.7 minerio2 + 0.3 minerio3 + 0.8 minerio4 + 0.4 minerio5 >= 0.5

Bounds
minerio1 >= 0
minerio2 >= 0
minerio3 >= 0
minerio4 >= 0
minerio5 >= 0

end