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

int main (int argc, char* argv[]) {
  std::multimap<char, int> aux1;
  std::string archivo = argv[1];
  std::ifstream fa{archivo};
  Automata conjunto;
  std::string linea;
  Alfabeto alphabet;
  int contador = 0;
  getline(fa,linea);
  std::set<char> aux;
  for (int i = 0; i < linea.length(); i++){
    aux.insert(linea.at(i));
    alphabet.set_set(aux);
  }
  int nestado;
  fa >> nestado;
  //std::cout << nestado << std::endl; 
  conjunto.set_n_estados(nestado);

  int inicial;
  fa >> inicial;
  //std::cout << "Inicial " <<inicial << std::endl;
  conjunto.set_estado_inicial(inicial);
  //while(getline(fa, linea)){
  int n_estado;
  while(fa >> n_estado) {
    //std::cout << "while" << std::endl;
    bool aceptacion;
    int transiciones;
    std::multimap<char, int> transiciones_x;
    fa >> aceptacion >> transiciones;
    // std::cout << n_estado << " " << aceptacion << " " << transiciones << std::endl;
    Estado estado_n(transiciones_x, aceptacion, transiciones, n_estado);
    conjunto.Add_estado(estado_n);
    conjunto.get_conjunto_de_estados()[n_estado].set_transiciones(transiciones);
    conjunto.get_conjunto_de_estados()[n_estado].set_aceptacion(aceptacion);
    //std::cout << conjunto.get_conjunto_de_estados()[n_estado].get_transiciones() << " X " << conjunto.get_conjunto_de_estados()[n_estado].get_aceptacion() << std::endl;
    for(int i = 0; i < transiciones; i++){
      char simbolo;
      int estado_siguiente;
      fa >> simbolo >> estado_siguiente;
      //std::cout << "Simbolo " << simbolo << " NextQ" << estado_siguiente << std::endl;
      conjunto.get_conjunto_de_estados()[n_estado].set_multimap(simbolo,estado_siguiente);
      aux1.emplace(simbolo,estado_siguiente);  
    }
  }
  std::string archivo2 = argv[2];
  std::ifstream cadenas{archivo};
  std::vector<Estado> estados_actuales;
  estados_actuales.emplace_back(conjunto.get_conjunto_de_estados()[inicial]);
  std::string line;
  //while(getline(cadenas,line)){
    bool encontrado = false;
    int siguiente = inicial;
    //std::cout << conjunto.get_conjunto_de_estados()[inicial].get_siguiente_estado().size();
    //std::cout << conjunto.get_conjunto_de_estados().size();
    conjunto.print();
    //for (std::multimap<char, int>::iterator it = aux1.begin(); it != aux1.end(); it++) {
      //std::cout << it->first << " -> "<< it->second << std::endl;
    //}  
    //}
}
