#ifndef __JENIC_PARSER_PARSER_H
#define __JENIC_PARSER_PARSER_H

#include "jenic/parser/ast.h"
#include "jenic/lexer/token.h"

namespace jenic {
    class Parser {
        private:
        std::vector<jenic::Token> tokens;
        public:
        Parser(std::vector<jenic::Token> tokens);
        jenic::AbstractSyntaxTree parse();
    };
}

#endif