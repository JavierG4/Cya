// Universidad de La Laguna
// Escuela Superior de Ingenier´ıa y Tecnolog´ıa
// Grado en Ingenier´ıa Inform´atica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Pr´actica 5:mplementación de un simulador de autómatas finitos 
// Autor: Javier González Brito
// Correo: alu0101548197@ull.edu.es
// Fecha: 17/09/2023
// Archivo alfabeto.h
// Contiene la implementacion de la clase estado
// Enlaces de inter´es
// Historial de revisiones
// 14/09/2023 - Creaci´on (primera versi´on) del c´odigo

#include<iostream>
#include<stdlib.h>
#include<fstream>
#include <string.h>
#include <utility>
#include <set>
#include <map>
#include <vector>
#ifndef ESTADO_H
#define ESTADO_H

class Estado {
 public:
   Estado(std::multimap<char, int>, bool, int, int);            //@brief Constructor de la clase con parametros
                                                                //@Params :
                                                                //@Param1: Es un multimap que contiene <char,int> para guardar las transciones de estado
                                                                //@Param2: Es un bool para guardar la aceptacion
                                                                //@Param3: Es un int para saber el numero de transiciones que tiene el estado
                                                                //@Param4: Es un int con el numero de estado que es
                                                                //@Return no devuelve nada

   Estado();                                                    // contructor por dedecto

   int get_n_estado();          //@brief Funcion que devuelve el n_estado
                                //@Params no parametros
                                //@Return devuelve un int que es el numero del estado 

   void set_n_estado(int);        //@brief Funcion que hace set de los n_estados
                                  //@Params un int para poner su n_estado
                                  //@Return no devuelve nada

   std::multimap<char, int> get_siguiente_estado();

   void set_multimap(char,int);         //@brief Funcion que hace set del multimap de transiciones
                                        //@Params un char y un int para el simbolo y el siguiente estado
                                        //@Return no devuelve nada

   void set_siguiente_estado(std::multimap<char, int>);         //@brief Funcion que hace set del multimap de transiciones
                                                                //@Params un multimap que contiene un char para simbolos y otro para el estado siguiente con int
                                                                //@Return no devuelve nada

   int get_transiciones();        //@brief Funcion que devuelve las n transiciones del estado
                                  //@Params no parametros
                                  //@Return devuelve un int que son el numero de transciones que tiene el estado

   void set_transiciones(int);    //@brief Funcion que hace set de las transiciones
                                  //@Params un int para poner sus n transiciones
                                  //@Return no devuelve nada
   
   bool get_aceptacion();         //@brief Funcion que devuelve la aceptacion
                                  //@Params no parametros
                                  //@Return devuelve un bool con la aceptacion

   void set_aceptacion(bool);     //@brief Funcion que hace set de la aceptacion
                                  //@Params un bool para hacer set de la aceptacion
                                  //@Return no devuelve nada
   bool Visitado();

   void set_visitado(bool);

 private:
   std::multimap<char, int> siguiente_estado_;
   int transiciones_;
   int n_estado_;
   bool aceptacion_;
   bool visitado_;
};

#endif  // ESTADO_H