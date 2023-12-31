#pragma once

#include <string>

enum class TokenType
{
  INTEGER,
  FLOAT,
  WORD,
  PLUS,
  MINUS,
  MULTIPLY,
  DIVIDE,
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
