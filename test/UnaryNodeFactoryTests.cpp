#include "UnaryNodeFactory.h"

#include "UnaryNode.h"

#include <gtest/gtest.h>

TEST(UnaryNodeFactoryTests, UnaryPlus)
{
  std::string name = "+";
  EXPECT_TRUE(UnaryNodeFactory::isUnaryOperator(name));
  auto node1 = std::make_shared<Node>();
  auto node = dynamic_cast<UnaryPlusNode *>(UnaryNodeFactory::create(name, node1).get());
  EXPECT_TRUE(node);
}

TEST(UnaryNodeFactoryTests, UnaryMinus)
{
  std::string name = "-";
  EXPECT_TRUE(UnaryNodeFactory::isUnaryOperator(name));
  auto node1 = std::make_shared<Node>();
  auto node = dynamic_cast<UnaryMinusNode *>(UnaryNodeFactory::create(name, node1).get());
  EXPECT_TRUE(node);
}

TEST(UnaryNodeFactoryTests, Sin)
{
  std::string name = "sin";
  EXPECT_TRUE(UnaryNodeFactory::isUnaryOperator(name));
  auto node1 = std::make_shared<Node>();
  auto node = dynamic_cast<SinNode *>(UnaryNodeFactory::create(name, node1).get());
  EXPECT_TRUE(node);
}

TEST(UnaryNodeFactoryTests, Cos)
{
  std::string name = "cos";
  EXPECT_TRUE(UnaryNodeFactory::isUnaryOperator(name));
  auto node1 = std::make_shared<Node>();
  auto node = dynamic_cast<CosNode *>(UnaryNodeFactory::create(name, node1).get());
  EXPECT_TRUE(node);
}
