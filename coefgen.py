import hashlib
import math
import sys

def calcular_bits(texto, n):
    # Aplicar la función hash SHA256 al texto
    hash_resultado = hashlib.sha256(texto.encode()).digest()

    # Convertir el hash en una cadena binaria
    bits_hash = ''.join(format(byte, '08b') for byte in hash_resultado)

    # Calcular la cantidad de bits a extraer
    cantidad_bits_total = int((n-8)*((n*(n+1)/2) + n + 1))
    cantidad_bits_por_variable = int(((n*(n+1)/2) + n + 1))

    # Extraer los bits requeridos
    bits_extraidos = bits_hash[:cantidad_bits_total]
    #print("Bits extraídos:", bits_extraidos, " Cantidad de bits:", cantidad_bits_total)

    # Dividir los bits extraídos en (n-8) variables
    variables_divididas = []
    for i in range(1):
        inicio = i * cantidad_bits_por_variable
        fin = inicio + cantidad_bits_por_variable
        variables_divididas.append(bits_extraidos[inicio:fin])

    return variables_divididas

def read_file(filename):
    try:
        with open(filename, 'r') as file:
            content = file.read()
            print("Contenido del archivo:")
            print(content)
    except FileNotFoundError:
        print(f"Error: El archivo '{filename}' no se encontró.")

def main():
    if len(sys.argv) != 3:
        print("Uso: python script.py <nombre_archivo_texto> <valor_de_n>")
        return
    
    filename = sys.argv[1]
    n = int(sys.argv[2])

    try:
        with open(filename, 'r') as file:
            texto_ejemplo = file.read().strip()  # Leer el contenido del archivo y quitar espacios en blanco al inicio y al final
    except FileNotFoundError:
        print(f"Error: El archivo '{filename}' no se encontró.")
        return

    # texto_ejemplo = "HOLA" #input("Introduce el texto de ejemplo: ")
    # n = int(16) #int(input("Introduce el valor de n: "))

    variables = calcular_bits(texto_ejemplo, n)
    
    for i, variable in enumerate(variables):
        print(variable)

if __name__ == "__main__":
    main()
