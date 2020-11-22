#include <fstream>
#include <iostream>
#include "cronologia.h"

using namespace std;

int main(int argc, char* argv[]) {
   if (argc != 3) {
      cout << "Dime los nombres de los ficheros con las cronologias" << endl;
      return 0;
   }

   ifstream f(argv[1]);
   if (!f) {
      cout << "No puedo abrir el fichero " << argv[1] << endl;
      return 0;
   }

   ifstream g(argv[2]);
   if (!f) {
      cout << "No puedo abrir el fichero " << argv[1] << endl;
      return 0;
   }

   Cronologia mi_cronologia1, mi_cronologia2;
   f >> mi_cronologia1;   //Cargamos en memoria la cronología.
   g >> mi_cronologia2;

   //cout << mi_cronologia1.ObtenerEventos(1900, 1930) << endl;

  cout << mi_cronologia1;

   /* Exhibir aquí la funcionalidad programada para el TDA Cronologia / TDA FechaHistorica */

   // Algunas sugerencias:
   // - Obtener los eventos acaecidos en un año dado
   // - Obtener la (sub)cronología de eventos históricos acaecidos en [anioDesde, anioHasta], donde anioDesde y anioHasta son proporcionados por el usuario
   // - Obtener la (sub)cronología de eventos históricos asociados a una palabra clave. Ejemplo: la cronología de eventos asociados a "Einstein"
   // - Operadores sobre cronologías, ejemplo: Unión de dos cronologías (la cronología resultante debería estar ordenada)
   // - Cualquier otra funcionalidad que consideréis de interés
}
