#include<iostream>
#include<stdlib.h>
#include<fstream>
#include <string.h>
#include <utility>
#include <set>
#include <map>
#include "alfabeto.h"
#include "estado.h"
#include <vector>

#ifndef FA_H
#define FA_H
class Automata {
 public:
   int get_n_estados();
   void set_n_estados(int);

   int get_estado_inicial();
   void set_estado_inicial(int);

   Alfabeto get_alfabeto();
   void set_alfabeto(Alfabeto);
   
   std::vector<Estado> get_conjunto_de_estados();
   void Add_estado(Estado);

  void print();
 private:
   int n_estados_;
   int estado_inicial_;
   std::vector<Estado> conjunto_de_estados_;
   //std::map<int> conjunto_de_aceptacion;
   Alfabeto alfabeto_;
};

#endif  // FA_H