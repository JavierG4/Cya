
#include<iostream>
#include<stdlib.h>
#include<fstream>
#include <string.h>
#include <utility>
#include <set>
#include <vector>

#ifndef ALFABETO_H
#define ALAFABETO_H


class Alfabeto{
 public:
   void remove_set();                          // Brief@ funcion que se encarga de vaciar el set
                                               // parametros ninguno
   void print_set();    // Brief@ funcion que se encarga de imprimir el set
                                               // param1 Archivo de entrada, param2 archivo de salida
   std::set<char> get_set();                   // Brief@ funcion que se encarga de devolver el valor del set privado
                                               // parametros ninguno
   void set_set(std::set<char>);
 private:
   std::set<char> alfabeto_;                   //set, atributo privado
};
std::ostream& operator<<(std::ostream&,Alfabeto&);  // Sobrecarga de operador de salida, para imprimir los datos del set

#endif  // ALFABETO_H