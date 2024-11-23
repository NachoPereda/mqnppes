#!/bin/bash

# Verifica que se haya pasado un argumento
if [ -z "$1" ]; then
    echo "Debe proporcionar el nombre de un fichero de entrada"
    exit 1
fi

# Verifica que el fichero de entrada existe
if [ ! -f "$1" ]; then
    echo "El fichero $1 no existe"
    exit 1
fi

# Nombre del fichero de entrada
input_file=$1

# Contador para los ficheros de salida
counter=1

# Lee el fichero línea por línea
while IFS= read -r line
do
    # Escribe cada línea en un fichero separado
    echo "$line" > "outputcoef_$counter.txt"
    counter=$((counter + 1))
done < "$input_file"

echo "Se han creado $((counter - 1)) ficheros de salida."
