#include <iostream>
#include <sstream>
#include <string>

#include "cronologia.h"

using namespace std;

Cronologia::Cronologia() {}

Cronologia::Cronologia(const Cronologia& c) {
   //To-do ...
}

Cronologia& Cronologia::operator=(const Cronologia& c) {
   //To-do ...
}

// Completar la implementación...

// Este método se proporciona a medio hacer para facilitar la lectura de una Cronologia a partir de un fichero
istream& operator>>(istream& flujo, Cronologia& c) {
   cout << "Leyendo cronología ..." << endl;

   int fh_leidas = 0;

   string s;
   getline(flujo, s, '\n');

   while (flujo.eof() == 0) {
      istringstream ss(s);
      FechaHistorica aux;
      cout << "Leyendo FechaHistorica número: " << fh_leidas << endl;
      ss >> aux;
      //Aquí aux es una FechaHistorica que ya contiene la información de esa linea del fichero
      //To-do: guarda la FechaHistorica aux dentro de la cronologia c
      // ...
      fh_leidas++;
      s = "";
      getline(flujo, s, '\n');
   }

   return flujo;
}
