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
   Transicion(int,int,char,char,char);
   int get_estado_inicial();
   int get_estado_siguiente();
   char get_simbolo_read();
   char get_simbolo_write();
   char get_movimiento();

 private:
   int estado_inicial_;
   int estado_siguiente_;
   char simbolo_read_;
   char simbolo_write_;
   char movimiento_;
};


#endif  // TRANSICION