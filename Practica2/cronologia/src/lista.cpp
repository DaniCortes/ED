#include "lista.h"
#include "fechahistorica.h"

using namespace std;

template <class T>
NodoLista<T>::NodoLista() {
   siguiente = nullptr;
}

template <class T>
NodoLista<T>::~NodoLista() {
   siguiente = nullptr;
}

template <class T>
Lista<T>::Lista() {
   primer_dato = new NodoLista<T>;
   ultimo_dato = primer_dato;
   num_datos = 0;
   init = true;
}

template <class T>
Lista<T>::~Lista() {
   NodoLista<T>* tmp;

   while (primer_dato != nullptr) {
      tmp = primer_dato;
      primer_dato = primer_dato->siguiente;
      delete tmp;
   }
   num_datos = 0;
   ultimo_dato = nullptr;
}

template <class T>
T Lista<T>::get(int index) const {
   NodoLista<T>* tmp = primer_dato;
   for (int i = 0; i < index-1; i++) {
      tmp = tmp->siguiente;
   }
   return tmp->dato;
}

template <class T>
void Lista<T>::add(T dato) {
   if (init) {
      primer_dato->dato = dato;
      init = false;

   } else {
      ultimo_dato->siguiente = new NodoLista<T>;
      ultimo_dato = ultimo_dato->siguiente;
      ultimo_dato->dato = dato;
   }
   num_datos++;
}

template <class T>
Lista<T>& Lista<T>::operator=(const Lista<T>& otra) {
   if (otra != *this) {
      NodoLista<T>* tmp;
      num_datos = 0;

      while (primer_dato != nullptr) {
         tmp = primer_dato;
         primer_dato = primer_dato->siguiente;
         delete tmp;
      }

      primer_dato = new NodoLista<T>;
      ultimo_dato = primer_dato;
      init = true;

      for (int i = 0; i < otra.num_datos; i++) {
         add(otra.get(i));
      }
   }
   return *this;
}

template <class T>
Lista<T> Lista<T>::operator+(const Lista<T>& lista) {
   Lista<T> tmp = *this;
   for (int i = 0; i < lista.num_datos; i++) {
      tmp.add(lista.get(i));
   }
   return tmp;
   
}

template <class T>
void Lista<T>::operator+=(const Lista<T>& lista) {
   for (int i = 0; i < lista.num_datos; i++) {
      add(lista.get(i));
   }
}

template <class T>
bool Lista<T>::operator==(const Lista<T>& lista) const {
   if (num_datos != lista.num_datos) {
      return false;
   } else {
      for (int i = 0; i < num_datos; i++) {
         if ((get(i) != lista.get(i))) {
            return false;
         }
      }
   }
   return true;
}

template <class T>
bool Lista<T>::operator!=(const Lista<T>& lista) const {
   return !(*this == lista);
}

template class NodoLista<FechaHistorica>;
template class Lista<FechaHistorica>;
template class NodoLista<string>;
template class Lista<string>;