#ifndef _FECHAHISTORICA_H_
#define _FECHAHISTORICA_H_

#include <iostream>

/**
 * @class FechaHistorica
 *
 * @brief Completar
 *
 * @author Daniel Cortés
*/

class FechaHistorica {
  private:
   int anio;


  public:
   /**
  * @brief Constructor por defecto
  */
   FechaHistorica();

   /**
  * @brief Constructor de copia
  * 
  * @param fh un objeto de FechaHistorica
  */
   FechaHistorica(const FechaHistorica &f);

   /**
  * @brief Sobrecarga del operador =
  * 
  * @param fh un objeto de FechaHistorica
  */
   FechaHistorica &operator=(const FechaHistorica &f);

   // Completar ...
};

/**
  * @brief Sobrecarga del operador <<
  */
std::ostream &operator<<(std::ostream &os, const FechaHistorica &f);

/**
  * @brief Sobrecarga del operador >>
  */
std::istream &operator>>(std::istream &is, FechaHistorica &f);

#endif
