import hashlib

def calcular_bits(texto, n):
    # Aplicar la función hash SHA256 al texto
    hash_resultado = hashlib.sha256(texto.encode()).digest()

    # Convertir el hash en una cadena binaria
    bits_hash = ''.join(format(byte, '08b') for byte in hash_resultado)

    # Calcular la cantidad de bits a extraer
    cantidad_bits = (n - 8) * ((n * (n - 1) // (2 + n)) + 1)

    # Extraer los bits requeridos
    bits_extraidos = bits_hash[:cantidad_bits]

    return bits_extraidos

def main():
    texto_ejemplo = input("Introduce el texto de ejemplo: ")
    n = int(input("Introduce el valor de n: "))

    bits = calcular_bits(texto_ejemplo, n)
    
    print("Bits extraídos:", bits)

if __name__ == "__main__":
    main()
