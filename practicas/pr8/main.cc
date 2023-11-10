#include<iostream>
#include<stdlib.h>
#include<fstream>
#include <string.h>
#include <utility>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include "maquina_turing.h"

int main (int argc, char* argv[]) {
  /*if(argc < 4) {   // comprobar si escribieron parametros de entrada
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
  std::ifstream maquina{archivo};
  int estados;
  int arranque;
  int aceptado;
  maquina >> estados;
  maquina >> arranque;
  maquina >> aceptado;
  int ntransiciones;
  std::vector<Transicion> transiciones;
  maquina >> ntransiciones;
  for (int i = 0; i < ntransiciones; i++) {
    int inicial;
    int siguiente;
    char read;
    char write;
    char movimiento;
    maquina >> inicial;
    maquina >> read;
    maquina >> write;
    maquina >> movimiento;
    maquina >> siguiente;
    Transicion transicion_(inicial,siguiente,read,write,movimiento);
    transiciones.push_back(transicion_);
  }
  std::string archivo2 = argv[2];
  std::ifstream cadena2{archivo2};
  std::string cinta_cadena;
  cadena2 >> cinta_cadena;
  std::set<char> alfabeto_cinta;
  for (auto letra : cinta_cadena) {
    alfabeto_cinta.insert(letra);
  }
  Alfabeto alfabeto;
  alfabeto.set_set(alfabeto_cinta);
  Tape cinta(cinta_cadena,alfabeto);
  Turing tm(arranque, aceptado ,estados, transiciones, cinta);
  tm.print();
}
