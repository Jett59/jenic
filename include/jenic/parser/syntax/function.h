#ifndef __JENIC_PARSER_SYNTAX_FUNCTION_H
#define __JENIC_PARSER_SYNTAX_FUNCTION_H

#include "jenic/lexer/token.h"
#include "jenic/parser/ast.h"

#include <tuple>
#include <vector>

namespace jenic {
    namespace syntax {
        class Function: public AbstractSyntaxNode {
            public:
            jenic::Token return_type;
            jenic::Token name;
            std::vector<std::pair<jenic::Token, jenic::Token>> args;
            Function(jenic::Token return_type, jenic::Token name, std::vector<std::pair<jenic::Token, jenic::Token>> args);
            std::string toString();
        };
    }
}

#endif