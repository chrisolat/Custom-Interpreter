
#ifndef LEXER_HPP
#define LEXER_HPP
#include <string>
#include <unordered_map>
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

    Token::token NextToken(Lexer::lexer& l);

    Token::token newToken(Token::TokenType type, char ch);

    std::string readIdentifier(Lexer::lexer& l);

    bool isLetter(Lexer::lexer& l);

    bool isDigit(Lexer::lexer& l);

    std::string readNumber(Lexer::lexer& l);

    void skipWhitespace(Lexer::lexer& l);
}
#endif