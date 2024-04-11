
#ifndef LEXER_HPP
#define LEXER_HPP
#include <string>
#include "token.hpp"
namespace Lexer{
    struct lexer {
        std::string input;
        int position;
        int readPosition;
        char ch;
        lexer():position(0),readPosition(0){}
        void readChar(){
            // std::cout << readPosition << " " << position << std::endl;
            if (readPosition>=input.size()){
                ch = 0;
            }else{
                ch = input[readPosition];
            }
            position = readPosition;
            readPosition++;
        }

        
        
    };
    lexer New(std::string input);

    Token::token NextToken(Lexer::lexer l);

    Token::token newToken(Token::TokenType type, char ch);
}
#endif