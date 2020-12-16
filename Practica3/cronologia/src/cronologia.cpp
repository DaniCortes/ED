#include "cronologia_stl.h"

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
   FechaHistorica tmp;
   Cronologia::iterator it = fechas_historicas.find(anio);
   if (it != end() && it->first == anio) {
      tmp = it->second;
      return tmp;
   }
   tmp.fecha.first = anio;
   tmp.fecha.second.insert("No hay ningún evento");
   return tmp;
}

Cronologia Cronologia::ObtenerEventos(int anioDesde, int anioHasta) {
   int i = 0;
   Cronologia cr_tmp;

   Cronologia::iterator it = fechas_historicas.find(anioDesde);
   if (it == end()) {
      it = fechas_historicas.upper_bound(anioDesde);
   }
   for (it; it != fechas_historicas.upper_bound(anioHasta); it++) {
      cr_tmp.fechas_historicas.insert({it->first, it->second});
   }

   return cr_tmp;
}

int Cronologia::getMaxEventosEnAnio(int &anio) const {
   int max = begin()->second.getNumEventos();
   anio = begin()->first;
   int numEventos;
   for (pair<int, FechaHistorica> aux: fechas_historicas) {
      if (numEventos = aux.second.getNumEventos() > max) {
         max = numEventos;
         anio = aux.first;
      }
   }
   return max;
}

float Cronologia::getPromedioEventos() const {
   int total = 0;
   for (pair<int, FechaHistorica> aux : fechas_historicas) {
      total += aux.second.getNumEventos();
   }
   return (float(total) / float(fechas_historicas.size()));
}

Cronologia Cronologia::getFechasPalabraClave(string palabra_clave) {
   Cronologia cr_tmp;
   FechaHistorica fh_tmp;
   for (pair<int, FechaHistorica> aux: fechas_historicas) {
      fh_tmp = aux.second.getEventosPalabraClave(palabra_clave);
      if (fh_tmp.fecha.second.size() != 0) {
         cr_tmp.fechas_historicas.insert({aux.first, fh_tmp});
      }
   }
   return cr_tmp;
}

Cronologia::iterator Cronologia::begin() {
   return fechas_historicas.begin();
}

Cronologia::iterator Cronologia::end() {
   return fechas_historicas.end();
}

Cronologia::const_iterator Cronologia::begin() const {
   return fechas_historicas.begin();
}

Cronologia::const_iterator Cronologia::end() const {
   return fechas_historicas.end();
}

bool Cronologia::operator==(const Cronologia& c) const {
   return (fechas_historicas == c.fechas_historicas) ? true : false;
}

bool Cronologia::operator!=(const Cronologia& c) const {
   return !(*this == c);
}

ostream& operator<<(std::ostream& os, const Cronologia& c) {
FechaHistorica a = c.fechas_historicas.at(1);

   for (pair <int, FechaHistorica> fecha: c.fechas_historicas) {
      os << fecha.second;
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
      FechaHistorica fh_aux;
      int int_aux;
      cout << "Leyendo FechaHistorica número: " << fh_leidas << endl;
      ss >> fh_aux;
      int_aux = fh_aux.getAnio();
      c.fechas_historicas.insert({int_aux, fh_aux});
      fh_leidas++;
   }

   return is;
}