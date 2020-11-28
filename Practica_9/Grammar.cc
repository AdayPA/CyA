// University of La Laguna
// College of Engineering and Tech
// Degree of Computer Science
// Subject: Computabilidad y Algoritmia (CyA)
// Course/Year: 2º 
// @praxis: Number 7 CyA - "DFA"
// @author: Aday Padilla Amaya
// @e-mail: alu0100843453@ull.edu.es
// @date: 04/11/2020
// @brief DFA.cc :  This is the implementation of .h
// @compile: $ make
// References:
// References:
// https://en.wikipedia.org/wiki/Deterministic_finite_automaton
// Lab exercise:
// (private link)
// Others links:
//  https://stackoverflow.com/questions/14975737/regular-expression-to-remove-comment
//  https://regexr.com/5gecl
// Version Control:
// 23/11/2020 - First version of the code

#ifndef PRACTICA_9_DFA_CC_
#define PRACTICA_9_DFA_CC_

#include "Grammar.h"

#include <iostream>
#include <fstream>

Grammar::Grammar() {  
  /// @brief we set the bools to false as init
  alphabet_2 = alphabet_;
}

Grammar::~Grammar() {}

void Grammar::Test(void) {
  std::cout << "Test de Grammar" << std::endl;
}

void Grammar::Print(void) {
  std::cout << "Tamaño (desde grammar): " << alphabet_2.size()  << std::endl;
 for (auto it = alphabet_2.begin(); it != 
                             alphabet_2.end(); ++it)
        std::cout << ' ' << *it;
}

#endif  // PRACTICA_9_DFA_CC_
