#ifndef LISTA2
#define LISTA2

#include <iostream>
#include <string>

/**
 * @class NodoLista
 *
 * @brief T.D.A. NodoLista
 * 
 * Una instancia @e nd del tipo de datos abstracto @c NodoLista es un
 * objeto formado por un objeto de tipo @c T y la dirección al @c NodoLista
 * siguiente
 * 
 * @author Daniel Cortés
*/

template <class T>
struct NodoLista {
   /**
   * @page repConjunto Rep del TDA NodoLista
   *
   * @section invConjunto Invariante de la representación
   *
   * El invariante es \e dato!=null
   *
   * @section faConjunto Función de abstracción
   *
   * Un objeto válido @e rep del TDA NodoLista representa un nodo
   * con un dato válido
   *
   *
   */
   T dato;                    /**< Dato guardado en el nodo */
   NodoLista* siguiente;      /**< Dirección del siguiente nodo */

   /**
   * @brief Constructor por defecto
   */
   NodoLista();

   /**
   * @brief Destructor
   */
   ~NodoLista();
};

/**
 * @struct Lista
 *
 * @brief T.D.A. Lista
 * 
 * Una instancia @e l del tipo de datos abstracto @c Lista es un
 * objeto formado por un @c int que indica el número de datos, el
 * @c NodoLista con el primer dato, el @c NodoLista con el último
 * dato y un @c bool llamado init para controlar la inserción del 
 * primer @c T dato
 * 
 * @author Daniel Cortés
*/

template <class T>
class Lista {
  private:
   /**
   * @page repConjunto Rep del TDA Lista
   *
   * @section invConjunto Invariante de la representación
   *
   * El invariante es \e num_datos>=0
   *
   * @section faConjunto Función de abstracción
   *
   * Un objeto válido @e rep del TDA Racional representa a una
   * lista con nodos válidos
   *
   *
   */

   int num_datos;                /**< Número de datos guardados en la lista */
   NodoLista<T>* primer_dato;    /**< Dirección del primer nodo de la lista */
   NodoLista<T>* ultimo_dato;    /**< Dirección del último nodo de la lista */
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
   * @brief Añadirf un dato a la lista
   * 
   * @param dato dato que se quiere introducir
   */
   void add(T dato);

   /**
   * @brief Sobrecarga del operador =
   * 
   * @param l @c Lista usada para asignar el objeto implícito
   */
   Lista& operator=(const Lista& l);

   /**
   * @brief Sobrecarga del operador +
   * 
   * @param l @c Lista a sumar con el objeto implícito
   */
   Lista operator+(const Lista& l);

   /**
   * @brief Sobrecarga del operador +=
   * 
   * @param l @c Lista a sumar con el objeto implícito
   */
   void operator+=(const Lista& l);

   /**
   * @brief Sobrecarga del operador ==
   * 
   * @param l @c Lista a comparar con el objeto implícito
   */
   bool operator==(const Lista& l) const;

   /**
   * @brief Sobrecarga del operador !=
   * 
   * @param l @c Lista a comparar con el objeto implícito
   */
   bool operator!=(const Lista& l) const;

};

#endif
