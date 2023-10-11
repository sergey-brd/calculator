#include "Lexer.h"

#include <cctype>
#include <iostream>

Token::Token(const std::string &i_value, TokenType i_type) : value(i_value), type(i_type)
{
  if (type == TokenType::FLOAT_NUMBER)
    type = TokenType::NUMBER;
  else if (type == TokenType::SYMBOL)
  {
    assert(value.size() == 1);
    if (value[0] == '(')
      type = TokenType::OPENING_BRACKET;
    else if (value[0] == ')')
      type = TokenType::CLOSING_BRACKET;
    else
      type = TokenType::OPERATOR;
  }
};

std::vector<Token> Lexer::tokenize(const std::string &i_input)
{
  std::vector<Token> ret;
  int prevToken = 0;
  TokenType type = TokenType::NONE;
  for (int i = 0; i < i_input.size(); ++i)
  {
    // check if token ends
    if (type == TokenType::NUMBER && !std::isdigit(i_input[i]) && i_input[i] != '.' || // after number is not point and not number
        type == TokenType::FLOAT_NUMBER && !std::isdigit(i_input[i]) ||                // after float number is not number
        type == TokenType::WORD && !std::isalpha(i_input[i]) ||                        // after word is not letter
        type == TokenType::SYMBOL ||                                                   // it was symbol
        type == TokenType::SPACE)                                                      // it was space
    {
      if (type != TokenType::SPACE && type != TokenType::NONE)
        ret.emplace_back(i_input.substr(prevToken, i - prevToken), type);
      prevToken = i;
      type = TokenType::NONE;
    }
    // if token starts
    if (type == TokenType::NONE)
    {
      if (std::isdigit(i_input[i]))
        type = TokenType::NUMBER;
      else if (i_input[i] == '.')
        type = TokenType::FLOAT_NUMBER;
      else if (std::isalpha(i_input[i]))
        type = TokenType::WORD;
      else if (std::isspace(i_input[i]))
        type = TokenType::SPACE;
      else
        type = TokenType::SYMBOL;
    }
    // else token continues
    else
    {
      if (i_input[i] == '.' && type == TokenType::NUMBER)
        type = TokenType::FLOAT_NUMBER;
    }
  }
  // save last token
  if (type != TokenType::SPACE && type != TokenType::NONE)
    ret.emplace_back(i_input.substr(prevToken, i_input.size() - prevToken), type);
  return ret;
}
