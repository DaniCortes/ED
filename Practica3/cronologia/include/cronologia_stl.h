#ifndef _CRONOLOGIA_STL_H_
#define _CRONOLOGIA_STL_H_

#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include "fechahistorica_stl.h"

/**
 * @class Cronologia
 *
 * @brief T.D.A. Cronologia
 *
 * Una instancia @e c del tipo de datos abstracto @c Cronologia es un
 * objeto formado por un @c map de objetos de tipo @c FechaHistorica con claves
 * @c int que son el año de dichos objetos @c FechaHistorica
 *
 * @author Daniel Cortés
 */

class Cronologia {
 private:
  /**
   * @page repCronologia Rep del TDA Cronologia
   *
   * @section invCronologia Invariante de la representación
   *
   * Debe de estar formada por un @c map con claves @c int y objetos @c
   * FechaHistorica válidos
   *
   * @section faCronologia Función de abstracción
   *
   * Un objeto válido @e rep del TDA Cronologia representa una
   * Cronologia con fechas históricas válidas ordenadas por año.
   *
   */

  std::map<int, FechaHistorica>
      fechas_historicas; /**< Map de objetos tipo FechaHistorica y su respectivo
                            año*/

 public:
  typedef std::map<int, FechaHistorica>::iterator iterator;
  typedef typename std::map<int, FechaHistorica>::const_iterator const_iterator;

  /**
   * @brief Constructor por defecto
   */
  Cronologia();

  /**
   * @brief Constructor de copia
   *
   * @param c @c Cronologia para construir el objeto implícito
   */
  Cronologia(const Cronologia &c);

  /**
   * @brief Sobrecarga del operador =
   *
   * @param c @c Cronologia usada para asignar el objeto implícito
   */
  Cronologia &operator=(const Cronologia &c);

  /**
   * @brief Destructor
   */
  ~Cronologia();

  /**
   * @brief Método que obtiene los eventos ocurridos en un año preciso
   *
   * @param anio año del que se quieren obtener los eventos
   *
   * @return Objeto de clase @c FechaHistorica con los eventos ocurridos en
   * dicho año
   */
  FechaHistorica ObtenerEventos(int anio);

  /**
   * @brief Método que obtiene los eventos ocurridos entre dos años, ambos
   * incluídos
   *
   * @param anioDesde año desde el que se quieren obtener los eventos
   * @param anioHasta año hasta el que se quieren obtener los eventos
   *
   * @return Objeto de clase @c Cronologia con los eventos ocurridos en el
   * intervalo de años
   */
  Cronologia ObtenerEventos(int anioDesde, int anioHasta);

  /**
   * @brief Método que obtiene el número máximo de eventos guardados en una @c
   * FechaHistorica
   *
   * @param anio variable pasada por referencia para conseguir el año en el que
   * está el máximo de eventos
   */
  int getMaxEventosEnFechaHistorica(int &anio) const;

  /**
   * @brief Consultor del número total de eventos guardados
   */
  int getTotalEventos() const;

  /**
   * @brief Consultor del número de objetos @c FechaHistorica almacenados
   */
  size_t size() const;

  /**
   * @brief Método que obtiene el número promedio de eventos por año
   */
  float getPromedioEventos() const;

  /**
   * @brief Método que obtiene los eventos que contengan una palabra clave
   *
   * @param palabra_clave palabra que se está buscando en la @c Cronologia
   *
   * @return Objeto de clase @c Cronologia con los eventos que contengan dicha
   * palabra clave, ordenados por año
   */
  Cronologia getFechasPalabraClave(std::string palabra_clave);

  /**
   * @brief Método que devuelve un iterador apuntando al inicio de la @c
   * Cronologia
   */
  iterator begin();

  /**
   * @brief Método que devuelve un iterador apuntando al final de la @c
   * Cronologia
   */
  iterator end();

  /**
   * @brief Método que devuelve un iterador constante apuntando al inicio de la
   * @c Cronologia
   */
  const_iterator begin() const;

  /**
   * @brief Método que devuelve un iterador constante apuntando al final de la
   * @c Cronologia
   */
  const_iterator end() const;

  /**
   * @brief Método para insertar una @c FechaHistorica
   *
   * @param fh @c FechaHistorica a insertar en la @c Cronologia
   */
  std::pair<Cronologia::iterator, bool> insert(const FechaHistorica &fh);

  /**
   * @brief Método que comprueba si la @c Cronologia está vacía o no
   */
  bool empty() const;

  /**
   * @brief Sobrecarga del operador +
   *
   * @param c @c Cronologia a sumar con el objeto implícito
   */
  Cronologia operator+(const Cronologia &c) const;

  /**
   * @brief Sobrecarga del operador ==
   *
   * @param c @c Cronologia a comparar con el objeto implícito
   */
  bool operator==(const Cronologia &c) const;

  /**
   * @brief Sobrecarga del operador !=
   *
   * @param c @c Cronologia a comparar con el objeto implícito
   *
   */
  bool operator!=(const Cronologia &c) const;

  /**
   * @brief Sobrecarga del operador <<
   *
   * @param os stream de salida
   * @param c @c Cronologia a mostrar
   */
  friend std::ostream &operator<<(std::ostream &os, const Cronologia &c);

  /**
   * @brief Sobrecarga del operador >>
   *
   * @param is stream de entrada
   * @param c @c Cronologia a escribir
   */
  friend std::istream &operator>>(std::istream &is, Cronologia &c);
};

#endif
