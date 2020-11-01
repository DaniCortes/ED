#!/bin/bash

inicio=1000
fin=500000
incremento=1000

i=$inicio
echo > tiempos.dat
while [ $i -le $fin ]; 
do
	echo Ejecución tam = $i
	./ejercicio_desc $i >> tiempos.dat
	i=`expr $i + $incremento`
done
