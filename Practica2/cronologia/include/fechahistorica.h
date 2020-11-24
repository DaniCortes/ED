#ifndef _FECHAHISTORICA_H_
#define _FECHAHISTORICA_H_

#include <iostream>
#include <string>
#include "lista.h"

/**
 * @class FechaHistorica
 *
 * @brief T.D.A. FechaHistorica
 * 
 * Una instancia @e fh del tipo de datos abstracto @c FechaHistorica es un
 * objeto formado por un @c int que indica el año y una @c Lista de objetos
 * de tipo @c string que indica los eventos ocurridos en ese año
 * 
 * @author Daniel Cortés
*/

class FechaHistorica {
  private:
   /**
   * @page repConjunto Rep del TDA FechaHistorica
   *
   * @section invConjunto Invariante de la representación
   *
   * El invariante es \e num_datos>0
   *
   * @section faConjunto Función de abstracción
   *
   * Un objeto válido @e rep del TDA FechaHistorica representa una 
   * fecha histórica con 
   *
   *
   */
   int anio;                     /**< Año en el que los eventos ocurrieron */
   Lista<std::string> eventos;   /**< Lista de eventos */

  public:
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
   * 
   * @param eventos @c Lista de eventos ocurridos en ese año
   */
   FechaHistorica(const int anio, const Lista<std::string> eventos);

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
   * @brief Sobrecarga del operador =
   * 
   * @param fh @c FechaHistorica usada para asignar el objeto implícito
   */
   FechaHistorica& operator=(const FechaHistorica &f);

   /**
   * @brief Sobrecarga del operador +
   * 
   * @param fh @c FechaHistorica a sumar con el objeto implícito
   */
   FechaHistorica operator+(const FechaHistorica &f);

   /** @brief Sobrecarga del operador <
   * 
   * @param fh @c FechaHistorica a comparar con el objeto implícito
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

   // Completar ...

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
