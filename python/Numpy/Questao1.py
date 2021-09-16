'''
Nome: João Carlos Rodrigues Franco
Matricula: 87
Curso: GES
'''
from sympy import Limit, Symbol, S
c = (87%10)

def func(x):
  return ((3 * x**3 - 3)/(4 * x**2 - 4)) * (c + 1)

x = Symbol('x')
result = Limit(func(x),x, 1).doit()
print(f'Resultado da função para x->1: {result}\n')

result = Limit(func(x),x, S.Infinity).doit()
print(f'Resultado da função para x->oo: {result}\n')

result = Limit(func(x),x, -S.Infinity).doit()
print(f'Resultado da função para x--oo: {result}\n')

