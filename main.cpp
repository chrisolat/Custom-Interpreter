#include <iostream>
#include "repl.hpp"

int main() {
    repl::start(std::cin, std::cout);
    return 0;
}
