#include <fstream>
#include <iostream>
#include "fechahistorica.h"

using namespace std;

int main(int argc, char* argv[]) {
  FechaHistorica f1;
  FechaHistorica f2;
  FechaHistorica f3;

  ifstream f("datos/fh1.txt");
  if (!f) {
    cout << "No puedo abrir el fichero ../datos/fh1.txt" << endl;
    return 0;
  }

  ifstream g("datos/fh2.txt");
  if (!g) {
    cout << "No puedo abrir el fichero ../datos/fh2.txt" << endl;
    return 0;
  }

  f >> f1;  // Leemos la fecha histórica del fichero.
  g >> f2;

  f3 = f2 + f1;

  cout << f3;
  cout << f3.getAnio() << endl;
  cout << f3;

  /* Exhibir aquí la funcionalidad programada para el TDA FechaHistorica */

  // Algunas sugerencias:
  // - Obtener el año de una FechaHistorica
  // - Obtener los eventos de una FechaHistorica
  // - Comparar dos FechaHistorica (operator<)
  // - "Unir" o "sumar" dos FechaHistorica (operator+) -- sólo si tienen el
  // mismo año.
  // - Cualquier otra funcionalidad que consideréis de interés
}
