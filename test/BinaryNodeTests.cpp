#include "BinaryNode.h"

#include "NullaryNode.h"

#include <gtest/gtest.h>

TEST(BinaryNodeTests, AdditionNodeInteger)
{
  std::vector<std::shared_ptr<Node>> nodes = {std::make_shared<IntegerNode>("1"),
                                              std::make_shared<IntegerNode>("2")};
  auto node = std::make_shared<AdditionNode>(nodes);
  auto value = node->eval();
  EXPECT_TRUE(value.isInteger());
  EXPECT_EQ(value.get<int>(), 1 + 2);
}

TEST(BinaryNodeTests, AdditionNodeFloat)
{
  std::vector<std::shared_ptr<Node>> nodes = {std::make_shared<FloatNode>("1.0"),
                                              std::make_shared<IntegerNode>("2")};
  auto node = std::make_shared<AdditionNode>(nodes);
  auto value = node->eval();
  EXPECT_FALSE(value.isInteger());
  EXPECT_NEAR(value.get<double>(), 1 + 2, 0.001);
}

TEST(BinaryNodeTests, SubstractionNodeInteger)
{
  std::vector<std::shared_ptr<Node>> nodes = {std::make_shared<IntegerNode>("1"),
                                              std::make_shared<IntegerNode>("2")};
  auto node = std::make_shared<SubstractionNode>(nodes);
  auto value = node->eval();
  EXPECT_TRUE(value.isInteger());
  EXPECT_EQ(value.get<int>(), 1 - 2);
}

TEST(BinaryNodeTests, SubstractionNodeFloat)
{
  std::vector<std::shared_ptr<Node>> nodes = {std::make_shared<FloatNode>("1.0"),
                                              std::make_shared<IntegerNode>("2")};
  auto node = std::make_shared<SubstractionNode>(nodes);
  auto value = node->eval();
  EXPECT_FALSE(value.isInteger());
  EXPECT_NEAR(value.get<double>(), 1 - 2, 0.001);
}

TEST(BinaryNodeTests, MultiplicationNodeInteger)
{
  std::vector<std::shared_ptr<Node>> nodes = {std::make_shared<IntegerNode>("1"),
                                              std::make_shared<IntegerNode>("2")};
  auto node = std::make_shared<MultiplicationNode>(nodes);
  auto value = node->eval();
  EXPECT_TRUE(value.isInteger());
  EXPECT_EQ(value.get<int>(), 1 * 2);
}

TEST(BinaryNodeTests, MultiplicationNodeFloat)
{
  std::vector<std::shared_ptr<Node>> nodes = {std::make_shared<FloatNode>("1.0"),
                                              std::make_shared<IntegerNode>("2")};
  auto node = std::make_shared<MultiplicationNode>(nodes);
  auto value = node->eval();
  EXPECT_FALSE(value.isInteger());
  EXPECT_NEAR(value.get<double>(), 1 * 2, 0.001);
}

TEST(BinaryNodeTests, DivisionNodeInteger)
{
  std::vector<std::shared_ptr<Node>> nodes = {std::make_shared<IntegerNode>("1"),
                                              std::make_shared<IntegerNode>("2")};
  auto node = std::make_shared<DivisionNode>(nodes);
  auto value = node->eval();
  EXPECT_TRUE(value.isInteger());
  EXPECT_EQ(value.get<int>(), 1 / 2);
}

TEST(BinaryNodeTests, DivisionNodeFloat)
{
  std::vector<std::shared_ptr<Node>> nodes = {std::make_shared<FloatNode>("1.0"),
                                              std::make_shared<IntegerNode>("2")};
  auto node = std::make_shared<DivisionNode>(nodes);
  auto value = node->eval();
  EXPECT_FALSE(value.isInteger());
  EXPECT_NEAR(value.get<double>(), 1.0 / 2, 0.001);
}
