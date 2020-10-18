// University of La Laguna
// College of Engineering and Tech
// Degree of Computer Science
// Subject: Computabilidad y Algoritmia (CyA)
// Course/Year: 2º 
// @praxis: Number 3 CyA - "Productos Capicúas"
// @author: Aday Padilla Amaya
// @e-mail: alu0100843453@ull.edu.es
// @date: 14/11/2020
// @brief Palindromic.h:  Header file of the class Palindromic.
//                        This class aim to obtain the product and 
//                        store the result in a output file.          
//                                                       
// References: 
// https://es.wikipedia.org/wiki/Capic%C3%BAa#:~:text=En%20matem%C3%A1ticas%2C%20la%20palabra%20capic%C3%BAa,%2C%202882%2C%202442%2C%209102019.
// Lab exercise:
// https://github.com/fsande/CyA-P03-ProductosCapicua/blob/master/ProductosCapicua.md
// @compile:
// $ make
// $ make clean
// Version Control:
// 14/10/2020 - First version of the code 
// 15/10/2020 - Small changes and using threads
// 16/10/2020 - Changes in the Write method
// 17/10/2020 - Commenting the code
#ifndef PALINDROMIC_H_
#define PALINDROMIC_H_

#include <string>
#include <tuple>
#include <vector>

class Palindromic {
  public:
    Palindromic();
    Palindromic(int digits, std::string output_file);
    ~Palindromic();

  private:
    int numDigits_;
    std::string outputFile_;
    inline void set_outputFile(const std::string& filename) { outputFile_ = filename; };
    inline const std::string& get_outputFile (void) { return outputFile_; };
    inline void set_numDigits(int& numDigits) { numDigits_ = numDigits; };
    inline const int& get_numDigits(void) { return numDigits_; };
    std::vector<std::tuple<int,int,int>> my_palindroms;
    void FindPalin(void);
    const int MaxNumber(void);
    const int MinNumber(void);
    void Write(void);
};

#endif 