#include "gramatica.h"

Gramatica::Gramatica(char arranque ,Alfabeto alfabeto ,std::set<char> noterminales,std::multimap<char, std::string> transiciones){
    estado_arranque_ = arranque;
    alfabeto_ = alfabeto;
    noterminales_ = noterminales;
    producciones_ = transiciones;
}

char Gramatica::get_estado_arranque(){
    return estado_arranque_;
}
void Gramatica::set_estado_arranque(char arranque){
    estado_arranque_ = arranque;
}

Alfabeto Gramatica::get_alfabeto(){
    return alfabeto_;
}   
void Gramatica::set_alfabeto(Alfabeto alfabeto){
    alfabeto_ = alfabeto;
}

std::set<char> Gramatica::get_noterminales(){
    return noterminales_;
}
void Gramatica::set_noterminales(std::set<char> noterminales){
    noterminales_ = noterminales;
}

std::multimap<char, std::string> Gramatica::get_producciones(){
    return producciones_;
}
void Gramatica::set_producciones(std::multimap<char, std::string> transiciones){
    producciones_ = transiciones;
}

void Gramatica::print_out(std::string salida){
  std::ofstream out{salida};
  out << std::endl;
  auto set = noterminales_;
  auto iterador = set.begin();
  for(int i = 0; i < set.size(); ++i) {
    char no_terminal = *iterador;
    auto encontrar = producciones_.find(no_terminal);
    if(encontrar != producciones_.end()) {
      auto rango = producciones_.equal_range(no_terminal);
      out << no_terminal << "---> ";
      for(auto it = rango.first; it != rango.second; ++it) {
        out << it -> second;
        if(std::next(it) != rango.second) {
          out << "|";
        }
      }
      out << std::endl;
    }
    ++iterador;
  }
  out << "-------------------------\n";

}

void Gramatica::print(){
  std::cout << "El estado de arranque es " << estado_arranque_ << std::endl;
  auto aux = alfabeto_.get_set();
  std::cout << "Estos son los no terminales" << std::endl;
  for ( char terminales: aux){
    std::cout << terminales << " ";
  }
  std::cout << " " << std::endl;
  std::cout << "Estos son los terminales " << std::endl;
  for(char notermin : noterminales_){
    std::cout << notermin << " ";
  }
  std::cout << "\n";
  std::set<char> set = noterminales_;
  auto iterador = set.begin();
  for(int i = 0; i < set.size(); ++i) {
    char no_terminal = *iterador;
    auto encontrar = producciones_.find(no_terminal);
    if(encontrar != producciones_.end()) {
      auto rango = producciones_.equal_range(no_terminal);
      std::cout << no_terminal << "---> ";
      for(auto it = rango.first; it != rango.second; ++it) {
        std::cout << it -> second;
        if(std::next(it) != rango.second) {
          std::cout << "|";
        }
      }
      std::cout << std::endl;
    }
    ++iterador;
  }
  std::cout << "-------------------------\n";
}
// A ++ B ++ C ++ 
char Gramatica::buscar_identificador() {
  char identificador = 'A';
  for (auto alfabeto : get_noterminales()) {
    if ( identificador != alfabeto ){
      return identificador;
    }
    else {
      identificador++;
    }
  }
  return identificador;
}

std::set<char> Gramatica::producciones_terminales(){
  std::set<char> resultado;
  for (auto it = producciones_.begin(); it != producciones_.end(); ++it) {
    for (char a : alfabeto_.get_set()){
      if ( it->second[0] == a && it->second.size() == 1) {
        resultado.insert(it->second[0]);
      }
    }
  }
  return resultado;
}

void Gramatica::transoformacion_a_chomksy(){
  for (auto it = producciones_.begin(); it != producciones_.end(); ++it) {
    if (it->second == "&") {
      std::cout << "La gramática contiene & transiciones "<< it->first << " -> " << it->second << std::endl;
      return;
    }
    if (it->second.size() == 1) {
      for (auto termin: get_noterminales()) {
        for(auto aux2 : it -> second) {
          if ( aux2 == termin ){
            std::cout << "Tiene producciones unitarias en " << it->first << " -> " << termin << std::endl;
            return;
          }
        }
      }
    }
  }
  for (auto it1 = producciones_.begin(); it1 != producciones_.end(); ++it1) {
    int tam = it1->second.size(); // Tamaño string
    //std::cout << "Nueva comprobacion " << std::endl;
    //std::cout << it1->second << std::endl;
    if ( tam >= 2 ) {
      for (auto iterador: it1->second ) { // Compruebo los char de la string para ver si hay terminales
        for (auto termin : alfabeto_.get_set()) { // Compruebo el set de los terminales
          //std::cout << iterador << termin << std::endl;
          if (iterador == termin) { // Si es un terminal lo que hay en la string 
            //std::cout << "Si" << std::endl;
            bool encontrado = 0;
            std::set<char> terminales_solos = producciones_terminales();
            auto it = terminales_solos.find(iterador);
            if ( it == terminales_solos.end() ) { 
              char identi = buscar_identificador();
              noterminales_.insert(identi);
              std::string aux4;
              aux4 += iterador;
              producciones_.emplace(identi, aux4);
            }
          }
        }
      }
    }
  }
  remplazar();
  std::string prox_cadenas;
  std::string cadenas_actuales;
  for (auto elemento : noterminales_ ) {
    auto rango = producciones_.equal_range(elemento);
    for (auto it = rango.first; it != rango.second;) {  // revisar cadenas mayores o iguasles que tres
      prox_cadenas = "";
      cadenas_actuales = "";
      std::string cadena = it -> second;
      if (cadena.size() < 3) {
        ++it;
        continue;
      }
      std::string letras = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
      bool pertenece = 0;
      for (int i = 0; i < cadena.size() -2; ++i) {
        for (int j = 0; j < letras.size(); ++j) {
          pertenece = 0;
          for (auto elemento : noterminales_ ) {
            if (elemento == letras[j]) {
              pertenece = 1;
              break;
            }
          }
          if (!pertenece) {
            prox_cadenas += letras[j];
            noterminales_.insert(letras[j]);  // crear no terminales necesarios
            break;
          }
        }
      }
      for (int i = 0; i < cadena.size(); ++i) {
        cadenas_actuales += cadena[i];   // meter en una string los no terminales que ya estaban 
      }
      std::string cadenas = "";
      for (int i = 0; i < cadenas_actuales.size() - 1; ++i) {  // algoritmo para sustitur y reemplazar unas producciones por otras
        cadenas = "";
        if (i == 0) {
          cadenas += cadenas_actuales[0];
          cadenas += prox_cadenas[0];
          producciones_.emplace(it -> first, cadenas);
          continue;
        }
        if (i == cadenas_actuales.size() - 2) {
          cadenas += cadenas_actuales[i];
          cadenas += cadenas_actuales[i + 1];
          producciones_.emplace(prox_cadenas[i - 1], cadenas);
          break;
        }
        cadenas += cadenas_actuales[i];
        cadenas += prox_cadenas[i];
        producciones_.emplace(prox_cadenas[i - 1], cadenas);            
      }
      it = producciones_.erase(it);  // borrar produccion de tamaÃ±o >= 3
    }
  }
}

void Gramatica::remplazar(){
  for (auto it = producciones_.begin(); it != producciones_.end(); ++it) {
    for (auto terminal : alfabeto_.get_set()) {
      if ( it->second[0] == terminal && it->second.size() == 1) {
        for (auto it2 = producciones_.begin(); it2 != producciones_.end(); ++it2) {
          for (char aux : it2->second ){ 
            if ( it2->second.size() > 1 && aux == terminal) {
              std::replace(it2->second.begin(), it2->second.end(), terminal ,it->first);
            }
          } 
        }
      }
    }
  }
}

std::ostream& operator<<(std::ostream& out, Gramatica& a) {
  out << std::endl;
  Alfabeto alfabeto = a.get_alfabeto();
  auto set = a.get_noterminales();
  auto iterador = set.begin();
  for(int i = 0; i < set.size(); ++i) {
    char no_terminal = *iterador;
    auto encontrar = a.get_producciones().find(no_terminal);
    if(encontrar != a.get_producciones().end()) {
      auto rango = a.get_producciones().equal_range(no_terminal);
      out << no_terminal << "---> ";
      for(auto it = rango.first; it != rango.second; ++it) {
        out << it -> second;
        if(std::next(it) != rango.second) {
          out << "|";
        }
      }
      out << std::endl;
    }
    ++iterador;
  }
  out << "-------------------------\n";
  return out;
}
