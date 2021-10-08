#include <fstream>
#include <iostream>
#include "cronologia_stl.h"

using namespace std;

int main(int argc, char* argv[]) {
  if (argc != 2) {
    cout << "Dime el nombre del fichero con la cronología\n";
    return 0;
  }

  ifstream f(argv[1]);
  if (!f) {
    cout << "No puedo abrir el fichero " << argv[1] << endl;
    return 0;
  }

  int anio = 0;
  Cronologia mi_cronologia;
  f >> mi_cronologia;  // Cargamos en memoria la cronología.

  cout << "--------------------------------------------------------------------"
          "------------------\n\n";
  cout << "Número total de años: " << mi_cronologia.size() << endl;
  cout << "Número total de eventos: " << mi_cronologia.getTotalEventos()
       << endl;
  cout << "Número máximo de eventos en un año: "
       << mi_cronologia.getMaxEventosEnFechaHistorica(anio) << " eventos en "
       << anio << endl;
  cout << "Número promedio de acontecimientos por año: "
       << mi_cronologia.getPromedioEventos() << endl
       << endl;

  return 0;
}