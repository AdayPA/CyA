// University of La Laguna
// College of Engineering and Tech
// Degree of Computer Science
// Subject: Computabilidad y Algoritmia (CyA)
// Course/Year: 2º 
// @praxis: Number 5 CyA - ""
// @author: Aday Padilla Amaya
// @e-mail: alu0100843453@ull.edu.es
// @date: 26/11/2020
// @brief ./.cc:  
// 
// @compile: $ make                                                    
// References: 
// 
// Lab exercise:
// 
// Version Control:
// 26/10/2020 - First version of the code 
// 

#ifndef SET_CC_
#define SET_CC_

#include "Set.h"

#include <iostream>
#include <sstream>
#include <algorithm>
#include <regex>

#include <stdio.h>
#include <math.h> 

Set::Set() {
    /*printf("bitwise operations\n");
    unsigned long int num = 1;
    num = num << 3;
    int i;
    for(i= (sizeof(unsigned long int)*8)-1;i>= 0; i--){
        char c = (num &(1LL<<i))? '1' : '0';
        putchar(c);
    }
    printf("\n");*/
}

Set::Set(int& size) {}

Set::~Set() {}

void Set::Work(std::string in) {
  Operate(FindOperators(in),in); 
  Range(ExtractIntegerWords(in));
}

std::vector<unsigned long int> Set::Range(std::vector<int> in){
  unsigned long int result = 0;
  int vect_pos = floor(in[2] / 64);
  //test
  
}

void Set::Operate(std::string operators, std::string operand) {
  if (operators == "!+!") {
    std::vector<std::string> v = Split (operand, "+" );
    std::vector<int> test = ExtractIntegerWords(v[0]);
    std::vector<int> test1 = ExtractIntegerWords(v[1]);
    set_ = Union(Complement(Convert(test)), Complement(Convert(test1)));
  } else if (operators == "+!") {
    std::vector<std::string> v = Split (operand, "+" );
    std::vector<int> test = ExtractIntegerWords(v[0]);
    std::vector<int> test1 = ExtractIntegerWords(v[1]);
    set_ = Union(Convert(test), Complement(Convert(test1)));
  } else if (operators == "!+") {
    std::vector<std::string> v = Split (operand, "+" );
    std::vector<int> test = ExtractIntegerWords(v[0]);
    std::vector<int> test1 = ExtractIntegerWords(v[1]);
    set_ = Union(Complement(Convert(test)), Convert(test1));
  } else if (operators == "+") {
    std::vector<std::string> v = Split (operand, "+" );
    std::vector<int> test = ExtractIntegerWords(v[0]);
    std::vector<int> test1 = ExtractIntegerWords(v[1]);
    set_ = Union(Convert(test), Convert(test1));
  } else if (operators == "-") {
    std::vector<std::string> v = Split (operand, "-" );
    std::vector<int> test = ExtractIntegerWords(v[0]);
    std::vector<int> test1 = ExtractIntegerWords(v[1]);
    set_ = RelativeComplement(Convert(test), Convert(test1));
  } else if (operators == "!-") {
    std::vector<std::string> v = Split (operand, "-" );
    std::vector<int> test = ExtractIntegerWords(v[0]);
    std::vector<int> test1 = ExtractIntegerWords(v[1]);
    set_ = RelativeComplement(Complement(Convert(test)), Convert(test1));
  } else if (operators == "!-!") {
    std::vector<std::string> v = Split (operand, "-" );
    std::vector<int> test = ExtractIntegerWords(v[0]);
    std::vector<int> test1 = ExtractIntegerWords(v[1]);
    set_ = RelativeComplement(Complement(Convert(test)), Complement(Convert(test1)));
  } else if (operators == "-!") {
    std::vector<std::string> v = Split (operand, "-" );
    std::vector<int> test = ExtractIntegerWords(v[0]);
    std::vector<int> test1 = ExtractIntegerWords(v[1]);
    set_ = RelativeComplement(Convert(test), Complement(Convert(test1)));
  } else if (operators == "*") {
    std::vector<std::string> v = Split (operand, "*" );
    std::vector<int> test = ExtractIntegerWords(v[0]);
    std::vector<int> test1 = ExtractIntegerWords(v[1]);
    set_ = Intersection(Convert(test), Convert(test1));
  } else if (operators == "!*") {
    std::vector<std::string> v = Split (operand, "*" );
    std::vector<int> test = ExtractIntegerWords(v[0]);
    std::vector<int> test1 = ExtractIntegerWords(v[1]);
    set_ = Intersection(Complement(Convert(test)), Convert(test1));
  } else if (operators == "!*!") {
    std::vector<std::string> v = Split (operand, "*" );
    std::vector<int> test = ExtractIntegerWords(v[0]);
    std::vector<int> test1 = ExtractIntegerWords(v[1]);
    set_ = Intersection(Complement(Convert(test)), Complement(Convert(test1)));
  } else if (operators == "*!") {
    std::vector<std::string> v = Split (operand, "*" );
    std::vector<int> test = ExtractIntegerWords(v[0]);
    std::vector<int> test1 = ExtractIntegerWords(v[1]);
    set_ = Intersection(Convert(test), Complement(Convert(test1)));
  } else if (operators == "!") {
    std::vector<std::string> v = Split (operand, "!" );
    std::vector<int> test = ExtractIntegerWords(v[0]);
    set_ = Complement(Convert(test));
  } else if (operand.at(0) == '{' && operand.back() == '}') {
    std::vector<int> test = ExtractIntegerWords(operand);
    set_ = Convert(test);
  } else {
    std::cout << "error de lectura" << std::endl;
  }
}

bool Set::CheckSyntax(std::string in) {
 /* std::regex a("(({.*}|!{.*}) (\+|\-|\*|\=) ({.*}|!{.*}))");
  if ( std::regex_match (in, a) ) 
        std::cout << "String 'a' matches regular expression 'b' \n"; 
        */
  return true;
}

void Set::write(std::string out) {}

unsigned long int Set::Convert(std::vector<int> in) {
  unsigned long int result = 0;
  for(unsigned int i = 0; i < in.size(); ++i){
    unsigned long int num = 1;
    for ( int j = 0; j < in[i]; ++j){
      num = num << 1;
    }
    result = result | num;
  }
  return result;
}

void Set::PrintBits (unsigned long int num) {
  int i;
    for (i = (sizeof(unsigned long int) * 8) - 1; i >= 0; i--) {
        char c = (num & (1LL << i))? '1' : '0';
        putchar(c);
    }
    printf("\n");
}

unsigned long int Set::Union (unsigned long int sum1, unsigned long int sum2) {
  return sum1 | sum2;
}

unsigned long int Set::Complement (unsigned long int num) {
  return  ~(num);
}

unsigned long int Set::RelativeComplement (unsigned long int sum1, unsigned long int sum2) {
  unsigned long int temp = Complement(sum1);
  return Intersection(sum2,temp);
}

unsigned long int Set::Intersection (unsigned long int sum1, unsigned long int sum2) {
  return sum1 & sum2;
}

std::string Set::FindOperators (std::string input) {
  std::string operation;
  for (unsigned int i = 0; i < input.size(); i++) {
    if (input[i] == '!') operation += "!";
    else if (input[i] == '-') operation += "-";
    else if (input[i] == '+') operation += "+";
    else if (input[i] == '*') operation += "*";
  }
  return operation;
}

std::vector<std::string> Set::Split (std::string str, std::string delim) {
  std::vector<std::string> tokens;
  size_t prev = 0, pos = 0;
  do {
    pos = str.find(delim, prev);
    if (pos == std::string::npos) pos = str.length();
    std::string token = str.substr(prev, pos-prev);
    if (!token.empty()) tokens.push_back(token);
    prev = pos + delim.length();
  }
  while (pos < str.length() && prev < str.length());
  return tokens;
}

std::vector<int> Set::ExtractIntegerWords(std::string str) {
  str.erase(std::remove(str.begin(), str.end(), '{'), str.end());
  str.erase(std::remove(str.begin(), str.end(), '!'), str.end());
  str.erase(std::remove(str.begin(), str.end(), '}'), str.end());
  str.erase(std::remove(str.begin(), str.end(), ','), str.end());
  std::stringstream ss;     
  std::vector<int> result;
  ss << str; 
  std::string temp; 
  int found; 
  while (!ss.eof()) { 
    ss >> temp; 
    if (std::stringstream(temp) >> found) 
      result.push_back(found);
    temp = ""; 
  } 
  return result;
}

void Set::PrintSet (void){
  PrintBits(set_);
}

void Set::operator=(std::string in){
  std::vector<int> test = ExtractIntegerWords(in);
  set_ = Convert(test);
  PrintBits(set_);
}
/*
void Set::operator>>(Set a, std::string& in){
  Work(in);
}
*/
void Set::operator + ( int sum){
  std::vector<int> temp;
  temp.push_back(sum);
  unsigned long int num = Convert (temp);
  this->set_ = Union(this->set_,num);
}

#endif