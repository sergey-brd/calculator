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
  EXPECT_EQ(out[0].value, "254.5");
  EXPECT_EQ(out[0].type, TokenType::NUMBER);
}

TEST(Lexer, Expression)
{
  auto out = Lexer::tokenize("0.25 * (-5 + sin(1.57))");
  std::vector<Token> tokens = {{"0.25", TokenType::NUMBER},
                               {"*", TokenType::OPERATOR},
                               {"(", TokenType::OPENING_BRACKET},
                               {"-", TokenType::OPERATOR},
                               {"5", TokenType::NUMBER},
                               {"+", TokenType::OPERATOR},
                               {"sin", TokenType::WORD},
                               {"(", TokenType::OPENING_BRACKET},
                               {"1.57", TokenType::NUMBER},
                               {")", TokenType::CLOSING_BRACKET},
                               {")", TokenType::CLOSING_BRACKET}};
  EXPECT_EQ(out.size(), tokens.size());
  for (int i = 0; i < out.size(); ++i)
  {
    EXPECT_EQ(out[i].value, tokens[i].value);
    EXPECT_EQ(out[i].type, tokens[i].type);
  }
}
