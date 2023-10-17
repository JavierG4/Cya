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
  }
  alphabet.set_set(aux);
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
    for(int i = 0; i < transiciones; i++){
      char simbolo;
      int estado_siguiente;
      fa >> simbolo >> estado_siguiente;
      //std::cout << "Simbolo " << simbolo << " NextQ" << estado_siguiente << std::endl;
      //conjunto.get_conjunto_de_estados()[n_estado].set_multimap(simbolo,estado_siguiente);
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
  while (getline(cadenas,line)){
    posicion = 0;
    int siguiente = inicial;
    estados_actuales.emplace_back(conjunto.get_conjunto_de_estados()[inicial]);
    std::set<char> alfabeto_cadena;
    bool encontrado = 0;
    while (line.length() > posicion) {
      for (int i = 0; i < estados_actuales.size(); i++){
        for (const int &elemento : conjunto.get_alfabeto().get_set()) {
          if (elemento == line[posicion]) { // comprobamos que el elemtno pertenece al alfabeto
            encontrado = 1;
            return 0;
          }
        }
        if (!encontrado) {
          std::cout << line << " --- Rejected" << std::endl;
          break;
        }
    }
    for (int i = 0; i < estados_actuales.size(); i++){
      for (const auto& par : estados_actuales.at(i).get_siguiente_estado()) {
        if(par.first == line[posicion]) {
          estados_siguientes.insert(conjunto.get_conjunto_de_estados()[par.second]);
        }
      }
    }
    estados_actuales.resize(0);
    for (int i = 0; i < estados_siguientes.size(); i++) {
      estados_actuales.insert(estados_siguientes.at(i));
    }
    estados_siguientes.resize(0);
    posicion++;
    }
    int aceptado = 0;
    for(int i = 0; i < estados_actuales.size(); i++) {
      if(estados_actuales.at(i).get_aceptacion() == 1){
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
