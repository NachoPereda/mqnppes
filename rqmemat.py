import numpy as np
from sympy import symbols, collect
import re
from tabulate import tabulate

def generate_rmqe_formula(n, m):
    rmqe_formula = ""

    for p in range(1, m+1):
        #rmqe_formula += f'('

        # Generate the xi * xj terms
        for i in range(1, n+1):
            for j in range(i, n+1):
                rmqe_formula += f'p({i},{j}) * x{i} * x{j} + '

        # Generate the xi terms
        for i in range(1, n+1):
            rmqe_formula += f'p({i}) * x{i} + '

        # Add the constant term p(m)0 and close the bracket
        rmqe_formula += f'p(0)'

        # Add the closing bracket for P(m) and a plus sign if not the last term
        if p != m:
            rmqe_formula += ') + '
        #else:
        #    rmqe_formula += ')'

    return rmqe_formula

def to_matrix(n,rmqe):
    filas = n + 3
    columnas = n * 3
    matriz = [['$'] * columnas for _ in range(filas)]
    fil=0
    col=0
    terms = re.split(r'\s*\+\s*', rmqe)

    # Imprimir los términos separados
    for term in terms:
        factors = re.split(r'\s*\*\s*', term)
        for factor in factors:
            if col == columnas:
               fil+=1
               if fil == n:
                  col=0
               else:
                  col=3*fil
            else:
                if fil == n:
                   if (col+1)%(3)==0:
                      col+=1
                      if col == columnas:
                        fil+=1
                        col=0
            if fil==n+1:
                matriz[fil][columnas-1]='s_k'
                matriz[fil+1][0]='c0'
            if fil==n+2:
               matriz[fil][0]='c0'
            matriz[fil][col]=factor
            col+=1

    for i in range(n):
        matriz[filas-1][((i+1)*3)-1]='c'+ str(i + 1)
            			   
    return matriz


def main():
    # Get user input for n and m
    n = int(input("Enter the value for n: "))
    m = int(input("Enter the value for m: "))

    # Generate and print the rmqe formula
    rmqe_formula = generate_rmqe_formula(n, m)
    print(f'rmqe = {rmqe_formula}')
    # Generate picture from rqme
    matrix = to_matrix(n,rmqe_formula)
    print("Picture:")
    for fila in matrix:
        print(fila)
    print(tabulate(matrix, tablefmt="fancy_grid"))
    indices_coeficientes = []

    for i, fila in enumerate(matrix):
        for j, elemento in enumerate(fila):
            if elemento.startswith('p('):
                indices_coeficientes.append((i, j))
    
    print("Índices de los coeficientes 'p':", indices_coeficientes)
    

if __name__ == "__main__":
    main()
