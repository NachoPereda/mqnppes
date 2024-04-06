import hashlib
import math

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
    print("Bits extraídos:", bits_extraidos, " Cantidad de bits:", cantidad_bits_total)

    # Dividir los bits extraídos en (n-8) variables
    variables_divididas = []
    for i in range(n - 8):
        inicio = i * cantidad_bits_por_variable
        fin = inicio + cantidad_bits_por_variable
        variables_divididas.append(bits_extraidos[inicio:fin])

    return variables_divididas

def main():
    texto_ejemplo = "HOLA" #input("Introduce el texto de ejemplo: ")
    n = int(9) #int(input("Introduce el valor de n: "))

    variables = calcular_bits(texto_ejemplo, n)
    
    for i, variable in enumerate(variables):
        print(f"Variable {i+1}: {variable}")

if __name__ == "__main__":
    main()
