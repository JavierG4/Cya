// Universidad de La Laguna
// Escuela Superior de Ingenier´ıa y Tecnolog´ıa
// Grado en Ingenier´ıa Inform´atica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Pr´actica 1: Contenedores asociativos
// Autor: Javier González Brito
// Correo: alu0101548197@ull.edu.es
// Fecha: 26/09/2023
// Archivo p02_stings.cc
// Contiene la funci´on main del proyecto que usa las clases X e Y
// Programa que le envias 3 parametros por línea de comando
// El primero es la entrada.txt, el segundo la salida.txt y el 3 sirve para decidir que tripo de operacion qieires realizar
// Enlaces de inter´es
// Historial de revisiones
// 20/09/2023 - Creaci´on (primera versi´on) del c´odigo


#include<iostream>
#include<stdlib.h>
#include<fstream>
#include <string.h>
#include <utility>
#include <set>
#ifndef ALFABETO_H
#define ALAFABETO_H
class Alfabeto {
 public:
   Alfabeto(std::string);                      // Contructor de la clase alfabeto
   void remove_set();                          // Brief@ funcion que se encarga de vaciar el set
                                               // parametros ninguno
   void print_set(std::string,std::string);    // Brief@ funcion que se encarga de imprimir el set
                                               // param1 Archivo de entrada, param2 archivo de salida
   std::set<char> get_set();                   // Brief@ funcion que se encarga de devolver el valor del set privado
                                               // parametros ninguno
 private:
   std::set<char> alfabeto_;                   //set, atributo privado
};
std::ostream& operator<<(std::ostream&,Alfabeto&);  // Sobrecarga de operador de salida, para imprimir los datos del set

#endif  // ALFABETO_H