#!/bin/bash

inicio=2
fin=800
incremento=1

i=$inicio
while [ $i -le $fin ]; 
do
	echo Ejecución tam = $i
	./ejercicio7 $i 500 >> tiempos.dat
	i=`expr $i + $incremento`
done
