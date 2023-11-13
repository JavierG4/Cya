#include <string.h>
#include<iostream>
int main(){
  std::string aux = "$";
  std::string mensaje = "mensaje";
  aux = aux + mensaje;
  aux = aux + "$";
  std::cout << aux;
}