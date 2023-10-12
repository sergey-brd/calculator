#include "Token.h"

#include <gtest/gtest.h>

TEST(Token, FloatToNumber)
{
  Token token("4.5", TokenType::FLOAT_NUMBER);
  EXPECT_EQ(token.value, "4.5");
  EXPECT_EQ(token.type, TokenType::NUMBER);
}

TEST(Token, SymbolToOpeningBracket)
{
  Token token("(", TokenType::SYMBOL);
  EXPECT_EQ(token.value, "(");
  EXPECT_EQ(token.type, TokenType::OPENING_BRACKET);
}

TEST(Token, SymbolToClosingBracket)
{
  Token token(")", TokenType::SYMBOL);
  EXPECT_EQ(token.value, ")");
  EXPECT_EQ(token.type, TokenType::CLOSING_BRACKET);
}

TEST(Token, SymbolToOperator)
{
  Token token("+", TokenType::SYMBOL);
  EXPECT_EQ(token.value, "+");
  EXPECT_EQ(token.type, TokenType::OPERATOR);
}
