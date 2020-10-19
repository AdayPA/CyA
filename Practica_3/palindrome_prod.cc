// University of La Laguna
// College of Engineering and Tech
// Degree of Computer Science
// Subject: Computabilidad y Algoritmia (CyA)
// Course/Year: 2º 
// @praxis: Number 3 CyA - "Productos Capicúas"
// @author: Aday Padilla Amaya
// @e-mail: alu0100843453@ull.edu.es
// @date: 14/11/2020
// @brief palindrome_prod.cc:  Contains the basic's guidelines to exec the project.
//                             Given a integer (n > 0) finds the palindomics numbers 
//                             obtained from multipliying two numbers of n digits 
//                             (both of them), storing them in a output file.          
// @compile: $ make                                                    
// References: 
// https://es.wikipedia.org/wiki/Capic%C3%BAa#:~:text=En%20matem%C3%A1ticas%2C%20la%20palabra%20capic%C3%BAa,%2C%202882%2C%202442%2C%209102019.
// Lab exercise:
// https://github.com/fsande/CyA-P03-ProductosCapicua/blob/master/ProductosCapicua.md
// Version Control:
// 14/10/2020 - First version of the code 
// 15/10/2020 - Small changes and using threads
// 16/10/2020 - Changes in the Write method
// 17/10/2020 - Commenting the code
// 18/10/2020 - Makefile added correctly

#include "Palindromic.h"

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
std::cout << kTab << "palindrome_prod" << std::endl;
std::cout << std::endl;
std::cout << kBoldOpen << "SYNOPSIS" << kBoldClose << std::endl;
std::cout << kTab << "palindrome_prod [DIGIT] [FILE]" << std::endl;
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
  std::cout << "Usage: ./palindrome_prod Number_of_Digits Output_File" << std::endl;
  std::cout << "Try: './palindrome_prod --help' for more information." << std::endl;
}

int main(int argc, char** argv) {
  switch (argc) {     // Switch depending of the input commands
    case kFirst: {    // executed as: $ ./palindrome_prod.cc
      BadImput();
      break;
	  }	
    case kSecond:	{   // executed as: $ ./palindrome_prod.cc 1st_arg 
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
      char *aux_char = {};
      long digit = strtol(argv[1], &aux_char, kBASE);
      if (*aux_char != kNewLine || digit > INT_MAX || digit < kMinimun) {
        BadImput();
      } else {        // executed with the proper arguments, we call the class
        Palindromic capicua(digit, output_file);
      }
      break;
    }
    default: {        //executed as: everything else
      BadImput();
      break;
    }
  }
  return 0;
}
