#ifndef LISTA
#define LISTA

#include "fechahistorica.h"


/**
 * @struct NodoLista
 *
 * @brief Completar
 *
 * @author Daniel Cortés
*/

template<class T>
struct NodoLista {
   T dato;
   NodoLista* siguiente;

   NodoLista();
   ~NodoLista();
   
};

template <class T>
class Lista {
   int num_datos;
   NodoLista* primer_dato;
   NodoLista* ultimo_dato;

   public:
   Lista();
   ~Lista();
   T get(int index);
   void add(T dato);
};


#endif
