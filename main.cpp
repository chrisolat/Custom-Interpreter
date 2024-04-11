#include <iostream>
#include "token.hpp"
#include "lexer.hpp"

int main() {
    std::cout << Token::TokenToString(Token::TokenType::EOF_) << std::endl;
    return 0;
}
