#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <string>



namespace Token {
    
    enum class TokenType {
        ILLEGAL,
        EOF_, 
        // Identifiers + literals
        IDENT,  // add, foobar, x, y, ...
        INT,  // 1343456
        // Operators
        ASSIGN, 
        PLUS, 
        // Delimiters
        COMMA, 
        SEMICOLON, 
        LPAREN, 
        RPAREN, 
        LBRACE,
        RBRACE,
        // Keywords
        FUNCTION,
        LET
    };
    struct token
    {
        std::string literal;
        TokenType type;

        token& operator=(const token& other){
            if(this != &other){
                literal = other.literal;
                type = other.type;
            }
            return *this;
        }
    };
    std::string TokenToString(TokenType token);

    // token NexToken(Le)
}

#endif
