#include "fechahistorica_stl.h"

using namespace std;

FechaHistorica::FechaHistorica() {}

FechaHistorica::FechaHistorica(const FechaHistorica &f) {
  fecha.first = f.fecha.first;
  fecha.second = f.fecha.second;
}

FechaHistorica::FechaHistorica(const int anio, const set<string> &eventos) {
  fecha.first = anio;
  fecha.second = eventos;
}

FechaHistorica::~FechaHistorica() {
  fecha.second.clear();
}

void FechaHistorica::setAnio(int anio) {
  fecha.first = anio;
}

int FechaHistorica::getAnio() const {
  return fecha.first;
}

int FechaHistorica::getNumEventos() const {
  return fecha.second.size();
}

FechaHistorica FechaHistorica::getEventosPalabraClave(string palabra_clave) {
  FechaHistorica tmp;
  tmp.fecha.first = fecha.first;
  for (string aux : *this) {
    if (aux.find(palabra_clave) != string::npos) {
      tmp.insert(aux);
    }
  }
  return tmp;
}

FechaHistorica::iterator FechaHistorica::begin() {
  return fecha.second.begin();
}

FechaHistorica::iterator FechaHistorica::end() {
  return fecha.second.end();
}

FechaHistorica::const_iterator FechaHistorica::begin() const {
  return fecha.second.begin();
}

FechaHistorica::const_iterator FechaHistorica::end() const {
  return fecha.second.end();
}

pair<FechaHistorica::iterator, bool> FechaHistorica::insert(
    const string evento) {
  return fecha.second.insert(evento);
}

bool FechaHistorica::empty() const {
  return fecha.second.empty();
}

FechaHistorica &FechaHistorica::operator=(const FechaHistorica &f) {
  fecha.first = f.fecha.first;
  fecha.second = f.fecha.second;
  return *this;
}

FechaHistorica FechaHistorica::operator+(const FechaHistorica &f) const {
  FechaHistorica tmp = *this;
  if (fecha.first == f.fecha.first) {
    for (string evento : f) {
      tmp.insert(evento);
    }
  }
  return tmp;
}

FechaHistorica &FechaHistorica::operator+=(const FechaHistorica &f) {
  if (fecha.first == f.fecha.first) {
    *this = *this + f;
  }
  return *this;
}

bool FechaHistorica::operator<(const FechaHistorica &f) const {
  return (fecha.first < f.fecha.first) ? true : false;
}

bool FechaHistorica::operator>(const FechaHistorica &f) const {
  return (fecha.first > f.fecha.first) ? true : false;
}

bool FechaHistorica::operator==(const FechaHistorica &f) const {
  return (fecha.first == f.fecha.first && fecha.second == f.fecha.second)
             ? true
             : false;
}

bool FechaHistorica::operator!=(const FechaHistorica &f) const {
  return !(*this == f);
};

ostream &operator<<(ostream &os, const FechaHistorica &f) {
  os << "\tAño: " << f.fecha.first << endl;
  int i = 0;
  if (f.getNumEventos() > 0) {
    for (string evento : f) {
      os << "\t\tEvento " << ++i << ": " << evento << endl;
    }

    os << endl;
  } else {
    os << "\t\tNo hay ningún evento\n";
  }
  return os;
}

istream &operator>>(istream &is, FechaHistorica &f) {
  string s;

  getline(is, s, '#');

  int anio = stoi(s);
  int i = 0;
  cout << "\tLeído año: " << anio << endl;
  f.fecha.first = anio;

  s = "";
  while (getline(is, s, '#')) {
    cout << "\t\tLeído evento " << ++i << ": " << s << endl;
    f.insert(s);
    s = "";
  }

  return is;
}
