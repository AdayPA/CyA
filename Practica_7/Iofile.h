// University of La Laguna
// College of Engineering and Tech
// Degree of Computer Science
// Subject: Computabilidad y Algoritmia (CyA)
// Course/Year: 2º 
// @praxis: Number 6 CyA - "Sets"
// @author: Aday Padilla Amaya
// @e-mail: alu0100843453@ull.edu.es
// @date: 04/11/2020
// @brief IOFile.h :  
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

#ifndef IOFILE_H_
#define IOFILE_H_

#include <string>
#include <vector>

class IOFile {
  public:
    IOFile();
    IOFile(std::string, std::string);
    IOFile(std::string, std::string, std::string);
    ~IOFile();

  private:
    std::string inputFile_;
    inline void Set_inputFile(const std::string& filename) { inputFile_ = filename; };
    inline std::string& Get_inputFile (void) { return inputFile_; };
    std::string inputDFA_;
    inline void Set_inputDFA(const std::string& dfaname) { inputDFA_ = dfaname; };
    inline std::string& Get_inputDFA (void) { return inputDFA_; };
    std::string outputFile_;
    inline void Set_outputFile(const std::string& filename) { outputFile_ = filename; };
    inline const std::string& Get_outputFile (void)  { return outputFile_; };
    std::string Get_line (const std::string&, const int&);
    int Count_lines (const std::string);
    constexpr const int& CountChar (void);
    const bool IsDigit(const std::string&);
    void OutFileSyntaxName (void);
    std::vector<std::string> Split (std::string, std::string);
    // permissions
    // size for file
    // error type
};

#endif //IOFILE_H_