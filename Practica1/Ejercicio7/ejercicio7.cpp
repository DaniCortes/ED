#include "funciones_matrices.h"

using namespace std;


int main(int argc, char *argv[]) {
   if (argc != 3) {
      sintaxis();
   }

   int tam = atoi(argv[1]);   // Tamaño de las filas y columnas de las matrices
   int valor_max = atoi(argv[2]); // Valor máximo de las celdas de las matrices

   if (tam <= 0) {
      sintaxis();
   }

   int filas1 = tam,
       columnas1 = tam,
       filas2 = tam,
       columnas2 = tam;

   float **matriz_a,
         **matriz_b,
         **producto;

   reservarMatrices(matriz_a, filas1, columnas1);
   reservarMatrices(matriz_b, filas2, columnas2);
   reservarMatrices(producto, filas1, columnas2);

   rellenarMatrices(matriz_a, filas1, columnas1, valor_max);
   rellenarMatrices(matriz_b, filas2, columnas2, valor_max);
   rellenarMatrices(producto, filas1, columnas2, valor_max);

   clock_t tini;
   tini = clock();

   productoMatrices(matriz_a, matriz_b, producto, filas1, columnas1, columnas2);
   
   clock_t tfin;
   tfin = clock();

   liberarMatriz(matriz_a, filas1);
   liberarMatriz(matriz_b, filas2);
   liberarMatriz(producto, filas1);

   cout << tam << "\t" << (tfin - tini) / (double)CLOCKS_PER_SEC << endl;
}

