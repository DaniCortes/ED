#!/bin/bash

mejor_caso=$1
inicio=100
fin=30100
incremento=500

i=$inicio
while [ $i -le $fin ]; 
do
	echo Ejecución tam = $i
	if [ $mejor_caso -eq 1 ]
	then
		./ordenacion $i 10000 $mejor_caso >> mejor_caso.dat
	else 
		./ordenacion $i 10000 $mejor_caso >> peor_caso.dat
	fi

	i=`expr $i + $incremento`
done
