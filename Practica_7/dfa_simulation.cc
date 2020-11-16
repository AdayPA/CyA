// University of La Laguna
// College of Engineering and Tech
// Degree of Computer Science
// Subject: Computabilidad y Algoritmia (CyA)
// Course/Year: 2º 
// @praxis: Number 5 CyA - "Sets"
// @author: Aday Padilla Amaya
// @e-mail: alu0100843453@ull.edu.es
// @date: 04/11/2020
// @brief pattern.cc :  This is the main of the praxis
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

#include "Iofile.h"

#include <errno.h>   
#include <limits.h>  
#include <stdlib.h>  

#include <cstdlib>   
#include <iostream>   
#include <string>

const int kFileIn = 2;
const int kFileOut = 3;
const int kDfa = 1;
const int kFirst = 1;
const int kSecond = 2;
const int kThird = 3;
const int kFourth = 4;
const int kMinimun = 1;                 // N > 0
const char kNewLine = '\0';
const std::string kBoldOpen = "\e[1m";
const std::string kBoldClose = "\e[0m";
const std::string kTab = "\t";
const std::string kExplain = "--help";
const std::string kExplain2 = "-h";

void Help(void) {
  /**
 ** Summary when the program is executed as: "./pattern --help" 
 ** Explain everithing about the program.
 */
std::cout << kBoldOpen << "NAME" << kBoldClose << std::endl;
std::cout << kTab << "pattern" << std::endl;
std::cout << std::endl;
std::cout << kBoldOpen << "SYNOPSIS" << kBoldClose << std::endl;
std::cout << kTab << "pattern [FILE_IN] [FILE_OUT]" << std::endl;
std::cout << std::endl;
std::cout << kBoldOpen << "DESCRIPTION" << kBoldClose << std::endl;
std::cout << kTab << "This program read the set, transform it and operate with it " <<
 "in a bit level and showing the result in a output file" << std::endl;
std::cout << std::endl;
std::cout << kTab << "Mandatory arguments:" << std::endl;
std::cout << std::endl;
std::cout << kTab << "[FILE_IN] " << std::endl;
std::cout << kTab << kTab << "input file with set for operate " << std::endl;
std::cout << std::endl;
std::cout << kTab << "[FILE_OUT] " << std::endl;
std::cout << kTab << kTab << "name of the output file; it will be created or " << 
  "overwritten " << std::endl;
std::cout << std::endl;
}

void BadImput (void) {
  // Message output when the program gets the wrong input arguments.
  std::cout << "Usage: ./dfa_simulation  input.dfa input.txt output.txt" << std::endl;
  std::cout << "Try: './dfa_simulation --help' for more information." << std::endl;
}

int main(int argc, char** argv) {
  switch (argc) {     // Switch depending of the input commands
    case kFirst: {    // executed as: $ ./pattern.cc
      BadImput();
      break;
	  }	
    case kSecond:	{   // executed as: $ ./pattern.cc 1st_arg 
      std::string temp = argv[kFirst];
      if ((temp == kExplain) || (temp == kExplain2)) {
        Help();
      } else {
        BadImput();
      }
      break;
    }
    case kThird: {    // executed as: $ ./pattern 1st_arg 2nd_arg
      BadImput();
      break;
    }
    case kFourth: {    // executed as: $ ./pattern 1st_arg 2nd_arg 3rd_arg
      std::string output_file(argv[kFileOut]);
      std::string input_txt(argv[kFileIn]);
      std::string input_dfa(argv[kDfa]);
      IOFile dfa(input_dfa,input_txt,output_file); 
      break;
    }
    default: {        //executed as: everything else
      BadImput();
      break;
    }
  }
  return 0;
}