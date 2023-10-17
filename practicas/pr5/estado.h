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
   Estado(std::multimap<char, int>, bool, int, int);
   int get_n_estado();
   void set_n_estado(int);

   std::multimap<char, int> get_siguiente_estado();
   void set_multimap(char,int);
   void set_siguiente_estado(std::multimap<char, int>);

   int get_transiciones();
   void set_transiciones(int);
   
   bool get_aceptacion();
   void set_aceptacion(bool);

   void Reset();
 private:
   std::multimap<char, int> siguiente_estado_;
   int transiciones_;
   int n_estado_;
   bool aceptacion_;
};

#endif  // ESTADO_H