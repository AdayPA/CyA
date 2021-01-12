// University of La Laguna
// College of Engineering and Tech
// Degree of Computer Science
// Subject: Computabilidad y Algoritmia (CyA)
// Course/Year: 2º
// @praxis: Number 12 CyA 
// @author: Aday Padilla Amaya
// @e-mail: alu0100843453@ull.edu.es
// @date: 10/01/2021
// @brief Traveler.cc : This file implement the header
// @compile: $ make
// References:
// Lab exercise:
// (private link)
// Version Control:
// 10/01/2021- First version of the code
//
//
//
#include "Traveler.h"

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


void BadImput (void) {
  // Message output when the program gets the wrong input arguments.
  std::cout << "Usage: ./viajante  input.txt " << std::endl;
}

int main(int argc, char** argv) {
  switch (argc) {     // Switch depending of the input commands
    case kFirst: {    // executed as: $ ./name
      BadImput();
      break;
	  }	
    case kSecond:	{   // executed as: $ ./name 1st_arg 
      std::string input_gra(argv[kFirst]);
      Traveler greedy(input_gra); 
      break;
    }
    default: {        //executed as: everything else
      BadImput();
      break;
    }
  }
  return 0;
}