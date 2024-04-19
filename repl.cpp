#include "repl.hpp"

namespace repl {
    void start(std::istream& input, std::ostream& output){
        
        std::string line;
        
        while(1){
            std::cout << PROMPT;
            std::getline(input, line);
            // std::cout << line << std::endl;
            if(line.empty()){return;}
            Lexer::lexer l = Lexer::New(line);
            // std::cout << l.input << l.position << std::endl;
            Token::token tok;
            // std::cout <<Token::TokenToString(tok.type) << std::endl;
            while(tok.type != Token::TokenType::EOF_){
                tok = Lexer::NextToken(l);
                std::cout << tok.literal << " " << Token::TokenToString(tok.type) << std::endl;
            }
            tok.type = Token::TokenType::ILLEGAL;
        }
    }
}