#ifndef _TRIE_H_
#define _TRIE_H_

#include <iostream>

/**
 * @class Celda
 *
 * @brief T.D.A. Celda
 *
 * Una instancia @e c del tipo de datos abstracto @c Celda es un
 * objeto formado por un @c char y varios punteros de clase @c Celda ,
 * representando al padre, al hijo izquierdo y al hermano derecho.
 *
 * @author Daniel Cortés
 */

class Celda {
 private:
  /**
   * @page repCelda Rep del TDA Celda
   *
   * @section invCelda Invariante de la representación
   *
   * Debe de estar formada por un @c char con o sin valor y punteros de clase @c
   * Celda apuntando al padre, al hermano izquierdo y al hermano derecho, si
   * existen.
   *
   * @section faCelda Función de abstracción
   *
   * Un objeto válido @e rep del TDA Celda representa una
   * celda enlazada con su padre, hijo y hermano.
   *
   */

  char caracter; /**< Carácter que guarda la celda*/

  Celda *padre;    /**< Puntero que apunta a la celda padre*/
  Celda *hijo_izq; /**< Puntero que apunta a la celda del hijo izquierdo*/
  Celda *herm_der; /**< Puntero que apunta a la celda del hermano derecho*/

 public:
  /**
   * @brief Constructor por defecto
   */
  Celda();

  /**
   * @brief Destructor
   */
  ~Celda();

  /**
   * @brief Constructor con parámetro
   *
   * @param c @c char para inicializar el carácter de la celda
   */
  Celda(char c);

  /**
   * @brief Constructor de copia
   *
   * @param c @c Celda para construir el objeto implícito
   */
  Celda(const Celda &c);
  /**
   * @brief Constructor con parámetros
   *
   * @param c @c Celda para inicializar los punteros
   * @param ch @c char para inicializar el carácter
   */
  Celda(const Celda &c, char ch);

  /**
   * @brief Sobrecarga del operador =
   *
   * @param c @c Celda usada para asignar el objeto implícito
   */
  Celda &operator=(const Celda &c);

  friend class Trie;
};

typedef Celda *Nodo;

/**
 * @class Trie
 *
 * @brief T.D.A. Árbol Trie
 *
 * Una instancia @e c del tipo de datos abstracto @c Trie es un
 * árbol genérico donde cada nodo contiene una letra que constituye
 * un prefijo de una palabra. Sirve para almacenar palabras. En la
 * instancia únicamente se almacena explícitamente el @c Nodo raiz.
 *
 * @author Daniel Cortés
 */
class Trie {
 private:
  /**
   * @page repTrie Rep del TDA Árbol Trie
   *
   * @section invTrie Invariante de la representación
   *
   * Debe de estar formada por un @c Nodo raiz enlazado con su hijo
   * izquierdo. Nunca debe tener enlazado un hermano derecho
   *
   * @section faTrie Función de abstracción
   *
   * Un objeto válido @e rep del TDA Trie representa una
   * colección de caracteres almacenados de forma ordenada,
   * formando palabras.
   *
   */

  Nodo raiz; /**< Raíz del árbol*/

  /**
   * @brief Método devuelve la palabra pasada por parámetro con todas las letras
   * en minúscula
   *
   * @param str palabra a la que pasar sus caracteres a minúscula
   *
   * @return Objeto de clase @c string con todos los caracteres en minúscula
   */
  std::string toLowerString(const std::string str);

  /**
   * @brief Método para eliminar un nodo y todos sus descendientes
   *
   * @param n @c Nodo que se quiere eliminar junto con su descendencia
   */
  void podar(Nodo n);

  /**
   * @brief Método que obtiene el hermano izquierdo del @c Nodo pasado por
   * parámetro
   *
   * @param n @c Nodo delque se quiere obtener el hermano izquierdo
   */
  Nodo getHermanoIzquierdo(Nodo n);

  /**
   * @brief Método busca un carácter en un nodo y en sus hermanos derechos
   *
   * @param c @c char que se quiere buscar
   * @param n @c Nodo en el que se quiere buscar el carácter, junto con sus
   * hermanos
   *
   * @return @c Nodo que tiene el carácter de entre los hermanos derechos de n
   */
  Nodo buscarCaracter(char c, Nodo n);

  /**
   * @brief Método que comprueba si el árbol está vacío
   */
  bool estaVacio();

  /**
   * @brief Método que crea un @c Nodo lo más derecha posible del nodo pasado
   * por parámetro
   *
   * @param n @c Nodo en el que se quiere crear el hermano derecho. Si ya
   * existe, se intenta crear en el siguiente hermano derecho
   *
   * @return @c Nodo creado lo más a la derecha posible del nodo pasado por
   * parámetro
   */
  Nodo crearHermanoDerecho(Nodo n);

  /**
   * @brief Método que inserta un @c char en un @c Nodo o en alguno de sus
   * hermanos derechos
   *
   * @param c @c char que se quiere insertar
   * @param n @c Nodo en el que se quiere insertar el carácter si está libre, En
   * caso contrario, se insertará en uno de sus hermanos
   *
   * @return @c Nodo que contenga el carácter recién insertado
   */
  Nodo insertarCaracter(char c, Nodo n);

 public:
  /**
   * @brief Constructor por defecto
   */
  Trie();

  /**
   * @brief Constructor con parámetro
   *
   * @param palabra @c string a introducir en el árbol
   */
  Trie(std::string palabra);

  /**
   * @brief destructor
   */
  ~Trie();

  /**
   * @brief Método que inserta un @c string en el árbol
   *
   * @param palabra @c string que se quiere insertar
   */
  void insertarPalabra(std::string palabra);

  /**
   * @brief Método que comprueba si una palabra está en el árbol
   *
   * @param palabra @c string que se quiere comprobar
   */
  bool buscarPalabra(std::string palabra);
};

#endif