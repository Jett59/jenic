#include "jenic/lexer/lexer.h"
#include <iostream>
#include <cstdlib>

    jenic::Lexer::Lexer(std::string str) {
        input = str;
    }
    std::vector<jenic::Token> jenic::Lexer::lex() {
        std::vector<jenic::Token> result;
        jenic::Token* token = new jenic::Token;
        token->type = jenic::TOKEN_NULL;
        for (int i = 0; i < input.length(); i ++) {
            char c = input [i];
            if (token->type == jenic::TOKEN_STRING) {
                if (c == '\\') {
                    token->value += c;
                    token->value += input [i + 1];
                    i ++;
continue;
                }
                if (IS_STRING(c)) {
result.push_back(*token);
delete token;
token = new jenic::Token;
token->type = jenic::TOKEN_NULL;
continue;
                }else {
token->value += c;
                }
            }else if (token->type != jenic::TOKEN_NULL) {
                if (c == ' ' || c == '\n' || c == '\t'
                || IS_STRUCTURE(c)
                || ((token->type == jenic::TOKEN_OPERATOR) != (IS_OPERATOR(c)))
                || IS_STRING(c)) {
                    result.push_back(*token);
                    delete token;
                    token = new jenic::Token;
                    token->type = jenic::TOKEN_NULL;
                }else {
                    token->value += c;
                }
            }
            if (token->type == jenic::TOKEN_NULL) {
                if (c == ' ' || c == '\t' || c == '\n' || c == '\r') {
                    continue;
                }else if (IS_IDENTIFIER(c)) {
                    token->type = jenic::TOKEN_IDENTIFIER;
                    token->value += c;
                }else if (IS_NUMBER(c)) {
                    token->type = jenic::TOKEN_NUMBER;
                    token->value += c;
                }else if (IS_STRING(c)) {
                    token->type = jenic::TOKEN_STRING;
                }else if(IS_STRUCTURE(c)) {
                    token->type = jenic::TOKEN_STRUCTURE;
                    token->value += c;
                    result.push_back(*token);
                    delete token;
                    token = new jenic::Token;
                    token->type = jenic::TOKEN_NULL;
                }else if (IS_OPERATOR(c)) {
                    token->type= jenic::TOKEN_OPERATOR;
                    token->value += c;
                }else {
                    std::cerr << "Error: Unknown token " << c << std::endl;
                    std::exit(-1);
                }
            }
        }
        if (token->type != jenic::TOKEN_NULL) {
if (token->type == jenic::TOKEN_STRING) {
    std::cerr << "Error: Expected string terminator (\"/')" << std::endl;
    std::exit(-1);
}
result.push_back (*token);
delete token;
        }else {
            delete token;
        }
        return result;
    }
