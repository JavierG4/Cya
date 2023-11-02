#include "gramatica.h"

Gramatica::Gramatica(char arranque ,Alfabeto alfabeto ,std::set<char> terminales,std::multimap<char, std::string> transiciones){
    estado_arranque_ = arranque;
    alfabeto_ = alfabeto;
    terminales_ = terminales;
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

std::set<char> Gramatica::get_terminales(){
    return terminales_;
}
void Gramatica::set_terminales(std::set<char> noterminales){
    terminales_ = noterminales;
}

std::multimap<char, std::string> Gramatica::get_producciones(){
    return producciones_;
}
void Gramatica::set_producciones(std::multimap<char, std::string> transiciones){
    producciones_ = transiciones;
}

void Gramatica::print(){
  std::cout << alfabeto_.get_set().size() << std::endl;
  for ( char terminales: alfabeto_.get_set()){
    std::cout << terminales << std::endl;
  }
  std::cout << terminales_.size() << std::endl;
  for(char notermin : terminales_){
    std::cout << notermin << std::endl;
  }
  std::cout
  for (auto it = producciones_.begin(); it != producciones_.end(); ++it) {
    std::cout << it->first << " " << it->second << std::endl;
  }
}
// A ++ B ++ C ++ 
char Gramatica::buscar_identificador() {
  char identificador = 'A';
  for (auto alfabeto : alfabeto_.get_set()) {
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
    for (char a : terminales_){
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
      for (auto termin: alfabeto_.get_set()) {
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
        for (auto termin : terminales_) { // Compruebo el set de los terminales
          //std::cout << iterador << termin << std::endl;
          if (iterador == termin) { // Si es un terminal lo que hay en la string 
            //std::cout << "Si" << std::endl;
            bool encontrado = 0;
            std::set<char> terminales_solos = producciones_terminales();
            auto it = terminales_solos.find(iterador);
            if ( it == terminales_solos.end() ) { 
              char identi = buscar_identificador();
              alfabeto_.set_valor(identi);
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
  print();
  std::string prox_cadenas;
  std::string cadenas_actuales;
  for (auto elemento : alfabeto_.get_set() ) {
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
          for (auto elemento : alfabeto_.get_set() ) {
            if (elemento == letras[j]) {
              pertenece = 1;
              break;
            }
          }
          if (!pertenece) {
            prox_cadenas += letras[j];
            alfabeto_.set_valor(letras[j]);  // crear no terminales necesarios
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
    for (auto terminal : terminales_) {
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


/*std::ostream& operator<<(std::ostream& out, Gramatica& a) {
  std::cout <<std::endl;
  Alfabeto alfabeto = a.GetAlfabeto();
  std::set<char> set = a.GetNoTerminales();
  auto iterador = set.begin();
  for(int i = 0; i < set.size(); ++i) {
    char no_terminal = *iterador;
    auto encontrar = produccionesS.find(no_terminal);
    if(encontrar != produccionesS.end()) {
      auto rango = produccionesS.equal_range(no_terminal);
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
  return out;
}
*/