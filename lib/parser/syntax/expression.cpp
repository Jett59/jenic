#include "jenic/parser/parser.h"
#include "jenic/parser/syntax/value.h"

#include <iostream>

jenic::AbstractSyntaxNode* jenic::Parser::parseExpression(int* index) {
    int i = * index;
    if (tokens [i].type == jenic::TOKEN_NUMBER || tokens [i].type == jenic::TOKEN_STRING) {
        (*index)++;
        return new jenic::syntax::Value(tokens [i]);
    }
    std::cerr << "Error: unknown expression at offset " << i << std::endl;
    return new jenic::syntax::Value({.type = jenic::TOKEN_NULL});
}
