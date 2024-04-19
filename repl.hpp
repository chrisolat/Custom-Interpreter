#include <iostream>
#include "lexer.hpp"
#include "token.hpp"
#include <string>
#define PROMPT ">> "

namespace repl{
    void start(std::istream& input, std::ostream& output);
}