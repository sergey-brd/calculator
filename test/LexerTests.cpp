#include "Lexer.h"

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
  EXPECT_EQ(out[0], "254.5");
}

TEST(Lexer, Expression)
{
  auto out = Lexer::tokenize("0.25 * (-5 + sin(1.57))");
  std::vector<std::string> tokens = {"0.25", "*", "(", "-", "5", "+", "sin", "(", "1.57", ")", ")"};
  EXPECT_EQ(out.size(), tokens.size());
  for (int i = 0; i < out.size(); ++i)
    EXPECT_EQ(out[i], tokens[i]);
}
