// University of La Laguna
// College of Engineering and Tech
// Degree of Computer Science
// Subject: Computabilidad y Algoritmia (CyA)
// Course/Year: 2º 
// @praxis: Number 5 CyA - "Sets"
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

DFA::DFA() {}

DFA::~DFA() {}

DFA::DFA(std::string sequence, std::string pattern) {
  SetPattern(pattern);
  SetSequence(sequence);

}

std::string DFA::GetPattern(void) {
  return pattern_;
}

void DFA::SetPattern(std::string& pattern) {
  pattern_ = pattern;
}

std::string DFA::GetSequence(void) {
  return sequence_;
}

void DFA::SetSequence(std::string& sequence) {
  sequence_ = sequence;
}

#endif