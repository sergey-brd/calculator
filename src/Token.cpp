#include "Token.h"

#include "Exception.h"

static TokenType convertSymbolToOperator(const std::string &i_word)
{
  if (i_word.size() == 1)
    switch (i_word[0])
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

  throw SymbolConvertionException(i_word);
}

Token::Token(const std::string &i_value, TokenType i_type) : value(i_value), type(i_type)
{
  if (type == TokenType::SYMBOL)
    type = convertSymbolToOperator(i_value);
};
