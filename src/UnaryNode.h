#pragma once

#include "Node.h"

#include <cassert>

class UnaryPlusNode : public ArityNode<1>
{
public:
  UnaryPlusNode(const std::vector<std::shared_ptr<Node>> &i_nodes) : ArityNode<1>(i_nodes){};
};

class UnaryMinusNode : public ArityNode<1>
{
public:
  UnaryMinusNode(const std::vector<std::shared_ptr<Node>> &i_nodes) : ArityNode<1>(i_nodes){};
};

class SinNode : public ArityNode<1>
{
public:
  SinNode(const std::vector<std::shared_ptr<Node>> &i_nodes) : ArityNode<1>(i_nodes){};
};

class CosNode : public ArityNode<1>
{
public:
  CosNode(const std::vector<std::shared_ptr<Node>> &i_nodes) : ArityNode<1>(i_nodes){};
};
