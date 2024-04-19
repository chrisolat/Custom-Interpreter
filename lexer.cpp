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

    Token::token NextToken(Lexer::lexer& l){
        Token::token tok;
        skipWhitespace(l);
        switch (l.ch)
        {
        case '=':
            if(peekChar(l) == '='){
                char c = l.ch;
                l.readChar();
                tok = newToken(Token::TokenType::EQ, c + l.ch);
                tok.literal = "==";
            }else{
                tok = newToken(Token::TokenType::ASSIGN, l.ch);
            }
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
        case '-':
            tok = newToken(Token::TokenType::MINUS, l.ch);
            break;
        case '!':
            if(peekChar(l) == '='){
                char c = l.ch;
                l.readChar();
                tok = newToken(Token::TokenType::NOT_EQ, c + l.ch);
                tok.literal = "!=";
            }else{
                tok = newToken(Token::TokenType::BANG, l.ch);
            }
            break;
        case '*':
            tok = newToken(Token::TokenType::ASTERISK, l.ch);
            break;
        case '/':
            tok = newToken(Token::TokenType::SLASH, l.ch);
            break;
        case '>':
            tok = newToken(Token::TokenType::GT, l.ch);
            break;
        case '<':
            tok = newToken(Token::TokenType::LT, l.ch);
            break;
        case 0:
            tok = newToken(Token::TokenType::EOF_, l.ch);
            break;
        default:
            if(isLetter(l)){
                tok.literal = readIdentifier(l);
                tok.type = Token::LookupIdent(tok.literal);
                return tok;
            }else if(isDigit(l)){
                tok.type = Token::TokenType::INT;
                tok.literal = readNumber(l);
                return tok;
            }
            else{
                tok = newToken(Token::TokenType::ILLEGAL, l.ch);
            }
        
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

    std::string readIdentifier(Lexer::lexer& l){
        std::string ident = "";
        while(isLetter(l)){
            ident += l.ch;
            l.readChar();
            
        }
        return ident;
    }

    bool isLetter(Lexer::lexer& l){
        return 'a' <= l.ch && l.ch <= 'z' || 'A' <= l.ch && l.ch <= 'Z' || l.ch == '_';
    }

    bool isDigit(Lexer::lexer& l){
        return '0' <= l.ch && l.ch <= '9';
    }

    std::string readNumber(Lexer::lexer& l){
        std::string ident = "";
        while(isDigit(l)){
            ident += l.ch;
            l.readChar();
        }
        return ident;
    }

    void skipWhitespace(Lexer::lexer& l){
        while(l.ch == ' ' || l.ch == '\t' || l.ch == '\n' || l.ch == '\r'){
            l.readChar();
        }
    }

    char peekChar(Lexer::lexer& l){
        if(l.readPosition < l.input.size()){
            return l.input[l.readPosition];
        }
        return '\0';
    }
}