#include "fechahistorica.h"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char * argv[]){

  FechaHistorica f1; 
  FechaHistorica f2;

  ifstream f ("../datos/fh1.txt");
  if (!f){
    cout<<"No puedo abrir el fichero ../datos/fh1.txt"<<endl;
    return 0;
  }
   
  f>>f1; //Leemos la fecha histórica del fichero.
   

   /* Exhibir aquí la funcionalidad programada para el TDA FechaHistorica */ 

   // Algunas sugerencias: 
   // - Obtener el año de una FechaHistorica
   // - Obtener los eventos de una FechaHistorica
   // - Comparar dos FechaHistorica (operator<)
   // - "Unir" o "sumar" dos FechaHistorica (operator+) -- sólo si tienen el mismo año.
   // - Cualquier otra funcionalidad que consideréis de interés


}
