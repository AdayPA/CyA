// University of La Laguna
// College of Engineering and Tech
// Degree of Computer Science
// Subject: Computabilidad y Algoritmia (CyA)
// Course/Year: 2º 
// @praxis: Number 4 CyA - "Palabras de Fibonacci"
// @author: Aday Padilla Amaya
// @e-mail: alu0100843453@ull.edu.es
// @date: 21/11/2020
// @brief ./fibonacci_words.cc:  
//         
// @compile: $ make                                                    
// References: 
// https://en.wikipedia.org/wiki/Fibonacci_sequence
// Lab exercise:
// https://github.com/fsande/CyA-P04-FibonacciWords/blob/master/FibonacciWords.md
// Version Control:
// 21/10/2020 - First version of the code 


#include "Iofile.h"

#include <errno.h>   
#include <limits.h>  
#include <stdlib.h>  

#include <cstdlib>   
#include <iostream>   
#include <string>

extern const int kBASE = 10;            // Numeric base
const int kFileIn = 1;
const int kFileOut = 2;
const int kFirst = 1;
const int kSecond = 2;
const int kThird = 3;
const int kMinimun = 1;                 // N > 0
const char kNewLine = '\0';
const std::string kBoldOpen = "\e[1m";
const std::string kBoldClose = "\e[0m";
const std::string kTab = "\t";
const std::string kExplain = "--help";

void Help(void) {
  /**
 ** Summary when the program is executed as: "./palindrome_prod --help" 
 ** Explain everithing about the program.
 */
std::cout << kBoldOpen << "NAME" << kBoldClose << std::endl;
std::cout << kTab << "fibonacci_words" << std::endl;
std::cout << std::endl;
std::cout << kBoldOpen << "SYNOPSIS" << kBoldClose << std::endl;
std::cout << kTab << "palindrome_prod [FILE_IN] [FILE_OUT]" << std::endl;
std::cout << std::endl;
std::cout << kBoldOpen << "DESCRIPTION" << kBoldClose << std::endl;
std::cout << kTab << "This program finds the palindomics numbers obtained from " << 
  "multipliying two numbers of n digits (both of them), storing them in " <<
  "a output file" << std::endl;
std::cout << std::endl;
std::cout << kTab << "Mandatory arguments:" << std::endl;
std::cout << std::endl;
std::cout << kTab << "[DIGIT] " << std::endl;
std::cout << kTab << kTab << "the number must be N > 0 " << std::endl;
std::cout << std::endl;
std::cout << kTab << "[FILE] " << std::endl;
std::cout << kTab << kTab << "name of the output file; it will be created or " << 
  "overwritten " << std::endl;
std::cout << std::endl;
}

void BadImput (void) {
  // Message output when the program gets the wrong input arguments.
  std::cout << "Usage: ./fibonacci_words Input_File Output_File" << std::endl;
  std::cout << "Try: './fibonacci_words --help' for more information." << std::endl;
}

int main(int argc, char** argv) {
  switch (argc) {     // Switch depending of the input commands
    case kFirst: {    // executed as: $ ./fibonacci_words.cc
      BadImput();
      break;
	  }	
    case kSecond:	{   // executed as: $ ./fibonacci_words.cc 1st_arg 
      std::string input_file = argv[kFileIn];
      if (input_file == kExplain) {
        Help();
      } else {
        BadImput();
      }
       break;
    }
    case kThird: {    // executed as: $ ./palindrome_prod.cc 1st_arg 2nd_arg
      std::string output_file(argv[kFileOut]);
      std::string input_file(argv[kFileIn]);
            
      break;
    }
    default: {        //executed as: everything else
      BadImput();
      break;
    }
  }
  return 0;
}
