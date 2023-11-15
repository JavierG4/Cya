#include "tape.h"

Tape::Tape(std::string cadena,Alfabeto alfabeto){
  cinta_ = cadena;
  alfabeto_cinta = alfabeto;
  pointer = 1;
}

int Tape::get_pointer() {
  return pointer;
}

void Tape::Left() {
  pointer--;
  if ( pointer == 0 ) {
    std::string aux = "$";
    aux = aux + cinta_;
    cinta_ = aux;
    pointer++;
  }
}

char Tape::read() {
  return cinta_[pointer];
}

void Tape::right() {
  pointer++;
  if (pointer == cinta_.size() ) {
    std::string aux = "$";
    cinta_ = cinta_ + aux;
  }
}

void Tape::write(char a) {
  cinta_[pointer] = a;
}

std::string Tape::get_cinta() {
  return cinta_;
}

Alfabeto Tape::get_alfabeto(){
  return alfabeto_cinta;
}

void Tape::print_cinta(int estado){
  for ( int i = 0; i < cinta_.size(); i++) {
    if( pointer == i ) {
      std::cout << " q" << estado << " ";
    }
    std::cout << cinta_[i];
  }
  std::cout << "" << std::endl;
}