// University of La Laguna
// College of Engineering and Tech
// Degree of Computer Science
// Subject: Computabilidad y Algoritmia (CyA)
// Course/Year: 2º 
// @praxis: Number 5 CyA - ""
// @author: Aday Padilla Amaya
// @e-mail: alu0100843453@ull.edu.es
// @date: 26/11/2020
// @brief Set.h :  Implementation of Set.h
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

#ifndef SET_CC_
#define SET_CC_

#include "Set.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <regex>

#include <stdio.h>
#include <math.h> 

Set::Set() {
  size_of_set_ = 64;
  set_ = 0;
}

Set::Set(int size) {
  size_of_set_ = size;
}

Set::~Set() {

}

void Set::Work(std::string in) {
  /// @brief calling private functions for make the class work.
  expression_ = in;
  Operate(FindOperators(in),in);
  TransformToInt();
}

std::string Set::Write() {
  /// @brief writting the result to the file
  for (auto& i : intergers_) {
    if ( i >= size_of_set_) {
      intergers_.erase(std::remove(intergers_.begin(), intergers_.end(), i), intergers_.end());
    }
  }
    std::string result;
    result += "{";
    for (auto& i : intergers_)
      if (i != intergers_.back()) {
        result = result + std::to_string(i);
        result = result + ", ";
      } else {
        result = result + std::to_string(i);
      }
  result = result + "}";
  return result;
}

void Set::Clear() {
  /// @brief clear the set
  set_ = 0;
}

bool Set::IsEmpty() {
  /// @brief return true if set is empty
  if (set_ == 0) {
    return true;
  } else {
    return false;
  }
}

bool Set::Belong(int number) {
  /// @brief return true if the element belong to the set
  unsigned long int temp = set_;
  for ( int i = 0; i < number; ++i) {
    temp >>= 1;
  }
  if(temp & 1) {
    return true;
  } else {
    return false;
  }
}

void Set::TransformToInt (void) {
  /// @brief take the bits and transform it to a legible int
  intergers_.resize(0);
  int shift = 0;
  for (unsigned int i = 0; i < set_storage.size(); ++i) {
  unsigned long int temp = set_storage[i];
  unsigned int count = 0; 
    while (set_storage[i]) { 
        if (temp & 1) {
          intergers_.push_back(count + shift);
        }
        temp = set_storage[i] >> 1; 
        set_storage[i] >>= 1;
        count++;
    } 
    shift += 64;
  }
}

std::vector<std::vector<int>> Set::Range(std::vector<int> in) {
  /// @brief split the int to a vector with the propper value range
  max_elements_ = 0;
  std::vector<std::vector< int>> data;
  for (unsigned int i = 0; i < in.size(); ++i) {
    if (in[i] > max_elements_ ) max_elements_ = in[i];
  }
  int vect_pos = floor(max_elements_ / 64);
  data.resize(vect_pos + 1);
  
  for (unsigned int i = 0; i < in.size(); ++i) {
    int temp =  floor(in[i] / 64);
    data[temp].push_back(in[i] % 64);
  }
  return data;
}

void Set::Operate(std::string operators, std::string operand) {
  /// @brief reads the operator and do the related math
  if (operators == "!+!") {
    std::vector<std::string> v = Split (operand, "+" );
    std::vector<int> test = ExtractIntegerWords(v[0]);
    std::vector<int> test1 = ExtractIntegerWords(v[1]);
    set_storage = Union2(Complement2(Convert2(Range(test))), Complement2(Convert2(Range(test1))));
  } else if (operators == "+!") {
    std::vector<std::string> v = Split (operand, "+" );
    std::vector<int> test = ExtractIntegerWords(v[0]);
    std::vector<int> test1 = ExtractIntegerWords(v[1]);
    set_storage = Union2(Convert2(Range(test)), Complement2(Convert2(Range(test1))));
  } else if (operators == "!+") {
    std::vector<std::string> v = Split (operand, "+" );
    std::vector<int> test = ExtractIntegerWords(v[0]);
    std::vector<int> test1 = ExtractIntegerWords(v[1]);
    set_storage = Union2(Complement2(Convert2(Range(test))), Convert2(Range(test1)));
  } else if (operators == "+") {
    std::vector<std::string> v = Split (operand, "+" );
    std::vector<int> test = ExtractIntegerWords(v[0]);
    std::vector<int> test1 = ExtractIntegerWords(v[1]);
    set_storage = Union2(Convert2(Range(test)),Convert2(Range(test1)));
  } else if (operators == "-") {
    std::vector<std::string> v = Split (operand, "-" );
    std::vector<int> test = ExtractIntegerWords(v[0]);
    std::vector<int> test1 = ExtractIntegerWords(v[1]);
    set_storage = RelativeComplement2(Convert2(Range(test)),Convert2(Range(test1)));
  } else if (operators == "!-") {
    std::vector<std::string> v = Split (operand, "-" );
    std::vector<int> test = ExtractIntegerWords(v[0]);
    std::vector<int> test1 = ExtractIntegerWords(v[1]);
    set_storage = RelativeComplement2(Complement2(Convert2(Range(test))), Convert2(Range(test1)));
  } else if (operators == "!-!") {
    std::vector<std::string> v = Split (operand, "-" );
    std::vector<int> test = ExtractIntegerWords(v[0]);
    std::vector<int> test1 = ExtractIntegerWords(v[1]);
    set_storage = RelativeComplement2(Complement2(Convert2(Range(test))), Complement2(Convert2(Range(test1))));
  } else if (operators == "-!") {
    std::vector<std::string> v = Split (operand, "-" );
    std::vector<int> test = ExtractIntegerWords(v[0]);
    std::vector<int> test1 = ExtractIntegerWords(v[1]);
    set_storage = RelativeComplement2(Convert2(Range(test)), Complement2(Convert2(Range(test1))));
  } else if (operators == "*") {
    std::vector<std::string> v = Split (operand, "*" );
    std::vector<int> test = ExtractIntegerWords(v[0]);
    std::vector<int> test1 = ExtractIntegerWords(v[1]);
    set_storage = Intersection2(Convert2(Range(test)),Convert2(Range(test1)));
  } else if (operators == "!*") {
    std::vector<std::string> v = Split (operand, "*" );
    std::vector<int> test = ExtractIntegerWords(v[0]);
    std::vector<int> test1 = ExtractIntegerWords(v[1]);
    set_storage = Intersection2(Complement2(Convert2(Range(test))),Convert2(Range(test1)));
  } else if (operators == "!*!") {
    std::vector<std::string> v = Split (operand, "*" );
    std::vector<int> test = ExtractIntegerWords(v[0]);
    std::vector<int> test1 = ExtractIntegerWords(v[1]);
    set_storage = Intersection2(Complement2(Convert2(Range(test))), Complement2(Convert2(Range(test1))));
  } else if (operators == "*!") {
    std::vector<std::string> v = Split (operand, "*" );
    std::vector<int> test = ExtractIntegerWords(v[0]);
    std::vector<int> test1 = ExtractIntegerWords(v[1]);
    set_storage = Intersection2(Convert2(Range(test)), Complement2(Convert2(Range(test1))));
  } else if (operators == "!") {
    std::vector<std::string> v = Split (operand, "!" );
    std::vector<int> test = ExtractIntegerWords(v[0]);
    set_storage = Complement2(Convert2(Range(test)));
  } else if (operand.at(0) == '{' && operand.back() == '}') {
    std::vector<int> test = ExtractIntegerWords(operand);
    set_storage = Convert2(Range(test));
  } else {
    //std::cout << "error de lectura" << std::endl;
  } 
}

bool Set::CheckSyntax(std::string in) {
  /// @brief check is input have a correct syntax
 /* std::regex a("(({.*}|!{.*}) (\+|\-|\*|\=) ({.*}|!{.*}))");
  if ( std::regex_match (in, a) ) 
        std::cout << "String 'a' matches regular expression 'b' \n"; 
        */
  return true;
}

void Set::SetOutput(std::ofstream& out) {
 // output_ = out;
}

unsigned long int Set::Convert(std::vector<int> in) {
  /// @brief transform the vector with int to the equal bit set
  unsigned long int result = 0;
  for(unsigned int i = 0; i < in.size(); ++i) {
    unsigned long int num = 1;
      for ( int j = 0; j < in[i]; ++j) {
        num = num << 1;
      } 
    result = result | num;
  }
  return result;
}

std::vector<unsigned long int> Set::Convert2 (std::vector<std::vector<int>> data) {
  /// @brief same function of Convert but for 2d vector
  std::vector<unsigned long int> result;
  for (unsigned int i = 0; i < data.size(); ++i ) {
    result.push_back(Convert(data[i]));
  }
  return result;
}


void Set::PrintBits (unsigned long int num) {
  /// @brief prints the bits
  int i;
    for (i = (sizeof(unsigned long int) * 8) - 1; i >= 0; i--) {
        char c = (num & (1LL << i))? '1' : '0';
        putchar(c);
    }
    printf("\n");
}

void Set::PrintVectorSet(std::vector<unsigned long int> data) {
  /// @brief prints all the bits of the vector
  for (unsigned int i = 0; i < data.size(); ++i) {
    PrintBits(data[i]);
  }
}


const unsigned long int Set::Union (unsigned long int sum1, unsigned long int sum2) {
  return sum1 | sum2;
}

std::vector<unsigned long int> Set::Union2 (std::vector<unsigned long int> sum1, std::vector<unsigned long int> sum2){
  /// @brief works like Union but for all the bits of the vector
  std::vector<unsigned long int> result;
  unsigned long int trash = 0;
  if (sum1.size() < sum2.size()) {
    for (unsigned int i = sum1.size() ; i < sum2.size(); ++i) {
      sum1.push_back(trash);
    }
  } else if (sum1.size() > sum2.size()) {
   for (unsigned int i = sum2.size() ; i < sum1.size(); ++i) {
      sum2.push_back(trash);
    }
  }
  const size_t minSize = std::max(sum1.size(), sum2.size());
  for (size_t i = 0; i < minSize; ++i)
    result.push_back(Union(sum1[i],sum2[i]));

  return result;
}

unsigned long int Set::Complement (unsigned long int num) {
  /// @brief return the complement of the number
  return  ~(num);
}

std::vector<unsigned long int> Set::Complement2 (std::vector<unsigned long int> num) {
  /// @brief works like Complement but for all the bits of the vector
  std::vector<unsigned long int> result;
  for (unsigned int i = 0; i < num.size(); ++i) {
    result.push_back(Complement(num[i]));
  }
  return result;
}

unsigned long int Set::RelativeComplement (unsigned long int sum1, unsigned long int sum2) {
  /// @brief thos func does the relative complement of the set
  unsigned long int temp = Complement(sum1);
  return Intersection(sum2,temp);
}

std::vector<unsigned long int> Set::RelativeComplement2 (std::vector<unsigned long int> sum1, std::vector<unsigned long int> sum2){
  /// @brief works like RelativeComplement but for all the bits of the vector
  std::vector<unsigned long int> result;
  unsigned long int trash = 0;
  if (sum1.size() < sum2.size()) {
    for (unsigned int i = sum1.size() ; i < sum2.size(); ++i) {
      sum1.push_back(trash);
    }
  } else if (sum1.size() > sum2.size()) {
   for (unsigned int i = sum2.size() ; i < sum1.size(); ++i) {
      sum2.push_back(trash);
    }
  }
  const size_t minSize = std::max(sum1.size(), sum2.size());
  for (size_t i = 0; i < minSize; ++i)
    result.push_back(RelativeComplement(sum1[i],sum2[i]));

  return result;
}

unsigned long int Set::Intersection (unsigned long int sum1, unsigned long int sum2) {
  /// @brief this return the intersection of the set
  return sum1 & sum2;
}

std::vector<unsigned long int> Set::Intersection2 (std::vector<unsigned long int> sum1, std::vector<unsigned long int> sum2){
  /// @brief works like Intersection but for all the bits of the vector
  std::vector<unsigned long int> result;
  unsigned long int trash = 0;
  if (sum1.size() < sum2.size()) {
    for (unsigned int i = sum1.size() ; i < sum2.size(); ++i) {
      sum1.push_back(trash);
    }
  } else if (sum1.size() > sum2.size()) {
   for (unsigned int i = sum2.size() ; i < sum1.size(); ++i) {
      sum2.push_back(trash);
    }
  }
  const size_t minSize = std::max(sum1.size(), sum2.size());
  for (size_t i = 0; i < minSize; ++i)
    result.push_back(Intersection(sum1[i],sum2[i]));

  return result;
}

std::string Set::FindOperators (std::string input) {
  /// @brief this func find the operators from a string
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
  /// @brief this func split in 2 the string and store them in vector, depending of the char
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
  /// @brief this func return a vector with the ints of a given string
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

void Set::PrintSet (void) {
  PrintBits(set_);
}

void Set::operator=(std::string in) {
  /// @brief overload of =
  std::vector<int> test = ExtractIntegerWords(in);
  set_storage = Convert2(Range((test)));
}

void Set::operator + ( int sum) {
  /// @brief overload of +
  std::vector<int> temp;
  temp.push_back(sum);
  unsigned long int num = Convert (temp);
  this->set_ = Union(this->set_,num);
}

void Set::operator - ( int sum) {
  /// @brief overload of -
  std::vector<int> temp;
  temp.push_back(sum);
  unsigned long int num = Convert (temp);
  this->set_ = this->set_ ^ num;
}

bool Set::operator==(Set in) {
  /// @brief overload of ==
  if (in.set_ == set_) {
    return true;
  } else {
    return false;
  }
}

std::ostream& operator<<(std::ostream& os, Set& a) {
  /// @brief overload of <<
  a.PrintSet();
  return os;
}
/*
std::istream& operator>>(std::istream& in, Set& a) {
  std::istringstream in(str);
  return in;
}
*/
#endif