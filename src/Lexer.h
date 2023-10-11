#pragma once

#include <string>
#include <vector>

enum class TokenType
{
  NUMBER,
  WORD,
  OPERATOR,
  OPENING_BRACKET,
  CLOSING_BRACKET,
  // used only for tokenize
  SYMBOL,
  FLOAT_NUMBER,
  SPACE,
  NONE
};

struct Token
{
  std::string value;
  TokenType type;
  Token(const std::string &i_value, TokenType i_type);
};

class Lexer
{
public:
  static std::vector<Token> tokenize(const std::string &i_input);
};
