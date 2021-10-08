#ifndef _FECHAHISTORICA_STL_H_
#define _FECHAHISTORICA_STL_H_

#include <iostream>
#include <set>
#include <string>

/**
 * @class FechaHistorica
 *
 * @brief T.D.A. FechaHistorica
 *
 * Una instancia @e fh del tipo de datos abstracto @c FechaHistorica es un
 * objeto formado por un @c pair que almacena tanto el año como un @c set de
 * objetos de tipo @c string que indica los eventos ocurridos en ese año
 *
 * @author Daniel Cortés
 */

class FechaHistorica {
 private:
  /**
   * @page repFechaHistorica Rep del TDA FechaHistorica
   *
   * @section invFechaHistorica Invariante de la representación
   *
   * El invariante es que no pueden coexistir dos eventos exactamente iguales
   *
   * @section faFechaHistorica Función de abstracción
   *
   * Un objeto válido @e rep del TDA FechaHistorica representa una
   * fecha histórica con un evento o más y el año en el que ocurrieron
   *
   *
   */

  std::pair<int, std::set<std::string>>
      fecha; /**< Par que contiene el año y un set con los eventos */

 public:
  typedef std::set<std::string>::iterator iterator;
  typedef typename std::set<std::string>::const_iterator const_iterator;

  /**
   * @brief Constructor por defecto
   */
  FechaHistorica();

  /**
   * @brief Constructor de copia
   *
   * @param fh @c FechaHistorica para construir el objeto implícito
   */
  FechaHistorica(const FechaHistorica &f);

  /**
   * @brief Constructor de la clase
   *
   * @param anio el año de la fecha histórica
   * @param eventos @c Lista de eventos ocurridos en ese año
   */
  FechaHistorica(const int anio, const std::set<std::string> &eventos);

  /**
   * @brief Destructor
   */
  ~FechaHistorica();

  /**
   * @brief Descriptor del año
   *
   * @param anio un entero que indica el año
   */
  void setAnio(int anio);

  /**
   * @brief Consultor del año
   */
  int getAnio() const;

  /**
   * @brief Consultor del número de eventos guardados
   */
  int getNumEventos() const;

  /**
   * @brief Método que obtiene los eventos que contengan una palabra clave
   *
   * @param palabra_clave palabra que se está buscando en la @c FechaHistorica
   *
   * @return Objeto de clase @c FechaHistorica con los eventos que contengan
   * dicha palabra clave
   */
  FechaHistorica getEventosPalabraClave(std::string palabra_clave);

  /**
   * @brief Método que devuelve un iterador apuntando al inicio de la @c
   * FechaHistorica
   */
  iterator begin();

  /**
   * @brief Método que devuelve un iterador apuntando al final de la @c
   * FechaHistorica
   */
  iterator end();

  /**
   * @brief Método que devuelve un iterador constante apuntando al inicio de la
   * @c FechaHistorica
   */
  const_iterator begin() const;

  /**
   * @brief Método que devuelve un iterador constante apuntando al final de la
   * @c FechaHistorica
   */
  const_iterator end() const;

  /**
   * @brief Método para insertar un evento
   *
   * @param evento @c string a insertar en la @c FechaHistorica
   */
  std::pair<FechaHistorica::iterator, bool> insert(const std::string evento);

  /**
   * @brief Método que comprueba si la @c FechaHistorica está vacía o no
   */
  bool empty() const;

  /**
   * @brief Sobrecarga del operador =
   *
   * @param fh @c FechaHistorica usada para asignar el objeto implícito
   */
  FechaHistorica &operator=(const FechaHistorica &f);

  /**
   * @brief Sobrecarga del operador +
   *
   * @param fh @c FechaHistorica a sumar con el objeto implícito
   */
  FechaHistorica operator+(const FechaHistorica &f) const;

  /**
   * @brief Sobrecarga del operador +=
   *
   * @param fh @c FechaHistorica a sumar con el objeto implícito
   */
  FechaHistorica &operator+=(const FechaHistorica &f);

  /**
   * @brief Sobrecarga del operador <
   *
   * @param fh @c FechaHistorica a añadir al objeto implícito
   */
  bool operator<(const FechaHistorica &f) const;

  /** @brief Sobrecarga del operador >
   *
   * @param fh @c FechaHistorica a comparar con el objeto implícito
   */
  bool operator>(const FechaHistorica &f) const;

  /** @brief Sobrecarga del operador ==
   *
   * @param fh @c FechaHistorica a comparar con el objeto implícito
   */
  bool operator==(const FechaHistorica &f) const;

  /** @brief Sobrecarga del operador !=
   *
   * @param fh @c FechaHistorica a comparar con el objeto implícito
   */
  bool operator!=(const FechaHistorica &f) const;

  /**
   * @brief Sobrecarga del operador <<
   *
   * @param os stream de salida
   * @param fh @c FechaHistorica a mostrar
   */
  friend std::ostream &operator<<(std::ostream &os, const FechaHistorica &f);

  /**
   * @brief Sobrecarga del operador >>
   *
   * @param is stream de entrada
   * @param os stream de salida
   * @param fh @c FechaHistorica a escribir
   */
  friend std::istream &operator>>(std::istream &is, FechaHistorica &f);

  friend class Cronologia;
};

#endif
