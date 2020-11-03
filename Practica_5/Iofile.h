// University of La Laguna
// College of Engineering and Tech
// Degree of Computer Science
// Subject: Computabilidad y Algoritmia (CyA)
// Course/Year: 2º 
// @praxis: Number 5 CyA - ""
// @author: Aday Padilla Amaya
// @e-mail: alu0100843453@ull.edu.es
// @date: 26/11/2020
// @brief ./.cc:  This class help us to manage input and outpu files
//         
// @compile: $ make                                                    
// References: 
// 
// Lab exercise:
// 
// Version Control:
// 26/10/2020 - First version of the code 


#ifndef IOFILE_H_
#define IOFILE_H_

#include <string>

class IOFile {
  public:
    IOFile();
    IOFile(std::string, std::string);
    ~IOFile();

  private:
    std::string inputFile_;
    inline void Set_inputFile(const std::string& filename) { inputFile_ = filename; };
    inline std::string& Get_inputFile (void) { return inputFile_; };
    std::string outputFile_;
    inline void Set_outputFile(const std::string& filename) { outputFile_ = filename; };
    inline const std::string& Get_outputFile (void)  { return outputFile_; };
    std::string Get_line (const std::string&, const int&);
    int Count_lines (const std::string);
    constexpr const int& CountChar (void);
    const bool IsDigit(const std::string&);
    void OutFileSyntaxName (void);
    // permissions
    // size for file
    // error type
};

#endif //IOFILE_H_