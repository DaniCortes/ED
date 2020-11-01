#include <cstdlib>
#include <ctime>
#include <iostream>

void sintaxis();

void reservarMatrices(float **&m, int filas, int columnas);

void rellenarMatrices(float **m, int filas, int columnas, int valor_max);

void productoMatrices(float **m1, float **m2, float **resultado, const int filas1, const int columnas1, const int columnas2);

void liberarMatriz(float **&m, int filas);