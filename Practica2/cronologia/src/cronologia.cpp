#include "cronologia.h"

using namespace std;

Cronologia::Cronologia() {}

Cronologia::~Cronologia() {}

Cronologia::Cronologia(const Cronologia& c) {
   fechas_historicas = c.fechas_historicas;
}

Cronologia& Cronologia::operator=(const Cronologia& c) {
   fechas_historicas = c.fechas_historicas;
   return *this;
}

FechaHistorica Cronologia::ObtenerEventos(int anio) {
   int i = 0;
   FechaHistorica tmp;
   while ((tmp = fechas_historicas.get(i)).anio <= anio) {
      if (tmp.anio == anio) {
         return tmp;
      }
      i++;
   }
   tmp.anio = anio;
   tmp.eventos.add("No hay ningún evento");
   return tmp;
}

Cronologia Cronologia::ObtenerEventos(int anioDesde, int anioHasta) {
   int i = 0;
   Cronologia cr_tmp;
   while(fechas_historicas.get(i).anio < anioDesde) i++;
   while((fechas_historicas.get(i).anio >= anioDesde) && (fechas_historicas.get(i).anio <= anioHasta)) {
      cr_tmp.fechas_historicas.add(fechas_historicas.get(i));
      i++;
   }
   return cr_tmp;
}

bool Cronologia::operator==(const Cronologia& c) {
   return (fechas_historicas == c.fechas_historicas) ? true : false;
}

bool Cronologia::operator!=(const Cronologia& c) {
   return !(*this == c);
}

// Completar la implementación...

ostream& operator<<(std::ostream& os, const Cronologia& c) {

   for (int i = 0; i < c.fechas_historicas.getNumDatos(); i++) {
      os << c.fechas_historicas.get(i);
   }
   return os;
}

// Este método se proporciona a medio hacer para facilitar la lectura de una Cronologia a partir de un fichero

istream& operator>>(istream& is, Cronologia& c) {
   cout << "Leyendo cronología ..." << endl;

   int fh_leidas = 0;

   string s;

   while (getline(is, s)) {
      istringstream ss(s);
      FechaHistorica aux;
      cout << "Leyendo FechaHistorica número: " << fh_leidas << endl;
      ss >> aux;
      c.fechas_historicas.add(aux);
      fh_leidas++;
   }

   return is;
}