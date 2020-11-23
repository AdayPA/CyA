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
// @brief Transition.cc :
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

#ifndef PRACTICA_9_IOFILE_H_
#define PRACTICA_9_IOFILE_H_

#include <string>
#include <vector>

class IOFile {
 public:
    IOFile();
    IOFile(std::string& inputDFA, std::string& outputGRA);
    ~IOFile();

 private:
    std::string inputDFA_;
    std::string outputFile_;
    inline void Set_inputDFA(const std::string& dfaname) {inputDFA_ = dfaname;}
    inline void Set_outputFile(const std::string& filename) {outputFile_ = filename;}
    inline std::string& Get_inputDFA(void) { return inputDFA_; }
    inline const std::string& Get_outputFile (void)  {return outputFile_;}
    void ReadDFA(void);
    std::string Get_line(const std::string&, const int&);
    int Count_lines(const std::string);
    constexpr const int& CountChar(void);
    const bool IsDigit(const std::string&);
    void OutFileSyntaxName(void);
    void OutputOpenError(void);
    std::vector<std::string> Split(std::string, std::string);
    std::string ClearComments(std::string new_file_name);
    void RemoveFile(const char * file_to_remove);
    // permissions
    // size for file
    // error type
};

#endif  // PRACTICA_9_IOFILE_H_
