#pragma once

#include <iostream>
#include <utility>
#include <vector>
#include <set>

#define MAX_SZ 3
#define MAX_PREC 0

namespace CyA {
  typedef std::pair<double, double> point; // Contiene ambas posiciones x e y 
  typedef std::pair<point, point> line; // No lo voy a usar en esta practica
  typedef std::vector<point> point_vector; // Es un vector de puuntos
  typedef std::pair<point, point> arc; // Una linea que va de punto a punto
  typedef std::pair<double, arc> weigthed_arc; // contiene el peso de un arco y el arco
  typedef std::vector<weigthed_arc> arc_vector; // Vector de pairs<double,arc>
  typedef std::set<point> point_collection; // set de 
  typedef std::vector<arc> tree;
};

std::ostream& operator<<(std::ostream& os, const CyA::point_vector& ps);
std::ostream& operator<<(std::ostream& os, const CyA::point& ps);

std::istream& operator>>(std::istream& is, CyA::point_vector& ps);
std::istream& operator>>(std::istream& is, CyA::point& ps);