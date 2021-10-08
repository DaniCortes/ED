#include <fstream>
#include <iostream>
#include "cronologia_stl.h"

using namespace std;

int main(int argc, char* argv[]) {
  if (argc < 3 || argc > 5) {
    cout << "Dime el nombre del fichero con la cronología y el intervalo de "
            "años o un único año\n";
    return 0;
  }

  ifstream f(argv[1]);
  if (!f) {
    cout << "No puedo abrir el fichero " << argv[1] << endl;
    return 0;
  }

  Cronologia mi_cronologia;
  f >> mi_cronologia;  // Cargamos en memoria la cronología.

  cout << "--------------------------------------------------------------------"
          "------------------\n\n";
  if (argc == 3) {
    cout << "FechaHistorica con los eventos de " << argv[2] << ":" << endl;
    cout << mi_cronologia.ObtenerEventos(stoi(argv[2]));
  } else {
    cout << "Cronología con los eventos entre " << argv[2] << " y " << argv[3]
         << ":" << endl;
    cout << mi_cronologia.ObtenerEventos(stoi(argv[2]), stoi(argv[3]));
  }

  return 0;
}