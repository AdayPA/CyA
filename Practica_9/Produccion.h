// University of La Laguna
// College of Engineering and Tech
// Degree of Computer Science
// Subject: Computabilidad y Algoritmia (CyA)
// Course/Year: 2º
// @praxis: Number 9 CyA - "Gramaticas Regulares y Autómatas Finitos. Gramatica
//                          regular a partir de un DFA"
// @author: Aday Padilla Amaya
// @e-mail: alu0100843453@ull.edu.es
// @date: 23/11/2020
// @brief Transition.h :
// @compile: $ make
// References:
// https://en.wikipedia.org/wiki/Deterministic_finite_automaton
// Lab exercise:
// (private link)
// Others links:
//  https://stackoverflow.com/questions/14975737/regular-expression-to-remove-comment
//  https://regexr.com/5gecl
// Version Control:
// 23/11/2020 - First version of the code
//
//
//

#ifndef PRACTICA_9_PRODUCCION_H_  // PRACTICA_9_TRANSITION_H_
#define PRACTICA_9_PRODUCCION_H_

#include <string>
#include <vector>

class Produccion {
 private:
  struct Node {
    std::string init_state_;
    std::string symbol_;
    std::string final_state_;
  };
 public:
  Produccion();
  void Insert(std::string, std::string, std::string);
  inline int GetSize(void) {return set_produccion_.size();}
  inline Node* GetNode(int position) {return set_produccion_[position];}
  ~Produccion();
 private:
  std::vector<Node*> set_produccion_;
};

#endif  // PRACTICA_9_PRODUCCION_H_
