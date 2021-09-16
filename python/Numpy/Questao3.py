'''
Nome: João Carlos Rodrigues Franco
Matricula: 87
Curso: GES
'''
from sympy import Integral, Symbol

c = 87%10

def areaFunc(x):
  return x**3 - 4*x**2 + 5*x - c

x = Symbol('x')
area = Integral(areaFunc(x),(x,0,5)).doit()
print(f'A area sob a curva x^3 - 4x^2 + 5x + c entre os valores 0 e 5:{area}' )
