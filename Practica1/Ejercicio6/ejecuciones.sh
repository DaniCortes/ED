#!/bin/bash

inicio=100
fin=30100
incremento=500

i=$inicio
while [ $i -le $fin ]; 
do
	echo Ejecución tam = $i
	./ordenacion_optimizada $i 10000 >> tiempos_optimizados.dat
	i=`expr $i + $incremento`
done
