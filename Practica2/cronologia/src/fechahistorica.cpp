#include "fechahistorica.h"

using namespace std;

FechaHistorica::FechaHistorica() {
   anio = 0;
}

FechaHistorica::FechaHistorica(const FechaHistorica &f) {
   anio = f.anio;
   eventos = f.eventos;
}

FechaHistorica::FechaHistorica(const int anio, const Lista<string> eventos) {
   this->anio = anio;
   this->eventos = eventos;
}

FechaHistorica::~FechaHistorica() {}

    void FechaHistorica::setAnio(int anio) {
   this->anio = anio;
}

int FechaHistorica::getAnio() const {
   return anio;
}

FechaHistorica& FechaHistorica::operator=(const FechaHistorica &f) {
   anio = f.anio;
   eventos = f.eventos;
   return *this;
}

FechaHistorica FechaHistorica::operator+(const FechaHistorica &f) {
   FechaHistorica tmp;
   tmp.anio = f.anio;
   tmp.eventos = eventos + f.eventos;
   return tmp;
}

bool FechaHistorica::operator<(const FechaHistorica &f) const {
   return (this->anio < f.anio) ? true : false;
}

bool FechaHistorica::operator>(const FechaHistorica &f) const {
   return (this->anio > f.anio) ? true : false;
}

bool FechaHistorica::operator==(const FechaHistorica &f) const {
   return (anio == f.anio && eventos == f.eventos) ? true : false;
}

bool FechaHistorica::operator!=(const FechaHistorica &f) const {
   return !(*this == f);
};

ostream &operator<<(ostream &os, const FechaHistorica &f) {
   os << "Año: " << f.anio;
   
   for (int i = 0; i < f.eventos.getNumDatos(); i++) {
      os << "\n\t" << f.eventos.get(i);
   }

   
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

