#ifndef __JENIC_PARSER_SYNTAX_TYPE_H
#define __JENIC_PARSER_SYNTAX_TYPE_H

#include "jenic/lexer/token.h"

#include <vector>

namespace jenic {
    namespace syntax {
        enum class StatementType {
            STATEMENT_NULL,
            STATEMENT_FUNCTION
        };
        jenic::syntax::StatementType getType (std::vector<jenic::Token> tokens, int offset);
    }
}

#endif