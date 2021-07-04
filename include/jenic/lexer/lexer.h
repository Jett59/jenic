#ifndef __JENIT_LEXER_LEXER_H
#define __JENIT_LEXER_LEXER_H

#include <string>
#include <vector>
#include "jenic/lexer/token.h"

namespace jenic {
    class Lexer {
        private:
        std::string input;
public:
Lexer(std::string str);
std::vector<jenic::Token> next();
    };
}

#endif