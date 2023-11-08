#include "estado.h"

Estado::Estado(std::multimap<char, int> transiciones, bool aceptacion, int ntransiciones, int nestado){
  siguiente_estado_ = transiciones;
  aceptacion_ = aceptacion;
  transiciones_ = ntransiciones;
  n_estado_ = nestado;
  visitado_ = 0;
}

Estado::Estado(){
  siguiente_estado_ = std::multimap<char, int>();
  aceptacion_ = bool();
  transiciones_ = int();
  n_estado_ = int();
}

int Estado::get_n_estado() {
  return n_estado_;
}

void Estado::set_n_estado(int n_estado){
  n_estado_ = n_estado;
}

std::multimap<char,int> Estado::get_siguiente_estado(){
  return siguiente_estado_;
}

void Estado::set_multimap(char simbol,int next_estado){
  siguiente_estado_.insert(std::pair<char,int>(simbol,next_estado));
}


