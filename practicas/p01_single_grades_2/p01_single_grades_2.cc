#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <sstream>
#include <map>
#include "p01_single_grades_2.h"
#include<vector>

void lectura2(std::map<std::string,std::vector<float>>& mapa, std::string param){
  std::ifstream archivo{param};
  std::string texto;
  std::string alu;
  float nota;
  if (archivo.fail()) {
    std::cout << "No se puedo abrir el archivo";
    exit(1);
  }
  while(archivo >> alu >> nota) {        
    mapa[alu].emplace_back(nota);
  }
}
void escritura2(std::map<std::string,std::vector<float>>& mapa) {
  for (std::map<std::string,std::vector<float>>::iterator it=mapa.begin(); it!=mapa.end(); ++it) {
    std::cout << it->first << " ";
    for(int j = 0;j < mapa[it->first].size();j++){
      std::cout << it->second.at(j) << " ";
    }
    std::cout << '\n';
  }
 }
