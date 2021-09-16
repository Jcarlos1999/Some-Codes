'''
Nome: João Carlos Rodrigues Franco
Matricula: 87
Curso: GES
'''
from sympy import exp, sin, Symbol, solve

c = 87%10

def eq1(x):
  return exp(x - 3) + exp(x - 1) + exp(x) - (c + 1)

def eq2(x):
  return x**4 - 4*x**3 + 3*x + (-c)

def eq3(x):
  return 4*sin((c+1)*x) + 2

x = Symbol('x')

y1 = eq1(x)
y2 = eq2(x)
y3 = eq3(x)

print(f'Resultado equação 1: {solve(y1)}\n')
print(f'Resultado equação 2: {solve(y2)}\n')
print(f'Resultado equação 3: {solve(y3)}\n')