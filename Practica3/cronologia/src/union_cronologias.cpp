#include <fstream>
#include <iostream>
#include "cronologia_stl.h"

using namespace std;

int main(int argc, char* argv[]) {
  if (argc != 3) {
    cout << "Dime los nombres de los ficheros con las cronologías\n";
    return 0;
  }

  ifstream f(argv[1]);
  if (!f) {
    cout << "No puedo abrir el fichero " << argv[1] << endl;
    return 0;
  }

  ifstream g(argv[2]);
  if (!f) {
    cout << "No puedo abrir el fichero " << argv[2] << endl;
    return 0;
  }

  Cronologia mi_cronologia1, mi_cronologia2, mi_cronologia3;
  f >> mi_cronologia1;  // Cargamos en memoria la cronología.
  g >> mi_cronologia2;

  cout << "--------------------------------------------------------------------"
          "------------------\n\n";
  cout << "Suma de las cronologías mi_cronologia1 y mi_cronologia2:\n";
  cout << mi_cronologia1 + mi_cronologia2;

  return 0;
}