#include "repl.hpp"

namespace repl {
    void start(std::istream& input, std::ostream& output){
        
        std::string line;
        
        while(1){
            std::cout << PROMPT;
            std::getline(input, line);
            if(line.empty()){return;}
            Lexer::lexer l = Lexer::New(line);
            Token::token tok;
            while(tok.type != Token::TokenType::EOF_){
                tok = Lexer::NextToken(l);
                std::cout << tok.literal << " " << Token::TokenToString(tok.type) << std::endl;
            }
            tok.type = Token::TokenType::ILLEGAL;
        }
    }
}