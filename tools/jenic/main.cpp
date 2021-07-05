#include "jenic_config.h"
#include <iostream>
#include "jenic/lexer/lexer.h"

int main (int argc, char* argv []) {
std::cout << "Jenic Version" << JENIC_MAJOR_VERSION << "." << JENIC_MINOR_VERSION << "." << JENIC_PATCH_VERSION << std::endl;
std::string line;
std::getline(std::cin, line);
jenic::Lexer lexer(line);
std::vector<jenic::Token> tokens = lexer.lex();
for (int i = 0; i < tokens.size(); i ++) {
    jenic::Token token = tokens [i];
    std::cout << token.type << " " << token.value << std::endl;
}
}