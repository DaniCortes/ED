#include "utiles.h"

using namespace std;

string * split (string linea, char delim, int &size){
   stringstream flujo;
   string tmp;
   string *datos = nullptr;
   int i = 0;
   size = 0;

   flujo.str(linea);

   while (getline(flujo, tmp, delim)){
      i++;
   }

   datos = new string[i];
   size = i;
   i = 0;

   flujo.clear();
   flujo.str(linea);

   while (getline(flujo, tmp, delim)){
      datos[i] = tmp;
      i++;
   }

   return datos;
}