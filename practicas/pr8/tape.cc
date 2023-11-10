#include "tape.h"

Tape::Tape(std::string cadena,Alfabeto alfabeto){
  cinta_ = cadena;
  alfabeto_cinta = alfabeto;
}

int Tape::get_pointer() {
  return pointer;
}

void Tape::Left() {
  pointer--;
}

char Tape::read() {
  return cinta_[pointer];
}

void Tape::right() {
  pointer++;
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
  std::cout << "$";
  for ( int i = 0; i < cinta_.size(); i++) {
    std::cout << cinta_[i];
    if( pointer == i ) {
      std::cout << " q" << estado << " ";
    }
  }
  std::cout << "$";
}