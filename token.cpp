#include "token.hpp"

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
            default: return "UNKNOWN";
        }
    }
}
