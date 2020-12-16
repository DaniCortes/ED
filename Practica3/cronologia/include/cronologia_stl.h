#ifndef _CRONOLOGIA_STL_H_
#define _CRONOLOGIA_STL_H_

#include <iostream>
#include <sstream>
#include <map>
#include "fechahistorica_stl.h"
#include <string>

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
   std::map<int, FechaHistorica> fechas_historicas; /**< Map de objetos tipo FechaHistorica */

  public:

  typedef typename std::map<int, FechaHistorica>::iterator iterator;
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
    * @brief Método que obtiene el número máximo de eventos que 
    * 
    * 
    * 
    */

   int getMaxEventosEnAnio(int &anio) const;

   float getPromedioEventos() const;

   Cronologia getFechasPalabraClave(std::string palabra_clave);

   iterator begin();

   iterator end();

   const_iterator begin() const;

   const_iterator end() const;

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
