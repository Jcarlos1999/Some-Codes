'''
Nome: João Carlos Rodrigues Franco
Matricula: 87
Curso: GES
'''
import numpy as np

c = 87%10

v1 = 10 + (2*c)
v2 = 5 + (2*c)
R1 = 25
R2 = 10
R3 = 20

'''
malha 1 = V1, R1 = 25, R2 = 10
malha 2 = V2, R3 = 20, R2 = 10

i4 = i1 - i2
i5 = i3 - i2

v1 + R1*i4 - R2*i4 - R2*i5 = 0 -> v1 = i4(-R1 + R2) + i5*R2
v2 + R3*i5 - R2*i5 - R2*i4 = 0 -> v2 = i4*-R2 + i5(R2 - R3)

'''

A = np.matrix([
            [v1],
            [v2],
])

print(f'Matriz A: {A}\n')

B = np.matrix([
            [-R1 + R2, R2],
            [-R3 + R2, R2]
])

print(f'Matriz B: {B}\n')

B_inv = np.linalg.inv(B)

X = B_inv * A

print(f'Matriz X: {X}')

i4 = X[0]
i5 = X[1]

print(f'i4 = {i4}\n')
print(f'i5 = {i5}\n')

'''

'''
V_r1 = R1*i4
V_r3 = R3*i5

print(f'V em R1 = {V_r1}\n')
print(f'V em R3 = {V_r3}\n')

i1 = V_r1 / R1
i3 = V_r3 / R3
i2 = i1 + i3

print(f'Valor de i1 = {i1}')
print(f'Valor de i2 = {i2}')
print(f'Valor de i3 = {i3}')

