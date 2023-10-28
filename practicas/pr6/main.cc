#include<iostream>
#include<stdlib.h>
#include<fstream>
#include <string.h>
#include <utility>
#include <set>
#include <map>
#include <vector>
#include "estado.h"
#include "fa.h"
#include <algorithm>
#include <stack>

int main (int argc, char* argv[]) {
  /*if(argc < 3) {   // comprobar si escribieron parametros de entrada
    std::cout << "Para ejecutar el programa haga ./automata input.fa cadenas.txt " << std::endl;
    std::cout << "Pruebe ./automata --help para mas informacion. " << std::endl;
    return 0;
  }
  */
  std::string help_1 = argv[1];
  if(help_1 == "--help") {  // opcion para mostrar una breve ayuda sobre el comando
    std::cout << "Para ejecutar este programa necesitas un archivo input.fa en el que tienes definidos los datos de un autómata" << std::endl;
    std::cout << "Además necesitas un cadenas.txt en el que escribas cadenas para ver si pertenecen al autómata " << std::endl;
    std::cout << "Ya sabiendo eso puedes ejecutar el programa asi ./automata input.fa cadenas.txt " << std::endl;
    return 0;
  }
  std::string archivo = argv[1];
  std::ifstream fa{archivo};
  Automata conjunto;
  std::string linea;
  Alfabeto alphabet;
  int contador = 0;
  getline(fa,linea);
  std::set<char> aux;

  for (int i = 0; i < linea.length(); i++){ //Asigna el alfabeto
    aux.insert(linea.at(i));
  }
// Asignacion de valores del automata
  alphabet.set_set(aux);
  int nestado;
  fa >> nestado;
  conjunto.set_n_estados(nestado);
  int inicial;
  fa >> inicial;
  conjunto.set_estado_inicial(inicial);
  int n_estado;
// Asigancion de valores a estados y su posterior implementacion en el automata
  while (fa >> n_estado) {
    bool aceptacion;
    int transiciones;
    std::multimap<char, int> transiciones_x;
    fa >> aceptacion >> transiciones;
    for (int i = 0; i < transiciones; i++) {
      char simbolo;
      int estado_siguiente;
      fa >> simbolo >> estado_siguiente;
      transiciones_x.emplace(simbolo,estado_siguiente);
    }
    Estado estado_n(transiciones_x, aceptacion, transiciones, n_estado);
    conjunto.Add_estado(estado_n);
  }
  
}
