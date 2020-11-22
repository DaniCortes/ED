#ifndef LISTA2
#define LISTA2

#include <iostream>
/**
 * @struct NodoLista
 *
 * @brief Completar
 *
 * @author Daniel Cortés
*/

template <class T>
struct NodoLista {
   T dato;               /**< Dato guardado en el nodo */
   NodoLista* siguiente; /**< Puntero que guarda la dirección del siguiente nodo */

   NodoLista() {
      siguiente = nullptr;
   }
   ~NodoLista() {
      siguiente = nullptr;
   }
};

template <class T>
class Lista {
   int num_datos;             /**< Número de datos guardados en la lista */
   NodoLista<T>* primer_dato; /**< Puntero que guarda la dirección del primer nodo de la lista */
   NodoLista<T>* ultimo_dato; /**< Puntero que guarda la dirección del último nodo de la lista */

  public:
   /**
   * @brief Constructor por defecto
   */
   Lista() {
      primer_dato = new NodoLista<T>;
      ultimo_dato = primer_dato;
      num_datos = 0;
   }

   /**
   * @brief Destructor
   */
   ~Lista() {
      NodoLista<T>* tmp;

      while (primer_dato != nullptr) {
         tmp = primer_dato;
         primer_dato = primer_dato->siguiente;
         delete tmp;
      }
   }

   /**
   * @brief Consultor del número de datos que hay en la lista
   */
   int getNumDatos() const { return num_datos; }

   /**
   * @brief Consultor del dato de una posición en la lista
   * 
   * @param index índice del dato en la lista
   */
   T get(int index) const {
      NodoLista<T>* tmp = primer_dato;
      for (int i = 0; i < index; i++) {
         tmp = tmp->siguiente;
      }
      return tmp->dato;
   }

   /**
   * @brief Añadir un dato a la lista
   * 
   * @param dato dato que se quiere introducir
   */
   void add(T dato) {
      ultimo_dato->siguiente = new NodoLista<T>;
      std::cout << "Crear nuevo nodo\n";
      ultimo_dato = ultimo_dato->siguiente;
      ultimo_dato->dato = dato;
      num_datos++;
      std::cout << "Sumar num_datos\n";
   }

   Lista& operator=(const Lista& otra) {
      if (otra != *this) {
         NodoLista<T>* tmp;

         while (primer_dato != nullptr) {
            tmp = primer_dato;
            primer_dato = primer_dato->siguiente;
            delete tmp;
         }
         num_datos = otra.num_datos;
         for (int i = 0; i < num_datos; i++) {
            add(otra.get(i));
         }
      }
      return *this;
   }

   Lista operator+(const Lista& lista) {
      Lista<T> tmp = *this;
      for (int i = 0; i < lista.num_datos; i++) {
         tmp.add(lista.get(i));
      }
      return tmp;
   }

   void operator+=(const Lista& lista) {
      for (int i = 0; i < lista.num_datos; i++) {
         add(lista.get(i));
      }
   }

   bool operator==(const Lista& lista) const {
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

   bool operator!=(const Lista& lista) const {
      return !(*this == lista);
   }
};

#endif