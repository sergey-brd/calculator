#include "Value.h"

#include <gtest/gtest.h>

TEST(ValueTests, Integer)
{
  Value valueInt(3);
  EXPECT_TRUE(valueInt.isInteger());
  EXPECT_EQ(valueInt.get<int>(), 3);
  EXPECT_NEAR(valueInt.get<double>(), 3, 0.001);
}

TEST(ValueTests, Float)
{
  Value valueFloat(3.14);
  EXPECT_FALSE(valueFloat.isInteger());
  EXPECT_NEAR(valueFloat.get<double>(), 3.14, 0.001);
}

TEST(ValueTests, UnknownImplementationException)
{
  Value valueInt(3);
  EXPECT_THROW(valueInt.get<float>(), UnknownImplementationException);
}

TEST(ValueTests, WrongValueTypeException)
{
  Value valueFloat(3.14);
  EXPECT_THROW(valueFloat.get<int>(), WrongValueTypeException);
}
