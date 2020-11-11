// University of La Laguna
// College of Engineering and Tech
// Degree of Computer Science
// Subject: Computabilidad y Algoritmia (CyA)
// Course/Year: 2º 
// @praxis: Number 6 CyA - "Sets"
// @author: Aday Padilla Amaya
// @e-mail: alu0100843453@ull.edu.es
// @date: 04/11/2020
// @brief DFA.cc :  This is the main of the praxis
//                 
// @compile: $ make                                                    
// References: 
// https://es.wikipedia.org/wiki/B%C3%BAsqueda_de_patrones
// https://es.wikipedia.org/wiki/ASCII
// Lab exercise:
// https://github.com/garamira/CyA-P06-Patterns
// Version Control:
// 04/11/2020 - First version of the code 
// 

#ifndef DFA_CC_
#define DFA_CC_

#include "DFA.h"

#include <iostream>
#include <fstream>

DFA::DFA() {
  alpha_ok_ = true;
  alphabet_.resize(0);
}

DFA::~DFA() {}

void DFA::SetAlphabet (std::string character) {
  //FILTRAR
  alphabet_.push_back(character);

}

void DFA::SetStates (std::string states) {
  //FILTRAR
  states_.push_back(states);
}

void DFA::SetStart (std::string start) {
  //FILTRAR
  start_ = start;
}

void DFA::SetAcceptStates (std::string state) {
  accept_states_.push_back(state);
}

void DFA::SetTransition (std::vector<std::string> transition) {
  Node* a = new Node {transition[0],transition[1],transition[2]};
  transitions_.push_back(a);
}

#endif