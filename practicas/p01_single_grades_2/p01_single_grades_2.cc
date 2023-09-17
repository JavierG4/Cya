#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <sstream>
#include <map>
#include "p01_single_grades.h"
#include<vector.h>

void lectura(std::map<std::string,std::vector<float>>& mapa, std::string param){
  std::ifstream archivo{param};
  std::string texto;
  std::string alu;
  float nota;
  if (archivo.fail()) {
    std::cout << "No se puedo abrir el archivo";
    exit(1);
  }
  while(archivo >> alu >> nota) {        
    mapa[alu].insert(nota);
  }
}
void escritura(std::map<std::string,float>& mapa) {
  for (std::map<std::string,std::vector<float>>::iterator it=mapa.begin(); it!=mapa.end(); ++it) {   
    std::cout << it->first << " " << it->second << '\n';
  }
 }
