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
  if(argc < 2) {   // comprobar si escribieron parametros de entrada
    std::cout << "Para ejecutar el programa haga ./Turing ejemplo.tm ejemplo.tape " << std::endl;
    std::cout << "Pruebe ./Turing --help para mas informacion. " << std::endl;
    return 0;
  }
  
  std::string help_1 = argv[1];
  if(help_1 == "--help") {  // opcion para mostrar una breve ayuda sobre el comando
    std::cout << "Para ejecutar este programa necesitas un archivo ejemplo.tm en el que tienes definidos los datos de una MT " << std::endl;
    std::cout << "Además necesitas un ejemplo.tape en el que escribas la cadena para ver si es aceptada por la MT " << std::endl;
    std::cout << "Ya sabiendo eso puedes ejecutar el programa asi ./Turing ejemplo.tm ejemplo.tape " << std::endl;
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
  int inicial;
  int transiciones_while = 0;
  std::set<int> contador_estados;
  while ( maquina >> inicial ) {
    contador_estados.insert(inicial);
    int siguiente;
    char read;
    char write;
    char movimiento;
    maquina >> read;
    maquina >> write;
    maquina >> movimiento;
    maquina >> siguiente;
    contador_estados.insert(siguiente);
    Transicion transicion_(inicial,siguiente,read,write,movimiento);
    transiciones.push_back(transicion_);
    transiciones_while++;
  }
  //std::cout << contador_estados.size() << " e " << std::endl;
  if ( transiciones_while != ntransiciones || contador_estados.size() != estados ) {
    std::cout << "Ha habido un error en la maquina de Turing escrita" << std::endl;
  }
  else {
    std::string archivo2 = argv[2];
    std::ifstream cadena2{archivo2};
    std::string cinta_cadena;
    cadena2 >> cinta_cadena;
    std::string aux = "$";
    aux = aux + cinta_cadena;
    aux = aux + "$";
    cinta_cadena = aux;
    std::set<char> alfabeto_cinta;
    for (auto letra : cinta_cadena) {
      alfabeto_cinta.insert(letra);
    }
    Alfabeto alfabeto;
    alfabeto.set_set(alfabeto_cinta);
    Tape cinta(cinta_cadena,alfabeto);
    Turing tm(arranque, aceptado ,estados, transiciones, cinta);
    tm.print();
    tm.Simulate();
  }
}
