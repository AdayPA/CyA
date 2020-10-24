// University of La Laguna
// College of Engineering and Tech
// Degree of Computer Science
// Subject: Computabilidad y Algoritmia (CyA)
// Course/Year: 2º 
// @praxis: Number 4 CyA - "Palabras de Fibonacci"
// @author: Aday Padilla Amaya
// @e-mail: alu0100843453@ull.edu.es
// @date: 21/11/2020
// @brief Fibonacci.h:  
//         
// @compile: $ make                                                    
// References: 
// https://en.wikipedia.org/wiki/Fibonacci_sequence
// Lab exercise:
// https://github.com/fsande/CyA-P04-FibonacciWords/blob/master/FibonacciWords.md
// Version Control:
// 21/10/2020 - First version of the code 
// 22/10/2020 - The core is done
// 23/10/2020 - Added IOFile
// 24/10/2020 - Added functionalities and output is good

#ifndef FIBONACCI_H_
#define FIBONACCI_H_

#include <string>
#include <vector>
#include <variant>


class Fibonacci {
  public:
    Fibonacci();
    Fibonacci(std::string first, std::string second, int iterations);
    bool Is_Fibonacci(const std::string&, const int&) const;
    ~Fibonacci();

  private:
    std::string firstElement_, secondElement_;
    inline void Set_firstElement(const std::string& element) { firstElement_ = element; };
    inline void Set_secondElement(const std::string& element) { secondElement_ = element; };
    inline std::string& Get_firstElement (void) { return firstElement_; };
    inline std::string& Get_secondElement (void) { return secondElement_; };
    int fibonacciIterations_;
    inline void Set_fibonacciIterations(int& iterations) { fibonacciIterations_ = iterations; };
    inline const int& Get_fibonacciIterations(void) { return fibonacciIterations_; };
   // std::vector<std::string> fibonacciSerie;
    std::vector<std::variant<type1, type2, type3>> vectorName;
    const bool IsDigit(const std::string&);
    void DoFibonacci(void);
};

#endif //FIBONACCI_H_