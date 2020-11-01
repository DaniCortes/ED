#include "funciones_matrices.h"

using namespace std;

void sintaxis() {
   cerr << "Sintaxis:" << endl;
   cerr << "  TAM: Tamaño de la matriz (>0)" << endl;
   cerr << "Se generan dos matrices de tamaño TAM*TAM con elementos aleatorios en [0,    VMAX[" << endl;
   exit(EXIT_FAILURE);
}

void reservarMatrices(float **&m, int filas, int columnas) {
   m = new float *[filas];

   for (int i = 0; i < filas; i++) {
      m[i] = new float[columnas];
   }
}

void rellenarMatrices(float **m, int filas, int columnas, int valor_max) {
   srand(time(0));

   for (int i = 0; i < filas; i++) {
      for (int j = 0; i < columnas; i++) {
         m[i][j] = rand() % valor_max;
      }
   }
}

void productoMatrices(float **m1, float **m2, float **resultado, const int filas1, const int columnas1, const int columnas2) {
   for (int i = 0; i < filas1; i++) {
      for (int j = 0; j < columnas2; j++) {
         for (int k = 0; k < columnas1; k++) {
            resultado[i][j] += m1[i][k] * m2[k][j];
         }
      }
   }
}

void liberarMatriz(float **&m, int filas) {
   for (int i = 0; i < filas; i++) {
      delete[] m[i];
   }
   delete[] m;
}
