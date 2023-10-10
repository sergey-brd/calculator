#pragma once

#include <string>
#include <vector>

class Lexer
{
public:
  static std::vector<std::string> tokenize(const std::string &i_input);
};
