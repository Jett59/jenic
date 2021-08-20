#ifndef __JENIC_PARSER_SYNTAX_VALUE_H
#define __JENIC_PARSER_SYNTAX_VALUE_H

#include "jenic/parser/ast.h"
#include "jenic/lexer/token.h"

namespace jenic {
    namespace syntax {
        class Value: public jenic::AbstractSyntaxNode {
            public:
            jenic::Token value;
            Value(jenic::Token value);
            jenic::syntax::StatementType getStatementType ();
            std::string toString();
        };
    }
}

#endif