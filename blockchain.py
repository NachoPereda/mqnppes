import hashlib
import math

def hash_function(text):
    # Aplica la función hash a un texto dado
    hashed_text = hashlib.sha256(text.encode()).hexdigest()
    return hashed_text

def generate_bitstring_size(n):
    # Genera el tamaño de la cadena de bits según la fórmula dada
    size = (((n * (n - 1)) / (2 + n) )+ 1)*(n-8)
    return size

def divide_bitstring(bitstring, n):
    # Convertir la cadena hexadecimal a binario
    binary_string = bin(int(bitstring, 16))[2:]
    
    # Calcular la longitud total de la cadena de bits
    bitstring_length = len(binary_string)
    
    # Calcular la longitud de cada subcadena en bits
    sub_bitstring_length = bitstring_length // n
    
    # Ajustar la longitud de cada subcadena para que sea un múltiplo de 4
    sub_bitstring_length -= sub_bitstring_length % 4
    
    # Dividir la cadena de bits en subcadenas de longitud específica
    sub_bitstrings = [binary_string[i:i + sub_bitstring_length] for i in range(0, bitstring_length, sub_bitstring_length)]
    
    return sub_bitstrings


def main():
    # Solicitar al usuario ingresar el valor de n
    n = int(input("Ingrese el valor de n: "))
    
    # Texto de ejemplo
    text = "Ejemplo de texto para aplicar la función hash."
    
    # Aplicar la función hash al texto
    hashed_text = hash_function(text)
    print("\nhashed text\n", hashed_text)
    
    # Obtener el tamaño de la cadena de bits
    bitstring_size = generate_bitstring_size(n)
    
    # Redondear hacia abajo el tamaño de la cadena de bits
    bitstring_size = math.floor(bitstring_size/4)
    print("\nsize\n", bitstring_size)
    
    # Truncar la cadena hash a la longitud deseada
    truncated_hashed_text = hashed_text[:bitstring_size]
    print("\nhashed text\n", truncated_hashed_text)
    
    # Guardar la cadena de bits truncada en un archivo
    with open("hashed_bitstring.txt", "w") as file:
        file.write(truncated_hashed_text)
    
    # Dividir la cadena de bits en subcadenas y guardarlas en un archivo
    sub_bitstrings = divide_bitstring(truncated_hashed_text, n)
    with open("sub_bitstrings.txt", "w") as file:
        for i, sub_bitstring in enumerate(sub_bitstrings):
            file.write(f"Subcadena {i + 1}: {sub_bitstring}\n")

if __name__ == "__main__":
    main()
