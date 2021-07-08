#include "jenic/parser/syntax/return.h"

jenic::syntax::Return::Return(jenic::AbstractSyntaxNode* value) {
    this->value = value;
}
std::string jenic::syntax::Return::toString() {
    return "return " + value->toString() + ";";
}
