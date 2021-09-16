'''
Nome: João Carlos Rodrigues Franco
Matricula: 87
Curso: GES
'''
from sympy import Derivative, Symbol

c = 87%10

def spaceFunc(t):
  return (-t**3/3) + 2*t**2 - c

t = Symbol('t')
speedFunc = Derivative(spaceFunc(t),t).doit()
print(f'Equação da Velocidade: {speedFunc}')

speedResult = Derivative(spaceFunc(t),t).doit().subs({t:3})
print(f'Resultado da equação da velocidade para t=3: {speedResult}\n')

print('--------------------------------------------')

accelerationFunc = Derivative(spaceFunc(t),t,2).doit()
print(f'Equação da aceleração: {accelerationFunc}\n')

accelerationResult = Derivative(spaceFunc(t),t,2).doit().subs({t:5})
print(f'Resultado da equação da aceleração para t=5: {accelerationResult}\n')