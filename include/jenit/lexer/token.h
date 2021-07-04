#ifndef __JENIT_LEXER_TOKEN_H
#define __FENIT_LEXER_TOKEN_H

#include <string>

namespace jenit {
    enum TokenType {
token_identifier
    };
typedef struct {
    std::string value;
    jenit::TokenType type;
} Token;
}

#endif