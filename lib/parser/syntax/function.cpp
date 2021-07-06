#include "jenic/parser/syntax/function.h"

jenic::syntax::Function::Function(jenic::Token return_type, jenic::Token name, std::vector<std::pair<jenic::Token, jenic::Token>> args) {
    this->return_type = return_type;
    this->name = name;
    this->args = args;
}
std::string jenic::syntax::Function::toString() {
    std::string result = return_type.value + " " + name.value + "(";
    for (int i = 0; i < args.size(); i ++) {
        std::pair<jenic::Token, jenic::Token> arg = args [i];
        result += arg.first.value + ": " + arg.second.value + ", ";
    }
    return result + ")";
}
