#include "Lexer.h"

#include <cctype>
#include <iostream>

enum class State
{
  NUMBER,
  FLOAT_NUMBER,
  WORD,
  SYMBOL,
  SPACE,
  NONE
};

Token createToken(const std::string &i_value, State i_state)
{
  TokenType type = TokenType::NUMBER;
  if (i_state == State::WORD)
    type = TokenType::WORD;
  if (i_state == State::SYMBOL)
    type = TokenType::SYMBOL;
  return {i_value, type};
}

std::vector<Token> Lexer::tokenize(const std::string &i_input)
{
  std::vector<Token> ret;
  int prevToken = 0;
  State state = State::NONE;
  for (int i = 0; i < i_input.size(); ++i)
  {
    // check if token ends
    if (state == State::NUMBER && !std::isdigit(i_input[i]) && i_input[i] != '.' || // after number is not point and not number
        state == State::FLOAT_NUMBER && !std::isdigit(i_input[i]) ||                // after float number is not number
        state == State::WORD && !std::isalpha(i_input[i]) ||                        // after word is not letter
        state == State::SYMBOL ||                                                   // it was symbol
        state == State::SPACE)                                                      // it was space
    {
      if (state != State::SPACE && state != State::NONE)
        ret.emplace_back(createToken(i_input.substr(prevToken, i - prevToken), state));
      prevToken = i;
      state = State::NONE;
    }
    // if token starts
    if (state == State::NONE)
    {
      if (std::isdigit(i_input[i]))
        state = State::NUMBER;
      else if (i_input[i] == '.')
        state = State::FLOAT_NUMBER;
      else if (std::isalpha(i_input[i]))
        state = State::WORD;
      else if (std::isspace(i_input[i]))
        state = State::SPACE;
      else
        state = State::SYMBOL;
    }
    // else token continues
    else
    {
      if (i_input[i] == '.' && state == State::NUMBER)
      {
        state = State::FLOAT_NUMBER;
      }
    }
  }
  // save last token
  if (state != State::SPACE && state != State::NONE)
    ret.emplace_back(createToken(i_input.substr(prevToken, i_input.size() - prevToken), state));
  return ret;
}
