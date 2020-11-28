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
// @brief DFA.h :
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

#ifndef PRACTICA_9_GRAMMAR_H_
#define PRACTICA_9_GRAMMAR_H_

#include <string>
#include <vector>
#include <set>

#include "/home/usuario/cya/Practica_9/Set.h"
#include "/home/usuario/cya/Practica_9/DFA.h"

class Grammar : public DFA {
 public:
    Grammar();
    virtual ~Grammar();
    /*
      void SetAlphabet(std::string);
      void SetStates(std::string);
      void SetStart(std::string);
      void SetAcceptStates(std::string);
      inline std::set<std::string> GetAlphabet(void) {return alphabet_;}
      inline std::set<std::string> GetStates(void) {return states_;}
      inline std::set<std::string> GetAcceptStates(void) {return accept_states_;}
      inline Transition GetTransitions(void) {return transitions_;}
    */
    void Print(void);    
    void Test(void);

 private:
    std::set<std::string> alphabet_2;
    bool failed_;
    bool start_ok_;
    bool accept_states_ok_;
    bool transitions_ok;
    bool complete_;
    bool CheckStatus(void);
};

#endif  // PRACTICA_9_GRAMMAR_H_
