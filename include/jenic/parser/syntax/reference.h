#ifndef _JENIC_PARSER_SYNTAX_REFERENCE_H
#define _JENIC_PARSER_SYNTAX_REFERENCE_H

#include "jenic/parser/ast.h"
#include "jenic/lexer/token.h"

namespace jenic {
    namespace syntax {
        class Reference: public AbstractSyntaxNode {
            public:
                jenic::Token identifier;
                Reference(jenic::Token identifier) {
                    this->identifier = identifier;
                }
                std::string toString() {
                    return identifier.value;
                }
                jenic::syntax::StatementType getStatementType() {
                    return jenic::syntax::StatementType::STATEMENT_REFERENCE;
                }
        };
    }
}

#endif
