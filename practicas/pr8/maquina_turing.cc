#include "maquina_turing.h"

Turing::Turing(int arranque, int aceptacion, int n_estados,std::vector<Transicion> transiciones,Tape cinta) {
  estado_de_arranque_ = arranque;
  estado_de_aceptacion_ = aceptacion;
  transiciones_ = transiciones;
  numero_de_estados = n_estados;
  cinta_ = cinta;
}

Tape Turing::get_cinta(){
  return cinta_;
}
int Turing::get_estado_arranque(){
  return estado_de_arranque_;
}
int Turing::get_estado_aceptacion(){
  return estado_de_aceptacion_;
}
int Turing::get_numero_de_estados(){
  return numero_de_estados;
}
std::vector<Transicion> Turing::get_transiciones(){
  return transiciones_;
}
void Turing::print(){
  std::cout << numero_de_estados << std::endl;
  std::cout << estado_de_arranque_ << std::endl;
  std::cout << estado_de_aceptacion_ << std::endl;
  std::cout << transiciones_.size() << std::endl;
  for ( auto transicion : transiciones_ ) {
    std::cout << transicion.get_estado_inicial();
    std::cout << transicion.get_simbolo_read();
    std::cout << transicion.get_simbolo_write();
    std::cout << transicion.get_movimiento();
    std::cout << transicion.get_estado_siguiente();
    std::cout << "" << std::endl;
  }
  cinta_.print_cinta(2);
}