#pragma once

#include <Node.h>

class AdditionNode : public ArityNode<2>
{
public:
  AdditionNode(const std::vector<std::shared_ptr<Node>> &i_nodes) : ArityNode<2>(i_nodes){};
};

class SubstractionNode : public ArityNode<2>
{
public:
  SubstractionNode(const std::vector<std::shared_ptr<Node>> &i_nodes) : ArityNode<2>(i_nodes){};
};

class MultiplicationNode : public ArityNode<2>
{
public:
  MultiplicationNode(const std::vector<std::shared_ptr<Node>> &i_nodes) : ArityNode<2>(i_nodes){};
};

class DivisionNode : public ArityNode<2>
{
public:
  DivisionNode(const std::vector<std::shared_ptr<Node>> &i_nodes) : ArityNode<2>(i_nodes){};
};
