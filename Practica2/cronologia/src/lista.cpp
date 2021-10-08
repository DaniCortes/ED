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
  if (index > 0) {
    for (int i = 0; i < index; i++) {
      tmp = tmp->siguiente;
    }
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
Lista<T>& Lista<T>::operator=(const Lista<T>& l) {
  if (l != *this) {
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

    for (int i = 0; i < l.num_datos; i++) {
      add(l.get(i));
    }
  }
  return *this;
}

template <class T>
Lista<T> Lista<T>::operator+(const Lista<T>& l) {
  Lista<T> tmp = *this;
  for (int i = 0; i < l.num_datos; i++) {
    tmp.add(l.get(i));
  }
  return tmp;
}

template <class T>
void Lista<T>::operator+=(const Lista<T>& l) {
  for (int i = 0; i < l.num_datos; i++) {
    add(l.get(i));
  }
}

template <class T>
bool Lista<T>::operator==(const Lista<T>& l) const {
  if (num_datos != l.num_datos) {
    return false;
  } else {
    for (int i = 0; i < num_datos; i++) {
      if ((get(i) != l.get(i))) {
        return false;
      }
    }
  }
  return true;
}

template <class T>
bool Lista<T>::operator!=(const Lista<T>& l) const {
  return !(*this == l);
}

template class NodoLista<FechaHistorica>;
template class Lista<FechaHistorica>;
template class NodoLista<string>;
template class Lista<string>;