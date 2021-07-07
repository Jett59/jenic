#include "jenic/parser/syntax/type.h"
#include <iostream>

jenic::syntax::StatementType jenic::syntax::getType(std::vector<jenic::Token> tokens, int offset) {
    jenic::Token token0 = tokens [offset];
    if (token0.type == jenic::TOKEN_IDENTIFIER) {
        jenic::Token token1 = tokens [offset + 1];
        if (token1.type == jenic::TOKEN_IDENTIFIER) {
            jenic::Token token2 = tokens [offset + 2];
            if (token2.type == jenic::TOKEN_STRUCTURE && token2.value == "(") {
                return jenic::syntax::StatementType::STATEMENT_FUNCTION;
            }
        }
    }
    std::cerr << "Error: unknown statement beginning at offset " << offset << std::endl;
    return jenic::syntax::StatementType::STATEMENT_NULL;
}
