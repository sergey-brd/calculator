#include "Node.h"

#include <gtest/gtest.h>

TEST(ArityNode, Create)
{
  auto node1 = std::make_shared<Node>();
  auto node2 = std::make_shared<Node>();
  EXPECT_NO_THROW(
      { ArityNode<2> arityNode({node1, node2}); });
}

TEST(ArityNode, GetChild)
{
  auto node1 = std::make_shared<Node>();
  auto node2 = std::make_shared<Node>();
  ArityNode<2> arityNode({node1, node2});
  EXPECT_EQ(arityNode.getChild(0), node1);
  EXPECT_EQ(arityNode.getChild(1), node2);
}
