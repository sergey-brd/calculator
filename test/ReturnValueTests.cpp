#include "ReturnValue.h"

#include <gtest/gtest.h>

TEST(RetrunValueTests, Integer)
{
  ReturnValue valueInt(3);
  EXPECT_TRUE(valueInt.isInteger());
  EXPECT_EQ(valueInt.get<int>(), 3);
  EXPECT_NEAR(valueInt.get<double>(), 3, 0.001);
}

TEST(RetrunValueTests, Float)
{
  ReturnValue valueFloat(3.14);
  EXPECT_FALSE(valueFloat.isInteger());
  EXPECT_NEAR(valueFloat.get<double>(), 3.14, 0.001);
}

TEST(RetrunValueTests, UnknownImplementationException)
{
  ReturnValue valueInt(3);
  EXPECT_THROW(valueInt.get<float>(), UnknownImplementationException);
}

TEST(RetrunValueTests, WrongValueTypeException)
{
  ReturnValue valueFloat(3.14);
  EXPECT_THROW(valueFloat.get<int>(), WrongValueTypeException);
}
