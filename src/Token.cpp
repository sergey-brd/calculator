#include "Token.h"

#include <cassert>

static TokenType convertSymbolToOperator(char i_c)
{
  switch (i_c)
  {
  case '(':
    return TokenType::OPENING_BRACKET;
  case ')':
    return TokenType::CLOSING_BRACKET;
  case '+':
    return TokenType::PLUS;
  case '-':
    return TokenType::MINUS;
  case '*':
    return TokenType::MULTIPLY;
  case '/':
    return TokenType::DIVIDE;
  }
  return TokenType::OPERATOR;
}

Token::Token(const std::string &i_value, TokenType i_type) : value(i_value), type(i_type)
{
  if (type == TokenType::FLOAT_NUMBER)
    type = TokenType::NUMBER;
  else if (type == TokenType::SYMBOL)
  {
    assert(value.size() == 1);
    type = convertSymbolToOperator(value[0]);
  }
};
