#include "estado.h"

Estado::Estado(std::multimap<char, int> transiciones, bool aceptacion, int ntransiciones, int nestado){
  siguiente_estado_ = transiciones;
  aceptacion_ = aceptacion;
  transiciones_ = ntransiciones;
  n_estado_ = nestado;
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

int Estado::get_transiciones() {
  return transiciones_;
}

void Estado::set_transiciones(int transiciones) {
  transiciones_ = transiciones;
}

bool Estado::get_aceptacion(){
  return aceptacion_;
}

void Estado::set_aceptacion(bool aceptacion) {
  aceptacion_ = aceptacion;
}

void Estado::set_siguiente_estado(std::multimap<char, int> siguiente_estado){
  siguiente_estado_ = siguiente_estado;

}

void Estado::Reset() {
  transiciones_ = 0;
  n_estado_ = 0;
  aceptacion_ = 0;
  siguiente_estado_.clear();
}