#include "jenic/parser/syntax/type.h"
#include <iostream>

jenic::syntax::StatementType jenic::syntax::getType(std::vector<jenic::Token> tokens, int offset) {
    if (tokens.size() > offset) {
    jenic::Token token0 = tokens [offset];
    if (token0.type == jenic::TOKEN_IDENTIFIER) {
        if (tokens.size() > offset + 1) {
        jenic::Token token1 = tokens [offset + 1];
        if (token1.type == jenic::TOKEN_IDENTIFIER) {
            if (tokens.size() > offset + 2) {
            jenic::Token token2 = tokens [offset + 2];
            if (token2.type == jenic::TOKEN_STRUCTURE && token2.value == "(") {
                return jenic::syntax::StatementType::STATEMENT_FUNCTION;
            } // token2.type
            } // tokens.size
        } // token1.type
        } // tokens.size
    } // token0.type
    } // tokens.size
    std::cerr << "Error: unknown statement beginning at offset " << offset << std::endl;
    return jenic::syntax::StatementType::STATEMENT_NULL;
}
