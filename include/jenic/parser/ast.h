#ifndef __JENIC_PARSER_AST_H
#define __JENIC_PARSER_AST_H

#include <string>
#include <vector>
#include "jenic/parser/syntax/type.h"

namespace jenic {
    class AbstractSyntaxNode {
public:
virtual ~AbstractSyntaxNode () {}
virtual jenic::syntax::StatementType getStatementType () = 0;
virtual std::string toString() = 0;
    };
    typedef std::vector<jenic::AbstractSyntaxNode*> AbstractSyntaxTree;
}

#endif