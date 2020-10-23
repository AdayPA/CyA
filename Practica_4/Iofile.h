// University of La Laguna
// College of Engineering and Tech
// Degree of Computer Science
// Subject: Computabilidad y Algoritmia (CyA)
// Course/Year: 2º 
// @praxis: Number 4 CyA - "Palabras de Fibonacci"
// @author: Aday Padilla Amaya
// @e-mail: alu0100843453@ull.edu.es
// @date: 21/11/2020
// @brief Iofile.h:  
//         
// @compile: $ make                                                    
// References: 
// https://en.wikipedia.org/wiki/Fibonacci_sequence
// Lab exercise:
// https://github.com/fsande/CyA-P04-FibonacciWords/blob/master/FibonacciWords.md
// Version Control:
// 21/10/2020 - First version of the code 

#ifndef IOFILE_H_
#define IOFILE_H_

#include <string>

class IOFile {
  public:
    IOFile();
    IOFile(std::string, std::string);
    ~IOFile();

  private:
    std::string inputFile_;
    inline void set_inputFile(const std::string& filename) { inputFile_ = filename; };
    inline std::string& get_inputFile (void) { return inputFile_; };
    std::string outputFile_;
    inline void set_outputFile(const std::string& filename) { outputFile_ = filename; };
    inline const std::string& get_outputFile (void)  { return outputFile_; };
    std::string get_line (const std::string, const int&);
    int count_lines (const std::string);
    constexpr const int& count_char (void);
    // permissions
    // size for file
    // add txt


};

#endif //IOFILE_H_