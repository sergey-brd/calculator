#include "UnaryNode.h"

#include "NullaryNode.h"

#include <cmath>
#include <gtest/gtest.h>

TEST(UnaryNodeTests, UnaryPlusInteger)
{
  std::shared_ptr<Node> node1 = std::make_shared<IntegerNode>("1");
  auto node = std::make_shared<UnaryPlusNode>(std::vector{node1});
  auto value = node->eval();
  EXPECT_TRUE(value.isInteger());
  EXPECT_EQ(value.get<int>(), 1);
}

TEST(UnaryNodeTests, UnaryPlusFloat)
{
  std::shared_ptr<Node> node1 = std::make_shared<FloatNode>("1.0");
  auto node = std::make_shared<UnaryPlusNode>(std::vector{node1});
  auto value = node->eval();
  EXPECT_FALSE(value.isInteger());
  EXPECT_NEAR(value.get<double>(), 1, 0.001);
}

TEST(UnaryNodeTests, UnaryMinusInteger)
{
  std::shared_ptr<Node> node1 = std::make_shared<IntegerNode>("1");
  auto node = std::make_shared<UnaryMinusNode>(std::vector{node1});
  auto value = node->eval();
  EXPECT_TRUE(value.isInteger());
  EXPECT_EQ(value.get<int>(), -1);
}

TEST(UnaryNodeTests, UnaryMinusFloat)
{
  std::shared_ptr<Node> node1 = std::make_shared<FloatNode>("1.0");
  auto node = std::make_shared<UnaryMinusNode>(std::vector{node1});
  auto value = node->eval();
  EXPECT_FALSE(value.isInteger());
  EXPECT_NEAR(value.get<double>(), -1, 0.001);
}

TEST(UnaryNodeTests, Sin)
{
  std::shared_ptr<Node> node1 = std::make_shared<FloatNode>("1.0");
  auto node = std::make_shared<SinNode>(std::vector{node1});
  auto value = node->eval();
  EXPECT_FALSE(value.isInteger());
  EXPECT_NEAR(value.get<double>(), std::sin(1), 0.001);
}

TEST(UnaryNodeTests, Cos)
{
  std::shared_ptr<Node> node1 = std::make_shared<FloatNode>("1.0");
  auto node = std::make_shared<CosNode>(std::vector{node1});
  auto value = node->eval();
  EXPECT_FALSE(value.isInteger());
  EXPECT_NEAR(value.get<double>(), std::cos(1), 0.001);
}
