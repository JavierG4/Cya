#include<iostream>
#include<stdlib.h>
#include<fstream>
#include <string.h>
#include <utility>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <stack>
#include "maquina_turing.h"


int main (int argc, char* argv[]) {
  /*if(argc < 4) {   // comprobar si escribieron parametros de entrada
    std::cout << "Para ejecutar el programa haga ./automata input.fa cadenas.txt " << std::endl;
    std::cout << "Pruebe ./automata --help para mas informacion. " << std::endl;
    return 0;
  }
  
  */
  std::string help_1 = argv[1];
  if(help_1 == "--help") {  // opcion para mostrar una breve ayuda sobre el comando
    std::cout << "Para ejecutar este programa necesitas un archivo input.fa en el que tienes definidos los datos de un autómata" << std::endl;
    std::cout << "Además necesitas un cadenas.txt en el que escribas cadenas para ver si pertenecen al autómata " << std::endl;
    std::cout << "Ya sabiendo eso puedes ejecutar el programa asi ./automata input.fa cadenas.txt " << std::endl;
    return 0;
  }
  std::string archivo = argv[1];
  std::ifstream maquina{archivo};
  
  //Turing mt













}