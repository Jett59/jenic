#include "jenit/lexer/lexer.h"

namespace jenic {
    class Lexer {
private:
std::string input;
public:
Lexer(std::string str) {
    input = str;
}
std::vector<jenit::Token> next() {
    std::vector<jenit::Token> result;
    return result;
}
    };
}