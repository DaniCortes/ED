#ifndef LISTA2
#define LISTA2

#include <iostream>
#include <string>
/**
 * @struct NodoLista
 *
 * @brief Completar
 *
 * @author Daniel Cortés
*/

template <class T>
struct NodoLista {
   T dato;                    /**< Dato guardado en el nodo */
   NodoLista* siguiente;      /**< Puntero que guarda la dirección del siguiente nodo */

   NodoLista();
   ~NodoLista();
};

template <class T>
class Lista {
   int num_datos;                /**< Número de datos guardados en la lista */
   NodoLista<T>* primer_dato;    /**< Puntero que guarda la dirección del primer nodo de la lista */
   NodoLista<T>* ultimo_dato;    /**< Puntero que guarda la dirección del último nodo de la lista */
   bool init;

  public:
   /**
   * @brief Constructor por defecto
   */
   Lista();

   /**
   * @brief Destructor
   */
   ~Lista();

   /**
   * @brief Consultor del número de datos que hay en la lista
   */
   int getNumDatos() const { return num_datos; }

   /**
   * @brief Consultor del dato de una posición en la lista
   * 
   * @param index índice del dato en la lista
   */
   T get(int index) const;

   /**
   * @brief Añadir un dato a la lista
   * 
   * @param dato dato que se quiere introducir
   */
   void add(T dato);

   Lista& operator=(const Lista& otra);

   Lista operator+(const Lista& lista);

   void operator+=(const Lista& lista);

   bool operator==(const Lista& lista) const;

   bool operator!=(const Lista& lista) const;
};

#endif
