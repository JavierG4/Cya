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

int main (int argc, char* argv[]) {
  if(argc < 2) {   // comprobar si escribieron parametros de entrada
    std::cout << "Para ejecutar el programa haga ./automata input.fa cadenas.txt " << std::endl;
    std::cout << "Pruebe ./automata --help para mas informacion. " << std::endl;
    return 0;
  }
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
  while(fa >> n_estado) {
    bool aceptacion;
    int transiciones;
    std::multimap<char, int> transiciones_x;
    fa >> aceptacion >> transiciones;
    for(int i = 0; i < transiciones; i++){
      char simbolo;
      int estado_siguiente;
      fa >> simbolo >> estado_siguiente;
      transiciones_x.emplace(simbolo,estado_siguiente);
    }
    Estado estado_n(transiciones_x, aceptacion, transiciones, n_estado);
    conjunto.Add_estado(estado_n);
  }

  std::string archivo2 = argv[2];
  std::ifstream cadenas{archivo2};
  std::vector<Estado> estados_actuales;
  std::vector<Estado> estados_siguientes;
  std::string line;
  int posicion;
  //conjunto.print();
  //Inicio del algoritmo
  while (getline(cadenas,line)){ // leemos cadena por cadena
    int aceptado = 0;
    posicion = 0;
    estados_actuales.resize(0);
    estados_actuales.push_back(conjunto.get_conjunto_de_estados()[inicial]);
    while (line.length() > posicion) { // Vamos leyendo signo por signo de la cadena
      bool encontrado = 0;
      for (int i = 0; i < estados_actuales.size(); i++){
        for (const char &elemento : aux) { // Comprobamos si el simbolo pertenece al alfabeto o es &
          if (elemento == line[posicion] || line[posicion] == '&' ) { 
            encontrado = 1;
            break;
          }
        }
        if (!encontrado) {
          std::cout << line << " --- Rejected" << std::endl;
          break;
        }
        std::multimap <char, int > map = estados_actuales[i].get_siguiente_estado();  // Apartir de aquí recorremos los estados actuales uno por uno y vemos sus transiciones
        auto rango = map.equal_range(line[posicion]);  
        auto encontrar = map.find('&');
        if(encontrar != map.end()) {
          auto rango_ = map.equal_range('&'); 
          for (auto it_ = rango.first; it_ != rango.second; ++it_) {
            estados_siguientes.push_back(conjunto.get_conjunto_de_estados()[it_ -> second]); 
          }
        }
        for (auto it = rango.first; it != rango.second; ++it) {
          estados_siguientes.emplace_back(conjunto.get_conjunto_de_estados()[it -> second]); 
        }
      }
      estados_actuales.resize(estados_siguientes.size());
      for (int i = 0; i < estados_siguientes.size(); i++) {
        estados_actuales[i] = estados_siguientes[i];
    }
      //std::cout << estados_actuales.size() << std::endl;
      estados_siguientes.resize(0);
      posicion++;
    }
    for(int i = 0; i < estados_actuales.size(); i++) {
      if(estados_actuales[i].get_aceptacion() == 1){
        aceptado = 1;
      }
    }
    if (aceptado == 0 ) {
      std::cout << line << " --- Rejected " << std::endl;
    }
    else if ( aceptado == 1 ){
      std::cout << line << " ---  Accepted " << std::endl;
    }
    estados_actuales.resize(0);
  }
}
