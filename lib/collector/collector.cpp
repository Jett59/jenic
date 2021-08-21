#include "jenic/collector/collector.h"

#include <iostream>
#include <cstdlib>

jenic::Collection* jenic::Collector::collect () {
    jenic::AbstractSyntaxTree variables;
    jenic::AbstractSyntaxTree constants;
    jenic::AbstractSyntaxTree functions;
    for (int i = 0; i < input.size(); i ++) {
        jenic::AbstractSyntaxNode* node = input [i];
        switch (node->getStatementType()) {
            case jenic::syntax::StatementType::STATEMENT_FUNCTION:
            functions.push_back (node);
            break;
            default:
            std::cerr << "Only functions, variables and constants may appear at the root scope";
            std::exit(-1);
        }
    }
   return new jenic::Collection (variables, constants, functions);
}