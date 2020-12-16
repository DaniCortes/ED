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

int FechaHistorica::getNumEventos() const {
   return fecha.second.size();
}

FechaHistorica FechaHistorica::getEventosPalabraClave(string palabra_clave) {
   FechaHistorica tmp;
   tmp.fecha.first = fecha.first;
   FechaHistorica::iterator it;
   for(string aux: fecha.second) {
      if (aux.find(palabra_clave) != string::npos) {
         tmp.fecha.second.insert(aux);
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

FechaHistorica& FechaHistorica::operator=(const FechaHistorica &f) {
   fecha.first = f.fecha.first;
   fecha.second = f.fecha.second;
   return *this;
}

FechaHistorica FechaHistorica::operator+(const FechaHistorica &f) {
   FechaHistorica tmp = *this;
   if (fecha.first == f.fecha.first){
      for (string evento: f.fecha.second){
         tmp.fecha.second.insert(evento);
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
   os << "Año: " << f.fecha.first << endl;
   int i = 0;
   for(string evento: f.fecha.second) {
      os << "\t Evento " << ++i << ": " << evento << endl;
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
   f.fecha.first = anio;

   s="";
   while (getline(is, s, '#')) {
      cout << "\t\tLeido evento: " << s << endl;
      f.fecha.second.insert(s);
      s="";
   }

   return is;
}

