// University of La Laguna
// College of Engineering and Tech
// Degree of Computer Science
// Subject: Computabilidad y Algoritmia (CyA)
// Course/Year: 2º 
// @praxis: Number 5 CyA - "Sets"
// @author: Aday Padilla Amaya
// @e-mail: alu0100843453@ull.edu.es
// @date: 26/11/2020
// @brief set_calculator.cc :  This is the main of the praxis
//                 
// @compile: $ make                                                    
// References: 
// https://en.wikipedia.org/wiki/Set_(mathematics)
// https://en.wikipedia.org/wiki/Union_(set_theory)
// Lab exercise:
// https://github.com/fsande/CyA-P05-Sets/blob/master/Sets.md
// Version Control:
// 26/10/2020 - First version of the code 
// 28/10/2020 - Adding the lecture filtering
// 29/10/2020 - Converting to bits
// 31/10/2020 - Adding operations
// 2/10/2020 -  Writting the output

#include "Iofile.h"

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
const int kMinimun = 1;                 // N > 0
const char kNewLine = '\0';
const std::string kBoldOpen = "\e[1m";
const std::string kBoldClose = "\e[0m";
const std::string kTab = "\t";
const std::string kExplain = "--help";
const std::string kExplain2 = "-h";

void Help(void) {
  /**
 ** Summary when the program is executed as: "./set_calculator --help" 
 ** Explain everithing about the program.
 */
std::cout << kBoldOpen << "NAME" << kBoldClose << std::endl;
std::cout << kTab << "set_calculator" << std::endl;
std::cout << std::endl;
std::cout << kBoldOpen << "SYNOPSIS" << kBoldClose << std::endl;
std::cout << kTab << "set_calculator [FILE_IN] [FILE_OUT]" << std::endl;
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
  std::cout << "Usage: ./set_calculator Input_File Output_File" << std::endl;
  std::cout << "Try: './set_calculator --help' for more information." << std::endl;
}

int main(int argc, char** argv) {
  switch (argc) {     // Switch depending of the input commands
    case kFirst: {    // executed as: $ ./set_calculator.cc
      BadImput();
      break;
	  }	
    case kSecond:	{   // executed as: $ ./set_calculator.cc 1st_arg 
      std::string input_file = argv[kFileIn];
      if ((input_file == kExplain) || (input_file == kExplain2) ) {
        Help();
      } else {
        BadImput();
      }
       break;
    }
    case kThird: {    // executed as: $ ./set_calculator 1st_arg 2nd_arg
      std::string output_file(argv[kFileOut]);
      std::string input_file(argv[kFileIn]);
      IOFile calculator(input_file,output_file); 
      break;
    }
    default: {        //executed as: everything else
      BadImput();
      break;
    }
  }
  return 0;
}