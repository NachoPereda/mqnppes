#!/bin/bash

# Verifica que se haya pasado un argumento
if [ -z "$1" ]; then
    echo "Debe proporcionar un valor para n"
    exit 1
fi

# Verifica que el argumento sea un número
if ! [[ "$1" =~ ^[0-9]+$ ]]; then
    echo "El argumento debe ser un número"
    exit 1
fi

# Asigna el valor de m
n=$1
m=$((n-8))

# Verifica si m es mayor o igual a 2
if [ "$m" -ge 1 ]; then
    # Llama al fichero Python m veces y guarda la salida en ficheros distintos
    for ((i=1; i<=m; i++))
    do
        python3 rqmemat.py $n > "out_n_$n/outputmatrix_$i.txt"
    done
else
    echo "El valor de m debe ser 2 o mayor"
    exit 1
fi
