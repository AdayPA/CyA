// University of La Laguna
// College of Engineering and Tech
// Degree of Computer Science
// Subject: Computabilidad y Algoritmia (CyA)
// Course/Year: 2º 
// @praxis: Number 9 CyA - "Sets"
// @author: Aday Padilla Amaya
// @e-mail: alu0100843453@ull.edu.es
// @date: 19/11/2020
// @brief  :  
//                 
// @compile: $ make                                                    
// References: 
// 
// Lab exercise:
// 
// Version Control:
// 19/11/2020 - Preparing the main 
// 

#include "Iofile.h"

#include <errno.h>   
#include <limits.h>  
#include <stdlib.h>  

#include <cstdlib>   
#include <iostream>   
#include <string>

const int kFileIn = 2;
const int kFileOut = 3;
const int kFirst = 1;
const int kSecond = 2;
const int kThird = 3;
const int kFourth = 4;
const int kFifth = 5;
const int kMinimun = 1;                 // N > 0
const char kNewLine = '\0';
const std::string kBoldOpen = "\e[1m";
const std::string kBoldClose = "\e[0m";
const std::string kTab = "\t";
const std::string kExplain = "--help";
const std::string kExplain2 = "-h";

void Help(void) {
  /**
 ** Summary when the program is executed as: "./dfa2g --help" 
 ** Explain everithing about the program.
 */
std::cout << kBoldOpen << "NAME" << kBoldClose << std::endl;
std::cout << kTab << "dfa2g" << std::endl;
std::cout << std::endl;
std::cout << kBoldOpen << "SYNOPSIS" << kBoldClose << std::endl;
std::cout << kTab << "dfa2g [DFA_IN] [GRA_OUT]" << std::endl;
std::cout << std::endl;
std::cout << kBoldOpen << "DESCRIPTION" << kBoldClose << std::endl;
std::cout << kTab << "This program read the dfa and transform it to a gramar. " << std::endl;
std::cout << std::endl;
std::cout << kTab << "Mandatory arguments:" << std::endl;
std::cout << std::endl;
std::cout << kTab << "[DFA_IN] " << std::endl;
std::cout << kTab << kTab << "input file with the custom dfa " << std::endl;
std::cout << std::endl;
std::cout << kTab << "[GRA_OUT] " << std::endl;
std::cout << kTab << kTab << "name of the output file; it will be created or " << 
  "overwritten " << std::endl;
std::cout << std::endl;
}

void BadImput (void) {
  // Message output when the program gets the wrong input arguments.
  std::cout << "Usage: ./dfa2g  input.dfa output.gra" << std::endl;
  std::cout << "Try: './dfa2g --help' for more information." << std::endl;
}

int main(int argc, char** argv) {
  switch (argc) {     // Switch depending of the input commands
    case kFirst: {    // executed as: $ ./name
      BadImput();
      break;
	  }	
    case kSecond:	{   // executed as: $ ./name 1st_arg 
      std::string temp = argv[kFirst];
      if ((temp == kExplain) || (temp == kExplain2)) {
        Help();
      } else {
        BadImput();
      }
      break;
    }
    case kThird: {    // executed as: $ ./name 1st_arg 2nd_arg
      std::string output_gra(argv[kSecond]);
      std::string input_dfa(argv[kFirst]);
      IOFile dfa2g(input_dfa, output_gra); 
      break;
    }
    case kFourth: {    // executed as: $ ./name 1st_arg 2nd_arg 3rd_arg
      BadImput();
      break;
    }
    case kFifth: {    // executed as: $ ./name 1st_arg 2nd_arg 3rd_arg 4th_arg
      break;
    }

    default: {        //executed as: everything else
      BadImput();
      break;
    }
  }
  return 0;
}