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
   Gramatica(char,Alfabeto,std::set<char>,std::multimap<char, std::string>); // Constructor

   char get_estado_arranque();
   void set_estado_arranque(char);

   Alfabeto get_alfabeto();
   void set_alfabeto(Alfabeto);

   std::set<char> get_noterminales();
   void set_noterminales(std::set<char>);

   std::multimap<char, std::string> get_producciones();
   void set_producciones(std::multimap<char, std::string>);
   
   void print();

   void print_out(std::string);
   void transoformacion_a_chomksy();

   char buscar_identificador();
   
   std::set<char> producciones_terminales();
   void remplazar();
 private:
   char estado_arranque_;
   Alfabeto alfabeto_; // Terminales
   std::set<char> noterminales_; // Noterminales
   std::multimap<char, std::string> producciones_;
};
  std::ostream& operator<<(std::ostream&,Gramatica&);

#endif  // GRAMATICA_H