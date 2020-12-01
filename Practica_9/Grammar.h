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
// @brief DFA.h : This
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
#include "/home/usuario/cya/Practica_9/Produccion.h"

class Grammar {
 public:
    Grammar();
    virtual ~Grammar();
    void SetAlphabet(std::set<std::string>);
    void SetStates(std::set<std::string>);
    void SetStart(std::string);
    void SetAcceptStates(std::set<std::string>);
    void SetProduccion(std::string, std::string, std::string);
    void PrintFile(std::string);

 private:
    std::set<std::string> alphabet_2;
    std::set<std::string> states_2;
    std::set<std::string> accept_states_2;
    std::string start_2;
    Transition transitions_2;
    Produccion produccion_;
    bool failed_;
    bool start_ok_;
    bool accept_states_ok_;
    bool transitions_ok;
    bool complete_;
    bool CheckStatus(void);
};

#endif  // PRACTICA_9_GRAMMAR_H_
