#include "fechahistorica_stl.h"

using namespace std;

FechaHistorica::FechaHistorica() {
   fecha.first = 0;
}

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

FechaHistorica& FechaHistorica::operator=(const FechaHistorica &f) {
   fecha.first = f.fecha.first;
   fecha.second = f.fecha.second;
   return *this;
}

FechaHistorica FechaHistorica::operator+(const FechaHistorica &f) {
   FechaHistorica tmp = *this;
   if (fecha.first == f.fecha.first){
      set<string>::iterator i;
      for (i = f.fecha.second.begin(); i != f.fecha.second.end(); i++){
         tmp.fecha.second.insert(*i);
      }
   }
   return tmp;
}

bool FechaHistorica::operator<(const FechaHistorica &f) const {
   return (fecha.first < f.fecha.first) ? true : false;
}

bool FechaHistorica::operator>(const FechaHistorica &f) const {
   return (fecha.first > f.fecha.first) ? true : false;
}

bool FechaHistorica::operator==(const FechaHistorica &f) const {
   return (fecha.first == f.fecha.first && fecha.second == f.fecha.second) ? true : false;
}

bool FechaHistorica::operator!=(const FechaHistorica &f) const {
   return !(*this == f);
};

ostream &operator<<(ostream &os, const FechaHistorica &f) {
   os << "Año: " << f.anio << endl;
   
   for (int i = 0; i < f.eventos.getNumDatos(); i++) {
      os << "\t Evento " << i << ": " << f.eventos.get(i) << endl;
   }

   os << endl;
   
   return os;
}

// Este método se proporciona a medio hacer para facilitar la lectura de una FechaHistorica a partir de un fichero
istream &operator>>(istream &is, FechaHistorica &f) {
   string s;

   getline(is, s, '#');

   int anio = stoi(s);
   cout << "\tLeido año: " << anio << endl;
   f.anio = anio;

   s="";
   while (getline(is, s, '#')) {
      cout << "\t\tLeido evento: " << s << endl;
      f.eventos.add(s);
      s="";
   }

   return is;
}

