#include "jenic/parser/parser.h"
#include "jenic/parser/syntax/type.h"

#include <iostream>

jenic::Parser::Parser(std::vector<jenic::Token> tokens) {
    this->tokens = tokens;
}

jenic::AbstractSyntaxTree jenic::Parser::parse() {
    int index = 0;
    return parse(&index);
}

jenic::AbstractSyntaxTree jenic::Parser::parse(int * index) {
    jenic::AbstractSyntaxTree tree;
    int i = * index;
    for (; i < tokens.size(); i ++) {
        jenic::syntax::StatementType statementType = jenic::syntax::getType(tokens, i);
        switch (statementType) {
            case jenic::syntax::StatementType::STATEMENT_FUNCTION:
            tree.push_back(this->parseFunction(&i));
            break;
            default:
            std::cerr << "Error: unknown statement at index " << i << std::endl;
            * index = i;
            return tree;
        }
    }
    * index = i;
    return tree;
}
