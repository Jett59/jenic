#include "jenic/parser/syntax/value.h"

jenic::syntax::Value::Value(jenic::Token value) {
    this->value = value;
}
std::string jenic::syntax::Value::toString() {
    return value.value;
}
