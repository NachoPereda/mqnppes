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


# Contar el número de ficheros de coeficientes en el directorio actual
# num_files=$(ls coef/coef*.txt 2> /dev/null | wc -l)

# Verifica si hay al menos un fichero de coeficientes
# if [ "$num_files" -lt 1 ]; then
#     echo "No se encontraron ficheros coef*.txt"
#     exit 1
# fi
# Iniciar la medición de tiempo total
start_time=$(date +%s)

./run_coefgen.sh $n
./run_script.sh $n

# Ejecuta el programa simulate para cada fichero de coeficientes
for ((i=1; i<=m; i++))
do
    coef_file="out_n_$n/coef_${i}.txt"
    output_matrix_file="out_n_$n/outputmatrix_${i}.txt"
    output_main_file="out_n_$n/outputmain${i}.txt"

    if [ -f "$coef_file" ]; then
        ./simulate "$output_matrix_file" "$coef_file" # > "$output_main_file"
        echo "Ejecución $i: ./simulate $output_matrix_file $coef_file "#> $output_main_file"
    else
        echo "El fichero $coef_file no existe"
    fi
done

# Finalizar la medición de tiempo total
end_time=$(date +%s)
elapsed_time=$(( end_time - start_time ))

echo "Se realizaron $num_files ejecuciones."
echo "Tiempo total de ejecución: $elapsed_time segundos."
