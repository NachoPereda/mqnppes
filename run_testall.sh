#!/bin/bash


# Ejecuta el programa simulate para cada fichero de coeficientes
for ((i=16; i<=20; i++))
do
    mkdir "out_n_$i"
    
    ./run_network.sh $i
done

