#include <iostream>
#include <string>
#include "lexer.hpp"
#include "token.hpp"

namespace Lexer{
    lexer New(std::string input){
        Lexer::lexer l;
        l.input = input;
        l.readChar();
        return l;
    }

    Token::token NextToken(Lexer::lexer l){
        Token::token tok;
        switch (l.ch)
        {
        case '=':
            tok = newToken(Token::TokenType::ASSIGN, l.ch);
            break;
        case ';':
            tok = newToken(Token::TokenType::SEMICOLON, l.ch);
            break;
        case '(':
            tok = newToken(Token::TokenType::LPAREN, l.ch);
            break;
        case ')':
            tok = newToken(Token::TokenType::RPAREN, l.ch);
            break;
        case ',':
            tok = newToken(Token::TokenType::COMMA, l.ch);
            break;
        case '{':
            tok = newToken(Token::TokenType::LBRACE, l.ch);
            break;
        case '+':
            tok = newToken(Token::TokenType::PLUS, l.ch);
            break;
        case '}':
            tok = newToken(Token::TokenType::RBRACE, l.ch);
            break;
        case 0:
            tok = newToken(Token::TokenType::EOF_, l.ch);
            break;
        
        }
        l.readChar();
        return tok;
    }
    Token::token newToken(Token::TokenType type, char ch){
        Token::token tok;
        tok.type = type;
        tok.literal = std::string(1, ch);
        return tok;
    }


}