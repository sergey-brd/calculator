#include "Parser.h"

#include "NullaryNode.h"

#include <gtest/gtest.h>

TEST(IntegerNode, Create)
{
  EXPECT_NO_THROW(
      { IntegerNode integer("3"); });
}

TEST(IntegerNode, GetValue)
{
  IntegerNode number("3");
  EXPECT_EQ(number.getValue(), 3);
}

TEST(FloatNode, Create)
{
  EXPECT_NO_THROW(
      { FloatNode integer("3.14"); });
}

TEST(FloatNode, GetValue)
{
  FloatNode number("3.14");
  EXPECT_NEAR(number.getValue(), 3.14, 0.01);
}
