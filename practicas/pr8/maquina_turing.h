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

#ifndef TURING_H
#define TURING_H

#include<iostream>
#include<stdlib.h>
#include<fstream>
#include <string.h>
#include <utility>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <stack>
//#include "alfabeto.h"
#include "transicion.h"
#include "tape.h"

class Turing {
 public:
   Tape get_cinta();
   Turing(int, int,int,std::vector<Transicion>,Tape);
   int get_estado_arranque();
   int get_estado_aceptacion();
   std::vector<Transicion> get_transiciones();
   int get_numero_de_estados();
   void print();
   void print_cinta();
   bool Existe_transicion(int,char);
   char Simbolo_write(int,char);
   int Siguiente_estado(int,char);
   char Right_or_left(int,char);
   void Simulate();
 private:
   int estado_de_arranque_;
   int estado_de_aceptacion_;
   std::vector<Transicion> transiciones_;
   int numero_de_estados;
   Tape cinta_;
};

#endif  // TURING_H