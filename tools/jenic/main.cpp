#include "jenic_config.h"
#include <iostream>
#include "jenic/lexer/lexer.h"

int main (int argc, char* argv []) {
std::cout << "Jenic Version" << JENIC_MAJOR_VERSION << "." << JENIC_MINOR_VERSION << "." << JENIC_PATCH_VERSION << std::endl;
std::string line;
std::getline(std::cin, line);
std::cout << "Compiling text from stdin: " << line << std::endl;
jenic::Lexer lexer(line);
std::vector<jenic::Token> first = lexer.next();
for (int i = 0; i < first.size(); i ++) {
    std::cout << first [i].value << " ";
}
}