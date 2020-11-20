#include "lista.h"

template <class T>
NodoLista<T>::NodoLista() {
   dato = null;
   siguiente = nullptr;
}

template <class T>
NodoLista<T>::~NodoLista() {
   delete fechaHistorica;
}

template <class T>
Lista<T>::Lista() {
   primer_dato = new NodoLista;
   ultimo_dato = primer_dato;
}

template <class T>
Lista<T>::~Lista() {
   NodoLista* anterior = nullptr;
   NodoLista* recorrer = primer_dato;
   primer_dato = nullptr;
   ultimo_dato = nullptr;

   for (int i = 0; i < num_datos; i++) {
      anterior = recorrer;
      recorrer = recorrer->siguiente;
      delete anterior;

   }

   anterior = nullptr;
}

template <class T>
T Lista<T>::get(int index) {
   NodoLista* tmp = bloque_primer;
   for (int i = 0; i < index; i++) {
      tmp = tmp->siguiente;
   }
   return tmp->dato;
}

template <class T>
void Lista<T>::add(T dato) {
   ultimo_dato->siguiente = new NodoLista;
   ultimo_dato = ultimo_dato->siguiente;
   ultimo_dato->dato = dato;
}

template class NodoLista<FechaHistorica>;
template class Lista<FechaHistorica>;
