#include <fstream>
#include <iostream>
#include "cronologia_stl.h"

using namespace std;

int main(int argc, char* argv[]) {
  if (argc != 3) {
    cout << "Dime el nombre del fichero con la cronología y la palabra clave\n";
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
  cout << "Cronología con los eventos con la palabra clave \"" << argv[2]
       << "\":" << endl;
  cout << mi_cronologia.getFechasPalabraClave(argv[2]);

  return 0;
}