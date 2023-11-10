#include "transicion.h"

Transicion::Transicion(int inicial,int siguiente,char read,char write,char movimiento) {
  estado_inicial_ = inicial;
  estado_siguiente_ = siguiente;
  simbolo_read_ = read;
  simbolo_write_ = write;
  movimiento_ = movimiento;
}

int Transicion::get_estado_inicial(){
  return estado_inicial_;
}
int Transicion::get_estado_siguiente(){
  return estado_siguiente_;
}
char Transicion::get_simbolo_read(){
  return simbolo_read_;
}
char Transicion::get_simbolo_write(){
  return simbolo_write_;
}
char Transicion::get_movimiento(){
  return movimiento_;
}
