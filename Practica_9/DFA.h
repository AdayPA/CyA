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
//                  
//                 
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

#ifndef DFA_H_
#define DFA_H_

#include <string>
#include <vector>

#include "/home/usuario/cya/Practica_9/Set.h"

class DFA {
  public:
    DFA();
    ~DFA();
    void SetAlphabet(std::string);
    void SetStates(std::string);
    void SetStart(std::string);
    void SetAcceptStates(std::string);
    void SetTransition(std::vector<std::string>);
    int Recon(std::string);

  private:
      struct Node {
      std::string init_;
      std::string alpha_;
      std::string end_;
      };
    Set dfa_set;
    std::vector<std::string> alphabet_;
    std::vector<std::string> states_;
    bool failed_;
    bool start_ok_;
    std::string start_;
    bool accept_states_ok_;
    std::vector<std::string> accept_states_;
    bool transitions_ok;
    std::vector<Node*> transitions_;
    bool complete_;
    bool CheckStatus(void);
    void Complete(void);
};

#endif  // DFA_H_

