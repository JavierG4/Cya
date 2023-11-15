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
   // @brief Contructor con parametros
   // @param string que contiene la cinta 
   // @param alfabeto de la cinta
   Tape(std::string,Alfabeto);

   // @brief contructor por defecto
   Tape() = default;

   // @brief devuelve a donde apunta la cinta
   // @return int de adonde apunta la cinta
   int get_pointer();

   // @brief hace un --pointer
   void Left();

   // @brief hace un ++pointer
   void right();

   // @brief funcion que devuelve el char a donde esta apuntando la cinta
   // @return char a donde esta apuntando la cinta
   char read();

   // @brief funcion que escribe el char que le pasas donde esta apuntando la cinta
   // @param char que se va a escribir donde apunta la cinta
   void write(char);

   // @brief funcion que te devuelve la cinta
   // @return string de la cinta
   std::string get_cinta();

   // @brief funcion que devuelve el alfabeto de la cinta
   // @return alfabeto de la cinta
   Alfabeto get_alfabeto();

   // @brief funcion que imprime la cinta 
   // @param el estado en el que esta la MT
   void print_cinta(int);

 private:
   std::string cinta_;
   int pointer;
   Alfabeto alfabeto_cinta;
};

#endif  // TAPE_H