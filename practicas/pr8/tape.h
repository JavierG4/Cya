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
#ifndef TAPE_H
#define TAPE_H

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
#include "alfabeto.h"

class Tape {
 public:
   Tape(std::string,Alfabeto);
   Tape() = default;
   int get_pointer();
   void Left();
   void right();
   char read();
   void write(char);
   std::string get_cinta();
   Alfabeto get_alfabeto();
   void print_cinta(int);

 private:
   std::string cinta_;
   int pointer;
   Alfabeto alfabeto_cinta;
};

#endif  // TAPE_H