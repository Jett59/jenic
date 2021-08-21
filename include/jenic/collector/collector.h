#ifndef _JENIC_COLLECTOR_COLLECTOR_H
#define _JENIC_COLLECTOR_COLLECTOR_H

#include "jenic/parser/ast.h"

namespace jenic {
    class Collection {
        public:
        jenic::AbstractSyntaxTree variables;
        jenic::AbstractSyntaxTree constants;
        jenic::AbstractSyntaxTree functions;
        Collection (jenic::AbstractSyntaxTree variableTree, jenic::AbstractSyntaxTree constantTree, jenic::AbstractSyntaxTree functionTree) {
            this->variables = variableTree;
            this->constants = constantTree;
            this->functions = functionTree;
        }
    };
    class Collector {
        private:
        jenic::AbstractSyntaxTree input;
        public:
        Collector(jenic::AbstractSyntaxTree input) {
            this->input = input;
        }
        jenic::Collection* collect ();
    };
}

#endif