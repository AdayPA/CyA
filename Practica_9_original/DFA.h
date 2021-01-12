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

#ifndef PRACTICA_9_DFA_H_
#define PRACTICA_9_DFA_H_

#include <string>
#include <vector>
#include <set>

#include "/home/usuario/cya/Practica_9/Set.h"
#include "/home/usuario/cya/Practica_9/Transition.h"
#include "/home/usuario/cya/Practica_9/Grammar.h"

class Grammar;

class DFA {
 public:
    DFA();
    DFA(std::string);
    ~DFA();
    void SetAlphabet(std::string);
    void SetStates(std::string);
    void SetStart(std::string);
    void SetAcceptStates(std::string);
    void SetTransition(std::vector<std::string>);
    std::string GetStart(void) {return start_;}
    inline std::set<std::string> GetAlphabet(void) {return alphabet_;}
    inline std::set<std::string> GetStates(void) {return states_;}
    inline std::set<std::string> GetAcceptStates(void) {return accept_states_;}
    inline Transition GetTransitions(void) {return transitions_;}
    Grammar ConvertToGrammar(void);

 protected:
    std::set<std::string> alphabet_;
    std::set<std::string> states_;
    std::set<std::string> accept_states_;
    std::string start_;
    Transition transitions_;
    bool CheckStatus(void);

 private:
    bool failed_;
    bool start_ok_;
    bool accept_states_ok_;
    bool transitions_ok;
    bool complete_;
    void Complete(void);
};

#endif  // PRACTICA_9_DFA_H_
