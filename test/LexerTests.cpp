#include "Lexer.h"
#include "Token.h"

#include <gtest/gtest.h>

TEST(Lexer, Empty)
{
  auto out = Lexer::tokenize("");
  EXPECT_EQ(out.size(), 0);
}

TEST(Lexer, Number)
{
  auto out = Lexer::tokenize("254.5");
  EXPECT_EQ(out.size(), 1);
  EXPECT_EQ(out.front().value, "254.5");
  EXPECT_EQ(out.front().type, TokenType::NUMBER);
}

TEST(Lexer, Expression)
{
  auto out = Lexer::tokenize("0.25 * (-5 + sin(1.57))");
  std::list<Token> tokens = {{"0.25", TokenType::NUMBER},
                             {"*", TokenType::MULTIPLY},
                             {"(", TokenType::OPENING_BRACKET},
                             {"-", TokenType::MINUS},
                             {"5", TokenType::NUMBER},
                             {"+", TokenType::PLUS},
                             {"sin", TokenType::WORD},
                             {"(", TokenType::OPENING_BRACKET},
                             {"1.57", TokenType::NUMBER},
                             {")", TokenType::CLOSING_BRACKET},
                             {")", TokenType::CLOSING_BRACKET}};
  EXPECT_EQ(out.size(), tokens.size());
  for (auto itOut = out.begin(), it = tokens.begin(); itOut != out.end(); ++itOut, ++it)
  {
    EXPECT_EQ(itOut->value, it->value);
    EXPECT_EQ(itOut->type, it->type);
  }
}
