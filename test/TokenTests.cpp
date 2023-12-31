#include "Token.h"

#include "Exception.h"

#include <gtest/gtest.h>

TEST(Token, Integer)
{
  Token token("3", TokenType::INTEGER);
  EXPECT_EQ(token.value, "3");
  EXPECT_EQ(token.type, TokenType::INTEGER);
}

TEST(Token, Float)
{
  Token token("3.14", TokenType::FLOAT);
  EXPECT_EQ(token.value, "3.14");
  EXPECT_EQ(token.type, TokenType::FLOAT);
}

TEST(Token, Word)
{
  Token token("sin", TokenType::WORD);
  EXPECT_EQ(token.value, "sin");
  EXPECT_EQ(token.type, TokenType::WORD);
}

TEST(Token, OpeningBracket)
{
  Token token("(", TokenType::SYMBOL);
  EXPECT_EQ(token.type, TokenType::OPENING_BRACKET);
}

TEST(Token, ClosingBracket)
{
  Token token(")", TokenType::SYMBOL);
  EXPECT_EQ(token.type, TokenType::CLOSING_BRACKET);
}

TEST(Token, Plus)
{
  Token token("+", TokenType::SYMBOL);
  EXPECT_EQ(token.type, TokenType::PLUS);
}

TEST(Token, Minus)
{
  Token token("-", TokenType::SYMBOL);
  EXPECT_EQ(token.type, TokenType::MINUS);
}

TEST(Token, Multiply)
{
  Token token("*", TokenType::SYMBOL);
  EXPECT_EQ(token.type, TokenType::MULTIPLY);
}

TEST(Token, Divide)
{
  Token token("/", TokenType::SYMBOL);
  EXPECT_EQ(token.type, TokenType::DIVIDE);
}

TEST(Token, SymbolConvertionException)
{
  EXPECT_THROW({ Token token("!", TokenType::SYMBOL); }, SymbolConvertionException);
}
