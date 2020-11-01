#include <cstring>
#include <iostream>
#include <string>

#include "fechahistorica.h"

using namespace std;

FechaHistorica::FechaHistorica() {
   //To-do ...
}

FechaHistorica::FechaHistorica(const FechaHistorica &f) {
   //To-do ...
}

FechaHistorica &FechaHistorica::operator=(const FechaHistorica &f) {
   //To-do ...
}

// Implementar el resto de métodos ...

ostream &operator<<(std::ostream &os, const FechaHistorica &f) {
   //Completar ...
}

// Este método se proporciona a medio hacer para facilitar la lectura de una FechaHistorica a partir de un fichero
istream &operator>>(std::istream &is, FechaHistorica &f) {
   string s;

   getline(is, s, '#');

   int anio = stoi(s);
   cout << "\tLeido año: " << anio << endl;
   //To-do: guarda anio dentro del objeto f

   while (!is.eof()) {
      s = "";
      getline(is, s, '#');
      cout << "\t\tLeido evento: " << s << endl;
      //s contiene un string con el texto de un evento
      //To-do: Guarda la cadena s dentro del objeto f
      // ...
   }

   return is;
}
