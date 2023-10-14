#include "Parser.h"

#include "NullaryNode.h"

#include <gtest/gtest.h>

TEST(IntegerNode, Create)
{
  EXPECT_NO_THROW(
      { IntegerNode integer("3"); });
}

TEST(IntegerNode, Eval)
{
  IntegerNode number("3");
  auto value = number.eval();
  EXPECT_TRUE(value.isInteger());
  EXPECT_EQ(value.get<int>(), 3);
  EXPECT_NEAR(value.get<double>(), 3, 0.001);
}

TEST(FloatNode, Create)
{
  EXPECT_NO_THROW(
      { FloatNode integer("3.14"); });
}

TEST(FloatNode, Eval)
{
  FloatNode number("3.14");
  auto value = number.eval();
  EXPECT_FALSE(value.isInteger());
  EXPECT_NEAR(value.get<double>(), 3.14, 0.001);
}
