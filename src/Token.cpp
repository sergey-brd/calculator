#include "Token.h"

#include <cassert>

Token::Token(const std::string &i_value, TokenType i_type) : value(i_value), type(i_type)
{
  if (type == TokenType::FLOAT_NUMBER)
    type = TokenType::NUMBER;
  else if (type == TokenType::SYMBOL)
  {
    assert(value.size() == 1);
    switch (value[0])
    {
    case '(':
      type = TokenType::OPENING_BRACKET;
      break;
    case ')':
      type = TokenType::CLOSING_BRACKET;
      break;
    default:
      type = TokenType::OPERATOR;
    }
  }
};
