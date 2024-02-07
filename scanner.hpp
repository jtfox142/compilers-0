#ifndef scannerH
#define scannerH

#include <string>
#include <vector>
#include <deque>

namespace scanner {

    void getFileName(int argc, char* argv[]);

    void readFromFile();

    const std::deque<std::string>& userInput();

};  // namespace inputParsing

#endif  // scannerH