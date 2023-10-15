#include "Exception.h"
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
    try
    {
      auto lexemes = Lexer::tokenize(input);
      auto node = parser.parse(lexemes);
      auto result = interpreter.eval(node);
      std::cout << (result.isInteger() ? result.get<int>() : result.get<double>()) << std::endl;
    }
    catch (const std::exception& e)
    {
      std::cout << e.what() << std::endl;
    }
  }

  return 0;
}
