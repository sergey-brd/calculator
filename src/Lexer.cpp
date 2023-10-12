#include "Lexer.h"

#include "Token.h"

#include <cctype>
#include <iostream>

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
