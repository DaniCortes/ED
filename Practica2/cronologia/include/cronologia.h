#ifndef _CRONOLOGIA_H_
#define _CRONOLOGIA_H_

#include <iostream>
#include <sstream>
#include <string>
#include "fechahistorica.h"
#include "lista.h"

/**
 * @class Cronologia

 * @brief Completar
 
 * @author Daniel Cortés
*/


class Cronologia {
  private:
   Lista<FechaHistorica> fechas_historicas;

  public:
   /**
  * @brief Constructor por defecto
  */
   Cronologia();

   /**
  * @brief Constructor de copia
  * 
  * @param c un objeto de Cronologia
  */
   Cronologia(const Cronologia &c);

   /**
  * @brief Sobrecarga del operador =
  * 
  * @param c un objeto de Cronologia
  */
   Cronologia &operator=(const Cronologia &c);

   void insertar(const FechaHistorica &f);

   /**
  * @brief Destructor
  */
   ~Cronologia();

   FechaHistorica ObtenerEventos(int anio);

   Cronologia ObtenerEventos(int anioDesde, int anioHasta);

   /**
   * @brief Sobrecarga del operador ==
   */
   bool operator==(const Cronologia &c);

   /**
   * @brief Sobrecarga del operador !=
   */
   bool operator!=(const Cronologia &c);

   /**
   * @brief Sobrecarga del operador <<
   */
   friend std::ostream &operator<<(std::ostream &flujo, const Cronologia &c);

   /**
  * @brief Sobrecarga del operador >>
  */
   friend std::istream &operator>>(std::istream &flujo, Cronologia &c);
};





#endif
