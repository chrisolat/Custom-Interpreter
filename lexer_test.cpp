#include <iostream>
#include "lexer.hpp"
#include <string>
using namespace std;
int main(){
    // string input = "==";
    string input = "let five = 5;"
    "let ten = 10;"
    "let add = fn(x, y) {"
    "x + y;"
    "};"
    "let result = add(five, ten);"
    "!<>-"
    "if (5 < 10) {"
    "return true;"
    "} else {"
    "return false;"
    "}"
    "== !="
    ;
    Lexer::lexer l = Lexer::New(input);
    cout << l.input << endl;
    Token::token tok;
    while(tok.type != Token::TokenType::EOF_){
        tok = Lexer::NextToken(l);
        cout << tok.literal << " " << Token::TokenToString(tok.type) << endl;
    }
    return 0;
}