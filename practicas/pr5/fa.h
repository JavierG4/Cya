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
   int get_n_estados();           //@brief Funcion que devuelve los n_estados
                                  //@Params no parametros
                                  //@Return devuelve un int que son el numero de estados del autómata

   void set_n_estados(int);       //@brief Funcion que hace un set del n_estado
                                  //@Params un int para hacer un set del n_estado
                                  //@Return no devuelve nada

   int get_estado_inicial();      //@brief Funcion que devuelve el estado inicial
                                  //@Params no parametros
                                  //@Return devuelve un int que es estado inicial

   void set_estado_inicial(int);  //@brief Funcion que hace set del estado inicial
                                  //@Params un int para hacer set del estado inicial
                                  //@Return no devuelve nada

   Alfabeto get_alfabeto();       //@brief Funcion que devuelve el alfabeto del autómata
                                  //@Params no parametros
                                  //@Return devuelve un el alfabeto del autómata

   void set_alfabeto(Alfabeto);   //@brief Funcion que hace set del alfabeto
                                  //@Params alfabeto que deseas que el automata tenga
                                  //@Return no devuelve nada
   
   std::vector<Estado> get_conjunto_de_estados();           //@brief Funcion que devuelve el vector de conjuntos de estado
                                                            //@Params no parametros
                                                            //@Return devuelve un vector que contiene estados
   void Add_estado(Estado);       //@brief Funcion añade un estado al conjunto de estados
                                  //@Params un estado que deseas añadir
                                  //@Return no devuelve nada

  void print();
 private:
   int n_estados_;                                // Numero de estados del automata
   int estado_inicial_;                           // estado inicial
   std::vector<Estado> conjunto_de_estados_;      //vector de estados
   //std::map<int> conjunto_de_aceptacion;
   Alfabeto alfabeto_;                            // Alfabeto del automata
};

#endif  // FA_H