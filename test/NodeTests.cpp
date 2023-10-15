#include "Node.h"

#include "BinaryNode.h"
#include "NullaryNode.h"

#include <gtest/gtest.h>

TEST(ArityNode, Create)
{
  auto node1 = std::make_shared<IntegerNode>("1");
  auto node2 = std::make_shared<IntegerNode>("2");
  EXPECT_NO_THROW(AdditionNode arityNode({node1, node2}));
}

TEST(ArityNode, WrongArgumentNumberException)
{
  auto node1 = std::make_shared<IntegerNode>("1");
  EXPECT_THROW(AdditionNode arityNode({node1}), WrongArgumentNumberException);
}
