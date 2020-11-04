// University of La Laguna
// College of Engineering and Tech
// Degree of Computer Science
// Subject: Computabilidad y Algoritmia (CyA)
// Course/Year: 2º 
// @praxis: Number 5 CyA - "Sets"
// @author: Aday Padilla Amaya
// @e-mail: alu0100843453@ull.edu.es
// @date: 04/11/2020
// @brief DFA.h :  
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


#ifndef DFA_H_
#define DFA_H_

#include <string>

class DFA {
  public:
    DFA();
    DFA(std::string,std::string);
    ~DFA();

  private:
    std::string pattern_;
    std::string GetPattern(void);
    void SetPattern(std::string&);
    std::string sequence_;
    std::string GetSequence(void);
    void SetSequence(std::string&);

  struct Node {
    int num_;
    char transition;
    bool accepted;
  };
    
};

#endif //DFA_H_