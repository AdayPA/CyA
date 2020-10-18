// University of La Laguna
// College of Engineering and Tech
// Degree of Computer Science
// Subject: Computabilidad y Algoritmia (CyA)
// Course/Year: 2º 
// @praxis: Number 4 CyA - "Productos Capicúas"
// @author: Aday Padilla Amaya
// @e-mail: alu0100843453@ull.edu.es
// @date: 14/11/2020
// @brief set_calculator.cc:  
//                                        
//                                                       
// References: 
// Lab exercise:
// https://github.com/fsande/CyA-P04-Sets/blob/master/Sets.md
// @compile:
// $ make
// $ make clean
// Version Control:
// 19/10/2020 - First version of the code 

#include "Vector.h"

#include <errno.h>   
#include <limits.h>  
#include <stdlib.h>  

#include <cstdlib>   
#include <iostream>   
#include <string>

const int kFileIn = 1;
const int kFileOut = 2;
const int kFirst = 1;
const int kSecond = 2;
const int kThird = 3;
const int kMinimun = 1;
const char kEmpty = '\0';
const std::string kExplain = "--help";

void Help(void) {
  /**
 ** Función declarada que retorna al comando "./palindrome_prod --help" un breve
 ** texto explicativo del funcionamiento del programa.
 */
  std::cout << "Modo de empleo: " << std::endl;
}

void BadImput (void) {
  std::cout << "Usage: ./set_calculator infile.txt outfile.txt" << std::endl;
  std::cout << "Try: './set_calculator --help' for more information." << std::endl;
}

int main(int argc, char** argv) {
  switch (argc) {
    case kFirst: {
      BadImput();
      break;
	  }	
    case kSecond:	{
      std::string help_string = argv[kFileIn];
      if (help_string == kExplain) {
        Help();
      } else {
        BadImput();
      }
       break;
    }
    case kThird: {
      std::string output_file(argv[kFileOut]);
      /*
      **
      **
      **
      **  TODO
      **
      **
      */
      Vector <int> w();
      w.write(std::cout);
      break;
    }
    default: {
      BadImput();
      break;
    }
  }
  return 0;
}