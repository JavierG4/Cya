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
#ifndef TRANSICION_H
#define TRANSICION_H

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


class Transicion {
 public:
   // @brief Constructor de la clase
   // @param int del estado inicial
   // @param int del estado siguiente
   // @param char del simbolo que se lee
   // @param char del simbolo que se escribe
   // @param char del simbolo que hace el movimiento
   Transicion(int,int,char,char,char);

   // @brief Funcion que devuelve el estado inicial
   // @return int de estado inicial
   int get_estado_inicial();

   // @brief Funcion que devuelve el estado siguiente
   // @return int del estado siguiente
   int get_estado_siguiente();

   // @brief Funcion que devuelve el char read
   // @return char del read
   char get_simbolo_read();

   // @brief Funcion que devuelve el char del write
   // @return char del write
   char get_simbolo_write();

   // @brief Funcion que devuelve el char del movimiento
   // @return el char del movimiento
   char get_movimiento();

 private:
   int estado_inicial_;
   int estado_siguiente_;
   char simbolo_read_;
   char simbolo_write_;
   char movimiento_;
};


#endif  // TRANSICION