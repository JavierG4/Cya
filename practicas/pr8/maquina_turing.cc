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
  std::cout << "" << std::endl;
}

bool Turing::Existe_transicion(int estado, char lectura) {
  bool encontrado = false;
  for (Transicion transi : transiciones_ ) {
    if (transi.get_estado_inicial() == estado && transi.get_simbolo_read() == lectura) {
      encontrado = true;
    }
  }
  return encontrado;
}

char Turing::Right_or_left(int estado,char lectura) {
  char resultado;
  for (Transicion transi : transiciones_ ) {
    if (transi.get_estado_inicial() == estado && transi.get_simbolo_read() == lectura){
      resultado = transi.get_movimiento();
    }
  }
  return resultado;
}

int Turing::Siguiente_estado(int estado,char lectura) {
  int siguiente = 0;
  for (Transicion transi : transiciones_ ) {
    if (transi.get_estado_inicial() == estado && transi.get_simbolo_read() == lectura){
      siguiente = transi.get_estado_siguiente();
    }
  }
  return siguiente;
}

char Turing::Simbolo_write(int estado,char lectura) {
  char write;
  for (Transicion transi : transiciones_ ) {
    if (transi.get_estado_inicial() == estado && transi.get_simbolo_read() == lectura){
      write = transi.get_simbolo_write();
    }
  }
  return write;
}

void Turing::Simulate() {
  int estado_lectura = estado_de_arranque_;
  bool notransi = false;
  bool aceptado = false;
  cinta_.print_cinta(estado_lectura);
  while ( notransi == false && aceptado == false ) {
    char read = cinta_.read();
    bool encontrar_transicion = Existe_transicion(estado_lectura,read);
    if ( encontrar_transicion == false ) {
      notransi = true;
      cinta_.print_cinta(estado_lectura);
    }
    else {
      char aux = Right_or_left(estado_lectura,read);
      cinta_.write(Simbolo_write(estado_lectura,read));
      char r = 'R';
      char l = 'L';
      if ( aux == r ) {
        cinta_.right();
      }
      if ( aux == l ) {
        cinta_.Left();
      }
      estado_lectura = Siguiente_estado(estado_lectura,read);
      if ( estado_lectura == estado_de_aceptacion_ ) {
        aceptado = true;
      }
      cinta_.print_cinta(estado_lectura);
    }
  }
  if ( aceptado == true ){
    std::cout << "CADENA ACEPTADA" << std::endl;
  }
  if ( notransi == true) {
    std::cout << "CADENA RECHAZADA" << std::endl;
  }
}

