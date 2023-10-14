#include "Interpreter.h"
#include "Lexer.h"
#include "Parser.h"

#include <iostream>

int main()
{
  std::string input;
  Parser parser;
  Interpreter interpreter;
  while (std::getline(std::cin, input))
  {
    if (input.empty())
      break;
    auto lexemes = Lexer::tokenize(input);
    auto node = parser.parse(lexemes);
    auto result = interpreter.eval(node);
    std::cout << (result.isInteger() ? result.get<int>() : result.get<double>()) << std::endl;
  }

  return 0;
}
