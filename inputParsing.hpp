#ifndef inputParsingH
#define inputParsingH

#include <string_view>
#include <vector>

namespace inputParsing {

    void parse(int argc, char* argv[]);

    const std::vector<std::string_view>& userInput();

};  // namespace inputParsing

#endif  // inputParsingH