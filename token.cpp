#include "token.hpp"
#include <unordered_map>
#include <iostream>
namespace Token {
    std::string TokenToString(TokenType token) {
        switch (token) {
            case TokenType::ILLEGAL: return "ILLEGAL";
            case TokenType::EOF_: return "EOF";
            case TokenType::IDENT: return "IDENT";
            case TokenType::INT: return "INT";
            case TokenType::ASSIGN: return "ASSIGN";
            case TokenType::PLUS: return "PLUS";
            case TokenType::COMMA: return "COMMA";
            case TokenType::SEMICOLON: return "SEMICOLON";
            case TokenType::LPAREN: return "LPAREN";
            case TokenType::RPAREN: return "RPAREN";
            case TokenType::LBRACE: return "LBRACE";
            case TokenType::RBRACE: return "RBRACE";
            case TokenType::FUNCTION: return "FUNCTION";
            case TokenType::LET: return "LET";
            case TokenType::MINUS: return "MINUS";
            case TokenType::BANG: return "BANG";
            case TokenType::ASTERISK: return "ASTERISK";
            case TokenType::SLASH: return "SLASH";
            case TokenType::LT: return "LT";
            case TokenType::GT: return "GT";
            case TokenType::TRUE: return "TRUE";
            case TokenType::FALSE: return "FALSE";
            case TokenType::IF: return "IF";
            case TokenType::ELSE: return "ELSE";
            case TokenType::RETURN: return "RETURN";
            case TokenType::EQ: return "EQ";
            case TokenType::NOT_EQ: return "NOT_EQ";
            default: return "UNKNOWN";
        }
    }

    std::unordered_map<std::string, TokenType> keyWords{
        {"fn", TokenType::FUNCTION},
        {"let", TokenType::LET},

        {"true", TokenType::TRUE},
        {"false", TokenType::FALSE},
        {"if", TokenType::IF},
        {"else", TokenType::ELSE},
        {"return", TokenType::RETURN}
    };

    TokenType LookupIdent(std::string ident){
        if(keyWords.find(ident) != keyWords.end()){
            return keyWords[ident];
        }
        return TokenType::IDENT;
    }
}
