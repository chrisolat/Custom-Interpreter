#ifndef AST_HPP
#define AST_HPP
#include <string>

namespace ast{

    struct Node{
        virtual std::string TokenLiteral() = 0;
    };

    struct Statement : public Node{
        virtual void statementNode() = 0;
    };

    struct Expression : public Node{
        virtual void expressionNode() = 0;
    };

}
#endif