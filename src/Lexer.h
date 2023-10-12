#pragma once

#include "Token.h"

#include <string>
#include <list>

class Lexer
{
public:
  static std::list<Token> tokenize(const std::string &i_input);
};
