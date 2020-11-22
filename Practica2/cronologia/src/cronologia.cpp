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

void Cronologia::insertar(const FechaHistorica& f) {
   cout << "Insertando FechaHistorica\n";
   fechas_historicas.add(f);
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
   int i;
   Cronologia cr_tmp;
   while(fechas_historicas.get(i).anio < anioDesde) i++;
   for (; (fechas_historicas.get(i).anio >= anioDesde) && (fechas_historicas.get(i).anio <= anioHasta); i++) {
      cr_tmp.fechas_historicas.add(fechas_historicas.get(i));
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

istream& operator>>(istream& flujo, Cronologia& c) {
   cout << "Leyendo cronología ..." << endl;

   int fh_leidas = 0;

   string s;

   Lista<string> prueba;
   prueba.add("hola");
   prueba.add("adios");
   prueba.add("adios");

   cout << "Hola\n";
   FechaHistorica tmp (1850, prueba);
   cout << "Hola2\n";
   cout << tmp << endl;
   cout << "hola1\n";
   FechaHistorica tmp2;

   tmp2 = tmp;
   cout << "GOLA3\n";

   c.fechas_historicas.add(tmp);
   cout << "Prueba555\n";

   while (getline(flujo, s)) {
      istringstream ss(s);
      FechaHistorica aux;
      cout << "Leyendo FechaHistorica número: " << fh_leidas << endl;
      ss >> aux;
      cout << aux << endl;
      c.fechas_historicas.add(aux);

      fh_leidas++;
   }

   return flujo;
}