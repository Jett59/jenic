#include "jenic/parser/parser.h"
#include "jenic/parser/syntax/type.h"

#include <iostream>
#include <cstdlib>

jenic::Parser::Parser(std::vector<jenic::Token> tokens) {
    this->tokens = tokens;
}

jenic::AbstractSyntaxTree jenic::Parser::parse() {
    int index = 0;
    return parse(&index);
}

jenic::AbstractSyntaxTree jenic::Parser::parse(int *index) {
    jenic::AbstractSyntaxTree tree;
    int i = *index;
    bool isBlock = false;
    if (tokens[i].value == "{") {
        isBlock = true;
        i++;
    }
    for (; i < tokens.size(); i++) {
        if (isBlock && tokens[i].value == "}") {
            break;
        }
        jenic::syntax::StatementType statementType = jenic::syntax::getType(
                tokens, i);
        switch (statementType) {
            case jenic::syntax::StatementType::STATEMENT_FUNCTION:
                tree.push_back(this->parseFunction(&i));
                break;
            case jenic::syntax::StatementType::STATEMENT_RETURN:
                tree.push_back(parseReturn(&i));
                break;
            default:
                std::cerr << "Error: unknown statement at index " << i
                        << std::endl;
                std::exit(-1);
        }
    }
    *index = i;
    return tree;
}
