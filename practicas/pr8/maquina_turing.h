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
   // @brief Devuelve la cinta
   // @return devuelve el objeto cinta de la clase
   Tape get_cinta();

   // @brief contructor con parametros
   // @param estado de arranque
   // @param estado de aceptacion
   // @param n estados
   // @param vector de transiciones
   // @param cinta
   Turing(int, int,int,std::vector<Transicion>,Tape);

   // @brief funcion que devuelve eel estado de arranque
   // @return int estado de arranque
   int get_estado_arranque();

   // @brief funcion que devuelve el estado de aceptacion
   // @return int estado de aceptacion
   int get_estado_aceptacion();
  
   // @brief funcion que devuelve el vector de transiciones
   // @return vector de trnansciones
   std::vector<Transicion> get_transiciones();

   // @brief devuelve el numero de estados
   // @return int del numero de estados
   int get_numero_de_estados();

   // @brief funcion que imprime la MT
   void print();

   // @brief Comprueba si existe una transicion para un estado y un char especifico
   // @param estado inicial de la trnasicion
   // @param char con el que transitas
   // @return bool de si existe o no la transicion
   bool Existe_transicion(int,char);

   // @brief devuelve el char write de una transicion con estado inicial x y char x
   // @param estado inicial de la trnasicion
   // @param char con el que transitas
   // @return char del write
   char Simbolo_write(int,char);

   // @brief devuelve el siguiente estado de una transicion con estado inicial x y char x
   // @param estado inicial de la trnasicion
   // @param char con el que transitas
   // @return int del siguiente estado
   int Siguiente_estado(int,char);

   // @brief Devuelve un char con el movimiento de una transicion especifica
   // @param estado inicial de la trnasicion
   // @param char con el que transitas 
   // @return char del movimiento
   char Right_or_left(int,char);

   // @brief funcion que te simula la maquina de turing con la cinta indicada
   void Simulate();
 private:
   int estado_de_arranque_;
   int estado_de_aceptacion_;
   std::vector<Transicion> transiciones_;
   int numero_de_estados;
   Tape cinta_;
};

#endif  // TURING_H