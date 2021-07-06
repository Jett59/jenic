#include "jenic/parser/parser.h"

jenic::Parser::Parser(std::vector<jenic::Token> tokens) {
    this->tokens = tokens;
}
jenic::AbstractSyntaxTree jenic::Parser::parse() {
    jenic::AbstractSyntaxTree tree;
    return tree;
}