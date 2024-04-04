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

def to_matrix(n, rmqe):
    filas = n + 3
    columnas = n * 3
    matriz = [['$'] * columnas for _ in range(filas)]
    fil = 0
    col = 0
    terms = re.split(r'\s*\+\s*', rmqe)

    # Convertir cada término en una lista de factores
    term_list = []
    for term in terms:
        factors = re.split(r'\s*\*\s*', term)
        term_list.append(factors)

    # Insertar los términos en la matriz
    for factors in term_list:
        for factor in factors:
            print(fil, n)
            if col == columnas:
                fil += 1
                if fil == n:
                    col = 0
                else:
                    col = 3 * fil
            else:
                if fil == n:
                    if (col + 1) % (3) == 0:
                        col += 1
                        if col == columnas:
                            fil += 1
                            col = 0
                if fil == n + 1:
                    matriz[fil][columnas - 1] = 's_k'
                    matriz[fil + 1][0] = 'c0'
                if fil == n + 2:
                    matriz[fil][0] = 'c0'
                matriz[fil][col] = [factor]  # Guardar factor como lista
                col += 1

    # Insertar coeficientes c en la última fila
    for i in range(n):
        matriz[filas - 1][((i + 1) * 3) - 1] = ['c' + str(i + 1)]

    return matriz


def to_matriXx(n, rmqe):
    filas = n + 3
    columnas = n * 3
    matriz = [["$" for _ in range(columnas)] for _ in range(filas)]
    fil = 0
    col = 0

    term_regex = re.compile(r'\s*\+\s*')
    factor_regex = re.compile(r'\s*\*\s*')
    terms = re.split(term_regex, rmqe)

    for term in terms:
        factors = re.split(factor_regex, term)

        for factor in factors:
            if col == columnas:
                fil += 1
                col = 0 if fil == n else 3 * fil

            if fil == n:
                if (col + 1) % 3 == 0:
                    col += 1
                    if col == columnas:
                        fil += 1
                        col = 0

            if fil == n + 1:
                matriz[fil][columnas - 1] = "s_k"
                matriz[fil + 1][0] = "c0"

            if fil == n + 2:
                matriz[fil][0] = "c0"

            matriz[fil][col] = factor
            col += 1

    for i in range(n):
        matriz[filas - 1][(i + 1) * 3 - 1] = "c" + str(i + 1)

    return matriz


def main():
    # Get user input for n and m
    # n = int(input("Enter the value for n: "))
    # m = int(input("Enter the value for m: "))
    n=9
    m=1

    # Generate and print the rmqe formula
    rmqe_formula = generate_rmqe_formula(n, m)
    # print(f'rmqe = {rmqe_formula}')
    # Generate picture from rqme
    matrix = to_matriXx(n,rmqe_formula)
    # print("Picture:")
    for fila in matrix:
        print(fila)
    # print(tabulate(matrix, tablefmt="fancy_grid"))
    
    

if __name__ == "__main__":
    main()
