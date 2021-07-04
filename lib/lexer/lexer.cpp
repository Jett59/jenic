#include "jenic/lexer/lexer.h"

namespace jenic {
    jenic::Lexer::Lexer(std::string str) {
        input = str;
    }
    std::vector<jenic::Token> jenic::Lexer::next() {
        std::vector<jenic::Token> result;
        return result;
    }

}