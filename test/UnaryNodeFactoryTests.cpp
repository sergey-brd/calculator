#include "UnaryNodeFactory.h"

#include "NullaryNode.h"
#include "UnaryNode.h"

#include <gtest/gtest.h>

TEST(UnaryNodeFactoryTests, UnaryPlusInteger)
{
  std::string name = "+";
  EXPECT_TRUE(UnaryNodeFactory::isUnaryOperator(name));
  auto node1 = std::make_shared<IntegerNode>("1");
  auto node = dynamic_cast<UnaryPlusNode *>(UnaryNodeFactory::create(name, node1).get());
  EXPECT_TRUE(node);
}

TEST(UnaryNodeFactoryTests, UnaryPlusFloat)
{
  std::string name = "+";
  EXPECT_TRUE(UnaryNodeFactory::isUnaryOperator(name));
  auto node1 = std::make_shared<IntegerNode>("1");
  auto node = dynamic_cast<UnaryPlusNode *>(UnaryNodeFactory::create(name, node1).get());
  EXPECT_TRUE(node);
}

TEST(UnaryNodeFactoryTests, UnaryMinus)
{
  std::string name = "-";
  EXPECT_TRUE(UnaryNodeFactory::isUnaryOperator(name));
  auto node1 = std::make_shared<IntegerNode>("1");
  auto node = dynamic_cast<UnaryMinusNode *>(UnaryNodeFactory::create(name, node1).get());
  EXPECT_TRUE(node);
}

TEST(UnaryNodeFactoryTests, Sin)
{
  std::string name = "sin";
  EXPECT_TRUE(UnaryNodeFactory::isUnaryOperator(name));
  auto node1 = std::make_shared<IntegerNode>("1");
  auto node = dynamic_cast<SinNode *>(UnaryNodeFactory::create(name, node1).get());
  EXPECT_TRUE(node);
}

TEST(UnaryNodeFactoryTests, Cos)
{
  std::string name = "cos";
  EXPECT_TRUE(UnaryNodeFactory::isUnaryOperator(name));
  auto node1 = std::make_shared<IntegerNode>("1");
  auto node = dynamic_cast<CosNode *>(UnaryNodeFactory::create(name, node1).get());
  EXPECT_TRUE(node);
}

TEST(UnaryNodeFactoryTests, GetNames)
{
  auto ret = UnaryNodeFactory::getNames();
  auto names = std::vector<std::string>{"+", "-", "sin", "cos"};
  EXPECT_EQ(ret.size(), names.size());
  for (int i = 0; i < ret.size(); ++i)
    EXPECT_EQ(ret[i], names[i]);
}
