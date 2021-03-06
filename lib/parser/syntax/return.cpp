#include "jenic/parser/syntax/return.h"
#include "jenic/parser/parser.h"

jenic::syntax::Return::Return(jenic::AbstractSyntaxNode *value) {
    this->value = value;
}
jenic::syntax::Return::~Return() {
    delete value;
}

std::string jenic::syntax::Return::toString() {
    return "return " + value->toString() + ";";
}

jenic::AbstractSyntaxNode* jenic::Parser::parseReturn(int *index) {
    int i = *index;
    i++;
    jenic::AbstractSyntaxNode *value = parseExpression(&i);
    *index = i;
    return new jenic::syntax::Return(value);
}

jenic::syntax::StatementType jenic::syntax::Return::getStatementType() {
    return jenic::syntax::StatementType::STATEMENT_RETURN;
}
