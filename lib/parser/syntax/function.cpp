#include "jenic/parser/syntax/function.h"
#include "jenic/parser/parser.h"

#include <iostream>

jenic::syntax::Function::Function(jenic::Token return_type, jenic::Token name, std::vector<std::pair<jenic::Token, jenic::Token>> args, jenic::AbstractSyntaxTree body) {
    this->return_type = return_type;
    this->name = name;
    this->args = args;
    this->body = body;
}
std::string jenic::syntax::Function::toString() {
    std::string result = return_type.value + " " + name.value + "(";
    for (int i = 0; i < args.size(); i ++) {
        std::pair<jenic::Token, jenic::Token> arg = args [i];
        result += arg.first.value + ": " + arg.second.value + ", ";
    }
    result += ")";
    if (body.size() > 0) {
        result += "{\n";
        for (int i = 0; i < body.size(); i ++) {
            result += body [i]->toString() + "\n";
        }
        result += "}";
    }else {
        result += ";";
    }
    return result;
}

jenic::AbstractSyntaxNode* jenic::Parser::parseFunction(int * index) {
    int i = * index;
    jenic::Token return_type = tokens [i];
    jenic::Token name = tokens [i + 1];
    std::vector<std::pair<jenic::Token, jenic::Token>> args;
    i += 2;
    while (tokens [i].value != ")") {
        jenic::Token type = tokens [ i + 1];
        if (type.value == ")") {
            i++;
            break;
        }
        jenic::Token name = tokens [i + 2];
        if (type.type != jenic::TOKEN_IDENTIFIER || name.type != TOKEN_IDENTIFIER) {
            std::cerr << "Error: unexpected token " << type.value << " " << name.value << "at index " << i << std::endl;
            break;
        }
        std::pair<jenic::Token, jenic::Token> arg(type, name);
        args.push_back(arg);
        i += 3;
    }
    i++;
    jenic::AbstractSyntaxTree body;
    if (tokens [i].value == "{") {
        body = parse(&i);
    }
    * index = i;
    return new jenic::syntax::Function(return_type, name, args, body);
}
