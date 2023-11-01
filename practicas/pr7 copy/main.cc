#include<iostream>
#include<stdlib.h>
#include<fstream>
#include <string.h>
#include <utility>
#include <set>
#include <map>
#include <vector>
#include "gramatica.h"
#include <algorithm>
#include <stack>

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
  std::ifstream gra{archivo};
  int noterminales = 0;
  gra >> noterminales;
  std::set<char> setterminales;
  for (int i = 0; i < noterminales; i++) {
    char notermin;
    gra >> notermin;
    setterminales.insert(notermin);
  }
  int terminales = 0;
  gra >> terminales;
  std::set<char> alfabeto;
  for (int i = 0; i < terminales; i++){
    char termin;
    gra >> termin;
    alfabeto.insert(termin);
  }
  int producciones;
  gra >> producciones;
  producciones = producciones -1;
  char arranque;
  Alfabeto alfabet;
  std::multimap<char, std::string> produccionesmap;
  std::string arranque_string;
  gra >> arranque;
  gra >> arranque_string;
  alfabeto.insert(arranque);
  produccionesmap.emplace(arranque,arranque_string);
  for (int i = 0; i < producciones; i++){
    char noterminal;
    std::string produccion;
    gra >> noterminal;
    gra >> produccion;
    produccionesmap.emplace(noterminal,produccion);
  }
  alfabet.set_set(setterminales);
  Gramatica gramatica(arranque,alfabet,alfabeto,produccionesmap);
  //std::cout << gramatica;
  gramatica.print();
  gramatica.transoformacion_a_chomksy();;
  std::string salida = argv[2];
  gramatica.print_out(salida);
  //out << gramatica.get_alfabeto();
  //salir << gramatica;
} 
