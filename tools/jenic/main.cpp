#include "jenic_config.h"
#include <iostream>
#include "jenic/lexer/lexer.h"
#include "jenic/parser/parser.h"
#include "jenic/collector/collector.h"

int main (int argc, char* argv []) {
    std::cout << "Jenic Version" << JENIC_MAJOR_VERSION << "." << JENIC_MINOR_VERSION << "." << JENIC_PATCH_VERSION << std::endl;
    std::string line;
    std::getline(std::cin, line);
    jenic::Lexer lexer(line);
    std::vector<jenic::Token> tokens = lexer.lex();
    jenic::Parser parser(tokens);
    jenic::AbstractSyntaxTree tree = parser.parse();
    jenic::Collector collector(tree);
    jenic::Collection* collection = collector.collect();
    for (int i = 0; i < collection->variables.size(); i ++) {
        std::cout << collection->variables [i]->toString() << std::endl;
        delete collection->variables [i];
    }
    for (int i = 0; i < collection->constants.size(); i ++) {
        std::cout << collection->constants [i]->toString() << std::endl;
        delete collection->constants [i];
    }
    for (int i = 0; i < collection->functions.size(); i ++) {
        std::cout << collection->functions[i]->toString() << std::endl;
        delete collection->functions[i];
    }
    delete collection;
return 0;
}
