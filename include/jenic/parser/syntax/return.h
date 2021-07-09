#ifndef __JENIC_PARSER_SYNTAX_RETURN_H
#define __JENIC_PARSER_SYNTAX_RETURN_H

#include "jenic/parser/ast.h"

namespace jenic {
    namespace syntax {
        class Return: public jenic::AbstractSyntaxNode {
            public:
            jenic::AbstractSyntaxNode* value;
            Return(jenic::AbstractSyntaxNode* value);
            ~Return();
            std::string toString();
        };
    }
}

#endif