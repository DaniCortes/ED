#ifndef _CRONOLOGIA_H_
#define _CRONOLOGIA_H_

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

   // Completar ...
};

/**
  * @brief Sobrecarga del operador <<
  */
std::ostream &operator<<(std::ostream &flujo, const Cronologia &c);

/**
  * @brief Sobrecarga del operador >>
  */
std::istream &operator>>(std::istream &flujo, Cronologia &c);

#endif
