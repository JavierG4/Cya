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
#ifndef STRINGS_H
#define STRINGS_H
class Cadena {
 public:
   void longitud(std::string,std::string);    // Brief@ funcion que se encarga decir la longitud de la cadena
                                              // param1 Archivo de entrada, param2 archivo de salida
   void inversa(std::string,std::string);     // Brief@ funcion que se encarga de invertir la cadena
                                              // param1 Archivo de entrada, param2 archivo de salida
   void prefijos(std::string,std::string);    // Brief@ funcion que se encarga de imprimir los prefijos de la cadena
                                              // param1 Archivo de entrada, param2 archivo de salida    
   void sufijos(std::string,std::string);     // Brief@ funcion que se encarga de imprimir los sujijos de la cadena
                                              // param1 Archivo de entrada, param2 archivo de salida
   // void todo(std::string,std::string);
   void concatenar(std::string);
 private:

};

#endif  // STRINGS_H