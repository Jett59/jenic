#include "jenic_config.h"
#include <iostream>
#include "jenic/lexer/lexer.h"
#include "jenic/parser/parser.h"

int main (int argc, char* argv []) {
    std::cout << "Jenic Version" << JENIC_MAJOR_VERSION << "." << JENIC_MINOR_VERSION << "." << JENIC_PATCH_VERSION << std::endl;
    std::string line;
    std::getline(std::cin, line);
    jenic::Lexer lexer(line);
    std::vector<jenic::Token> tokens = lexer.lex();
    jenic::Parser parser(tokens);
    jenic::AbstractSyntaxTree tree = parser.parse();
    for (int i = 0; i < tree.size(); i ++) {
        std::cout << tree [i]->toString() << std::endl;
    }
return 0;
}
