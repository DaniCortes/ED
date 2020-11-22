#ifndef _FECHAHISTORICA_H_
#define _FECHAHISTORICA_H_

#include <iostream>
#include <string>
#include "lista.h"

/**
* @class FechaHistorica
*
* @brief Completar
*
* @author Daniel Cortés
*/

class FechaHistorica {
   int anio;
   Lista<std::string> eventos;


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
   * @brief Constructor de la clase
   * 
   * @param anio el año de la fecha histórica
   * 
   * @param eventos la lista de eventos ocurridos en ese año
   */
   FechaHistorica(const int anio, const Lista<std::string> eventos);

   /**
   * @brief Destructor
   */
   ~FechaHistorica();

   /**
   * @brief Descriptor del año
   * @param anio un entero que indica el año
   */
   void setAnio(int anio);

   /**
   * @brief Consultor del año
   */
   int getAnio() const;

   /**
   * @brief Sobrecarga del operador =
   * 
   * @param fh un objeto de FechaHistorica
   */
   FechaHistorica& operator=(const FechaHistorica &f);

   /**
   * @brief Sobrecarga del operador +
   * 
   * @param fh un objeto de FechaHistorica
   */
   FechaHistorica operator+(const FechaHistorica &f);

   /** @brief Sobrecarga del operador <
   * 
   * @param fh un objeto de FechaHistorica
   */
   bool operator<(const FechaHistorica &f) const;

   /** @brief Sobrecarga del operador >
   * 
   * @param fh un objeto de FechaHistorica
   */
   bool operator>(const FechaHistorica &f) const;

   /** @brief Sobrecarga del operador ==
   * 
   * @param fh un objeto de FechaHistorica
   */
   bool operator==(const FechaHistorica &f) const;

   /** @brief Sobrecarga del operador !=
   * 
   * @param fh un objeto de FechaHistorica
   */
   bool operator!=(const FechaHistorica &f) const;

   // Completar ...

   /**
   * @brief Sobrecarga del operador <<
   */
   friend std::ostream &operator<<(std::ostream &os, const FechaHistorica &f);

   /**
  * @brief Sobrecarga del operador >>
  */
   friend std::istream &operator>>(std::istream &is, FechaHistorica &f);

   friend class Cronologia;
};





#endif
