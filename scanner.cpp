//Inspiration for options parsing code taken from:
//https://medium.com/@mostsignificant/3-ways-to-parse-command-line-arguments-in-c-quick-do-it-yourself-or-comprehensive-36913284460f
#include "scanner.hpp"

#include <vector>
#include <string>
#include <stdexcept>
#include <fstream>
#include <iostream>
#include <deque>

namespace {

    static std::deque<std::string> _userInput;
    static std::string _fileName;

} //namespace

void scanner::setFileName(int argc, char* argv[]) {

    //If there are no provided args, initiate place user input into a temporary file
    //The first argument should always be the path to the program
    if(argc <= 1) {
        std::ofstream defaultFile;
        _fileName = "default.txt";
        //Need to convert string to c string for .open() function call
        defaultFile.open(_fileName.c_str(), std::ios::out | std::ios::trunc);

        std::string userInput;
        std::getline(std::cin, userInput);

        defaultFile << userInput;
        defaultFile.close();

        std::cout << "\nDefault file has received input.\n";
    }
    else { //Otherwise, attempt to use the filename provided to the executable
        _fileName = argv[1];
    }
}

//Pushes file data onto a deque, which is then used to build the tree
void scanner::readFromFile() {
    std::cout << "filename inside of read function: " << _fileName.c_str() << std::endl;
    std::ifstream inputFile (_fileName.c_str());
    std::string word;

    if(inputFile.is_open()) {
        std::cout << "File " << _fileName << " is open." << std::endl;
        while(!inputFile.eof()) {
            //Not sure if I need to do this every time, but the files should be small enough that the extra overhead will not matter
            if(inputFile.fail() || inputFile.bad()) {
                throw std::runtime_error("ERROR: bad file read");
            }

            inputFile >> word;
            _userInput.push_back(word);
        }
    }
    else {
        throw std::runtime_error("ERROR: could not open file. Possible bad file name.");
    }

    inputFile.close();
    std::cout << "File read complete. preTreeInput deque has been filled." << std::endl;
}

const std::deque<std::string>& scanner::getUserInput() {
    return _userInput;
}

const std::string scanner::getFileName() {
    return _fileName;
}