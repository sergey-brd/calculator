#pragma once

#include "Token.h"

#include <string>
#include <vector>

class Lexer
{
public:
  static std::vector<Token> tokenize(const std::string &i_input);
};
