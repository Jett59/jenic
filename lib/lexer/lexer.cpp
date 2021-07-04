#include "jenic/lexer/lexer.h"

namespace jenic {
    Lexer::Lexer(std::string str) {
        input = str;
    }
    std::vector<jenic::Token> next() {
        std::vector<jenic::Token> result;
        return result;
    }
}