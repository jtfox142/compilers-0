//Inspiration for options parsing code taken from:
//https://medium.com/@mostsignificant/3-ways-to-parse-command-line-arguments-in-c-quick-do-it-yourself-or-comprehensive-36913284460f
#include "inputParsing.hpp"

#include <vector>
#include <string_view>
#include <string>
#include <stdexcept>
#include <fstream>

namespace {

    static std::vector<std::string_view> _preTreeInput;
    static bool _fileFlagSet = false;

} //namespace

void inputParsing::parse(int argc, char* argv[]) {
    const std::vector<std::string_view> args(argv + 1, argv + argc);

    for(const auto& arg : args) {
        if(_preTreeInput.empty()) {
            if(arg == "-f" || arg == "--filename") {
                if(_fileFlagSet) {
                    throw std::runtime_error("ERROR: the -f/--filename parameter cannot be used twice.");
                }
                _fileFlagSet = true;
                continue;
            }
        }

        if(_fileFlagSet) {
            readFromFile(arg);
            //Do not pay attention to any args after the first provided filename
            break;
        }
    }
}

//Pushes the contents of the given file onto the userInput vector
void readFromFile(std::string_view filename) {
    static std::ifstream inputFile (filename);
    std::string word;

    if(inputFile.is_open()) {
        while(!inputFile.eof()) {
            //Not sure I need to do this every time, but the files should be small enough that the extra overhead will not matter
            if(inputFile.bad() || inputFile.fail()) {
                throw std::runtime_error("ERROR: bad file read");
            }

            inputFile >> word;
            _preTreeInput.push_back(word);
        }
    }
    else {
        throw std::runtime_error("ERROR: could not open file");
    }
}

const std::vector<std::string_view>& inputParsing::userInput() {
    return _preTreeInput;
}