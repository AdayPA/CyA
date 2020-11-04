// University of La Laguna
// College of Engineering and Tech
// Degree of Computer Science
// Subject: Computabilidad y Algoritmia (CyA)
// Course/Year: 2º 
// @praxis: Number 5 CyA - "Sets"
// @author: Aday Padilla Amaya
// @e-mail: alu0100843453@ull.edu.es
// @date: 04/11/2020
// @brief Set.h :  
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
#ifndef SET_H_
#define SET_H_

#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <fstream>

class Set {
  public:
    Set();
    Set(int);
    Set(std::string, std::string);
    ~Set();
    int size_of_set_;
    int counter_mod_;
    void Work (std::string);
    void SetOutput (std::ofstream&);
    std::string Write();
    void Clear();
    bool IsEmpty();
    bool Belong(int);
    void operator=(std::string);
    bool operator==(Set);
    void operator+(int);
    void operator-(int);
    void PrintSet (void);
    void PrintVectorSet(std::vector<unsigned long int>);
    inline int GetSizeOfSet(void) {return size_of_set_; };

  private:
    std::string pattern_string_;                  // save the pattern
    std::string alphabet_;                        // alphabet of the set
    void SetPattern(std::string);                 // setter of pattern
    void SetAlphabet(void);                       // automatic setter of alphabet
    void ConvertAlphabet(void);
    void ConvertPattern(void);
    std::vector<unsigned long int> set_alphabet_;
    std::vector<unsigned long int> set_pattern_;
    bool Belong(std::vector<unsigned long int>, std::vector<unsigned long int> );
    int ConvertToASCII(std::string);
    int ConvertToASCII(char);
    ////////////////////////// p5 ///////////////////////
    std::vector<unsigned long int> set_storage;
    std::vector<int> intergers_;
    unsigned long int set_;
    std::string expression_;
    std::string result_;                         
    int max_elements_;
    int& GetMaxElements(void);
    void SetMaxElements(int&);
    std::vector<std::string> Split (std::string, std::string);
    std::string FindOperators(std::string);
    void Operate(std::string, std::string);
    bool CheckSyntax(std::string);
    std::vector<std::vector<int>>  Range(std::vector<int>);
    unsigned long int Convert (std::vector<int>);
    std::vector<unsigned long int> Convert2 (std::vector<std::vector<int>>);
    unsigned long int Complement (unsigned long int);
    std::vector<unsigned long int> Complement2 (std::vector<unsigned long int>);
    const unsigned long int Union (unsigned long int, unsigned long int);
    std::vector<unsigned long int> Union2 (std::vector<unsigned long int>, 
                                          std::vector<unsigned long int>);
    unsigned long int Intersection (unsigned long int, unsigned long int);
    std::vector<unsigned long int> Intersection2 (std::vector<unsigned long int>, 
                                                  std::vector<unsigned long int>);
    unsigned long int RelativeComplement (unsigned long int, unsigned long int);
    std::vector<unsigned long int> RelativeComplement2 (std::vector<unsigned long int>, 
                                                        std::vector<unsigned long int>);
    void PrintBits (unsigned long int);
    std::vector<int> ExtractIntegerWords(std::string);
    void TransformToInt (void);
    std::istream& operator>>(std::istream& in);
};

std::ostream& operator<<(std::ostream& os, Set& a);
//std::istream& operator>>(std::ostream& in, Set& a);


#endif //SET_H_