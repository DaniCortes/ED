#ifndef _CRONOLOGIA_H_
#define _CRONOLOGIA_H_

#include <iostream>
#include <sstream>
#include <string>
#include "fechahistorica.h"

/**
 * @class Cronologia
 * 
 * @brief T.D.A. Cronologia
 * 
 * Una instancia @e c del tipo de datos abstracto @c Cronologia es un 
 * objeto formado por una @c Lista de objetos de tipo @c FechaHistorica
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
   * El invariante es \e num_datos>=0
   *
   * @section faCronologia Función de abstracción
   *
   * Un objeto válido @e rep del TDA FechaHistorica representa una
   * cronología con fechas históricas válidas
   *
   *
   */
   Lista<FechaHistorica> fechas_historicas; /**< Lista de objetos tipo FechaHistorica */

  public:
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
   */
   FechaHistorica ObtenerEventos(int anio);

   /**
   * @brief Método que obtiene los eventos ocurridos entre dos años, ambos incluídos
   * 
   * @param anioDesde año desde el que se quieren obtener los eventos 
   * @param anioHasta año hasta el que se quieren obtener los eventos 
   */
   Cronologia ObtenerEventos(int anioDesde, int anioHasta);

   /**
   * @brief Sobrecarga del operador ==
   * 
   * @param c @c Cronologia a comparar con el objeto implícito
   */
   bool operator==(const Cronologia &c);

   /**
   * @brief Sobrecarga del operador !=
   * 
   * @param c @c Cronologia a comparar con el objeto implícito
   * 
   */
   bool operator!=(const Cronologia &c);

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
