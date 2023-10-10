#pragma once

#include <string>
#include <vector>

enum class TokenType
{
  NUMBER,
  WORD,
  SYMBOL
};

struct Token
{
  std::string value;
  TokenType type;
  Token(const std::string &i_value, TokenType i_type) : value(i_value), type(i_type){};
};

class Lexer
{
public:
  static std::vector<Token> tokenize(const std::string &i_input);
};
