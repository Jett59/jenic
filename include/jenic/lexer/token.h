#ifndef __JENIC_LEXER_TOKEN_H
#define __JENIC_LEXER_TOKEN_H

#include <string>
#include <ctype.h>

namespace jenic {
    enum TokenType {
        TOKEN_NULL,
TOKEN_IDENTIFIER,
TOKEN_NUMBER,
TOKEN_STRING,
TOKEN_STRUCTURE,
TOKEN_OPERATOR
};
#define IS_IDENTIFIER(c) (\
isalpha(c) || \
c == '_' \
)
#define IS_NUMBER(c) (\
isdigit(c) \
)
    #define IS_STRING(c) (\
    c == '\'' || \
    c == '"' \
    )
    #define IS_STRUCTURE(c) (\
    c == ';' || \
    c == '{' || \
    c == '}' || \
    c == '(' || \
    c == ')' || \
    c == ',' \
    )
    #define IS_OPERATOR(c) (\
    c == '+' || \
    c == '-' || \
    c == '/' || \
    c == '*' || \
    c == '%' || \
    c == '=' || \
    c == '!' || \
    c == '|' || \
    c == '&' \
    )

typedef struct {
    std::string value;
    jenic::TokenType type;
} Token;
}

#endif