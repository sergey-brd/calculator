#include "Parser.h"

#include "BinaryNode.h"
#include "Lexer.h"
#include "NullaryNode.h"
#include "UnaryNode.h"

#include <gtest/gtest.h>

class ParserTests : public ::testing::Test
{
protected:
  std::shared_ptr<Node> parse(const std::string &i_str)
  {
    auto tokens = Lexer::tokenize(i_str);
    Parser parser;
    return parser.parse(tokens);
  }
};

TEST_F(ParserTests, Addition)
{
  auto node = dynamic_cast<AdditionNode *>(parse("1 + 2").get());
  EXPECT_TRUE(node);
}

TEST_F(ParserTests, Substraction)
{
  auto node = dynamic_cast<SubstractionNode *>(parse("1 - 2").get());
  EXPECT_TRUE(node);
}

TEST_F(ParserTests, Multiplication)
{
  auto node = dynamic_cast<MultiplicationNode *>(parse("1 * 2").get());
  EXPECT_TRUE(node);
}

TEST_F(ParserTests, Division)
{
  auto node = dynamic_cast<DivisionNode *>(parse("1 / 2").get());
  EXPECT_TRUE(node);
}

TEST_F(ParserTests, Brackets)
{
  auto node = dynamic_cast<AdditionNode *>(parse("(1 + 2)").get());
  EXPECT_TRUE(node);
}

TEST_F(ParserTests, UnaryMinus)
{
  auto node = dynamic_cast<UnaryMinusNode *>(parse("-1").get());
  EXPECT_TRUE(node);
}

TEST_F(ParserTests, UnaryPlus)
{
  auto node = dynamic_cast<UnaryMinusNode *>(parse("-1").get());
  EXPECT_TRUE(node);
}

TEST_F(ParserTests, Sin)
{
  auto node = dynamic_cast<SinNode *>(parse("sin(1)").get());
  EXPECT_TRUE(node);
}

TEST_F(ParserTests, Cos)
{
  auto node = dynamic_cast<CosNode *>(parse("cos(1)").get());
  EXPECT_TRUE(node);
}

TEST_F(ParserTests, Integer)
{
  auto node = dynamic_cast<IntegerNode *>(parse("3").get());
  EXPECT_TRUE(node);
}

TEST_F(ParserTests, Float)
{
  auto node = dynamic_cast<FloatNode *>(parse("3.14").get());
  EXPECT_TRUE(node);
}
