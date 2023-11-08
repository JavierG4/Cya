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
// Contiene la implementacion de la clase alfabeto
// Enlaces de inter´es
// Historial de revisiones
// 14/09/2023 - Creaci´on (primera versi´on) del c´odigo

#include<iostream>
#include<stdlib.h>
#include <string.h>
#include <utility>
#include <set>
#include <vector>
#include "alfabeto.h"
#include <string.h>
#include <map>
#include <vector>
#include <algorithm>

#ifndef GRAMATICA_H
#define GRAMATICA_H


class Gramatica{
 public:
   //@brief Constructor de la clase
   //@Params1 un char que es el estado de arranque
   //@Params2 Un alfabeto que es el alfabeto de la clase
   //@Params3 un set de char que contiene los noterminales
   //@Params4 Un multimap de char y string que contienen las producciones de la gramatica
   //@Return no devuelve nada
   Gramatica(char,Alfabeto,std::set<char>,std::multimap<char, std::string>); // Constructor

   //@brief Funcion que devuelve el estado de arranque
   //@Params no parametros
   //@Return devuelve un char que es el estado de arranque
   char get_estado_arranque();

   //@brief Funcion que hace set del estado de arranque
   //@Params un char
   //@Return no devuelve nada
   void set_estado_arranque(char);

   //@brief Funcion que devuelve el Alfabeto
   //@Params no parametros
   //@Return devuelve el Alfabeto
   Alfabeto get_alfabeto();

   //@brief Funcion que hace set del alfabeto 
   //@Params un Alfabeto
   //@Return no devuelve nada
   void set_alfabeto(Alfabeto);

   //@brief Funcion que devuelve un set de char con los no terminales
   //@Params no parametros
   //@Return devuelve los noterminales
   std::set<char> get_noterminales();

   //@brief Funcion que hace set de los noterminales
   //@Params un set de char
   //@Return no devuelve nada
   void set_noterminales(std::set<char>);

   //@brief Funcion que devuelve un multimap de char y strings que contiene las producciones
   //@Params no parametros
   //@Return devuelve un multimap de producciones
   std::multimap<char, std::string> get_producciones();

   //@brief Funcion que setea las producciones de la gramatica
   //@Params un multimap de char y string para introducir las producciones
   //@Return no devuelve nada
   void set_producciones(std::multimap<char, std::string>);

   //@brief Funcion que imprime por pantalla la gramatica
   //@Params no parametros
   //@Return no devuelve nada
   void print();

   //@brief Funcion que imprime en el out la gramatica
   //@Params donde lo imprime
   //@Return no devuelve nada
   void print_out(std::string);

   //@brief Funcion que transforma a chomksy una gramatica
   //@Params no parametros
   //@Return no devuelve nada
   void transoformacion_a_chomksy();

   //@brief Funcion que devuelve un identificador que no este en uso
   //@Params no parametros
   //@Return devuelve un char
   char buscar_identificador();

   //@brief Funcion que devuelve un set de los terminales que estan ya de esta forma A -> b
   //@Params no parametros
   //@Return devuelve un set de char
   std::set<char> producciones_terminales();

   //@brief Funcion que remplaza los terminales por los noterminales de esta forma A -> b en la gramatica
   //@Params no parametros
   //@Return no devuelve
   void remplazar();
 private:
   char estado_arranque_;
   Alfabeto alfabeto_; // Terminales
   std::set<char> noterminales_; // Noterminales
   std::multimap<char, std::string> producciones_;
};
  std::ostream& operator<<(std::ostream&,Gramatica&);

#endif  // GRAMATICA_H