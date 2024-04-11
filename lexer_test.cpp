#include <iostream>
#include "lexer.hpp"
#include <string>
using namespace std;
int main(){
    string input = "=+(){},;";
    Lexer::lexer l = Lexer::New(input);
    cout << l.input << endl;
    Token::token tok;
    for (char c : input){
        tok = Lexer::NextToken(l);
        // cout << tok.literal << endl;
        cout << tok.literal << " " << Token::TokenToString(tok.type) << endl;
        l.readChar();
    }
    return 0;
}