#ifndef __JENIC_LEXER_TOKEN_H
#define __JENIC_LEXER_TOKEN_H

#include <string>

namespace jenic {
    enum TokenType {
token_identifier
    };
typedef struct {
    std::string value;
    jenic::TokenType type;
} Token;
}

#endif