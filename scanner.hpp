#ifndef scannerH
#define scannerH

#include <string>
#include <vector>
#include <deque>

namespace scanner {

    void setFileName(int argc, char* argv[]);

    const std::string getFileName();

    void readFromFile();

    const std::deque<std::string>& getUserInput();

};  // namespace inputParsing

#endif  // scannerH