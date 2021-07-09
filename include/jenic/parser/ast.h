#ifndef __JENIC_PARSER_AST_H
#define __JENIC_PARSER_AST_H

#include <string>
#include <vector>

namespace jenic {
    class AbstractSyntaxNode {
public:
virtual ~AbstractSyntaxNode () {}
virtual std::string toString() = 0;
    };
    typedef std::vector<jenic::AbstractSyntaxNode*> AbstractSyntaxTree;
}

#endif