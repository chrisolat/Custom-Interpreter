#include "ast.hpp"
#include "token.hpp"
#include <vector>
#include <string>

namespace ast{

    struct Program {
        std::vector<Statement> Statements;

        std::string TokenLiteral(){
            if(Statements.size() > 0){
                return Statements[0].TokenLiteral();
            }else{
                return "";
            }
        }
    };

    struct Identifier : public Expression {
        Token::token Token;
        std::string Value;

        void expressionNode() {}
        std::string TokenLiteral() { return Token.literal; }

    };

    struct LetStatement : public Statement {
        Token::token Token;
        Identifier* Name;
        Expression* Value;

        void statementNode() {}
        std::string TokenLiteral(){ return Token.literal; }
    };

    

}