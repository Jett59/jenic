#ifndef __JENIT_LEXER_LEXER_H
#define __JENIT_LEXER_LEXER_H

#include <string>
#include <vector>
#include "jenit/lexer/token.h"

namespace jenit {
    class Lexer {
public:
Lexer(std::string str);
std::vector<jenit::Token> next();
    };
}

#endif