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
  return tmp;
}

Cronologia Cronologia::ObtenerEventos(int anioDesde, int anioHasta) {
  Cronologia cr_tmp;

  Cronologia::iterator it = fechas_historicas.find(anioDesde);
  if (it == end()) {
    it = fechas_historicas.upper_bound(anioDesde);
  }
  for (; it != fechas_historicas.upper_bound(anioHasta); it++) {
    cr_tmp.insert(it->second);
  }

  return cr_tmp;
}

int Cronologia::getMaxEventosEnFechaHistorica(int& anio) const {
  int max = begin()->second.getNumEventos();
  anio = begin()->first;
  int numEventos;
  for (pair<int, FechaHistorica> aux : *this) {
    if ((numEventos = aux.second.getNumEventos()) > max) {
      max = numEventos;
      anio = aux.first;
    }
  }
  return max;
}

int Cronologia::getTotalEventos() const {
  int total = 0;
  for (pair<int, FechaHistorica> aux : *this) {
    total += aux.second.getNumEventos();
  }
  return total;
}

size_t Cronologia::size() const {
  return fechas_historicas.size();
}

float Cronologia::getPromedioEventos() const {
  return (float(getTotalEventos()) / float(size()));
}

Cronologia Cronologia::getFechasPalabraClave(string palabra_clave) {
  Cronologia cr_tmp;
  FechaHistorica fh_tmp;
  for (pair<int, FechaHistorica> aux : *this) {
    fh_tmp = aux.second.getEventosPalabraClave(palabra_clave);
    if (!fh_tmp.empty()) {
      cr_tmp.insert(fh_tmp);
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

pair<Cronologia::iterator, bool> Cronologia::insert(const FechaHistorica& fh) {
  pair<int, FechaHistorica> fecha{fh.getAnio(), fh};
  return fechas_historicas.insert(fecha);
}

bool Cronologia::empty() const {
  return fechas_historicas.empty();
}

Cronologia Cronologia::operator+(const Cronologia& c) const {
  Cronologia tmp = *this;
  for (pair<int, FechaHistorica> fecha : c) {
    cout << fecha.first << endl;
    if (tmp.fechas_historicas.count(fecha.first) == 1) {
      tmp.fechas_historicas[fecha.first] += fecha.second;
    } else {
      tmp.insert(fecha.second);
    }
  }
  return tmp;
}

bool Cronologia::operator==(const Cronologia& c) const {
  return (fechas_historicas == c.fechas_historicas) ? true : false;
}

bool Cronologia::operator!=(const Cronologia& c) const {
  return !(*this == c);
}

ostream& operator<<(std::ostream& os, const Cronologia& c) {
  if (!c.empty()) {
    os << "Mostrando cronología ...\n";

    int fh_mostradas = 0;

    for (pair<int, FechaHistorica> fecha : c) {
      os << "Mostrando FechaHistorica número: " << ++fh_mostradas << endl;
      os << fecha.second;
    }
    return os;
  }

  os << "Cronología vacía\n";

  return os;
}

istream& operator>>(istream& is, Cronologia& c) {
  cout << "Leyendo cronología ...\n";

  int fh_leidas = 0;

  string s;

  while (getline(is, s)) {
    FechaHistorica fh;
    istringstream ss(s);
    cout << "\nLeyendo FechaHistorica número: " << ++fh_leidas << endl;
    ss >> fh;
    c.insert(fh);
  }
  cout << endl;
  return is;
}