#include "UnaryNode.h"

#include <cmath>

Value UnaryPlusNode::eval() const
{
  auto params = evalNodes();
  return params.at(0);
}

Value UnaryMinusNode::eval() const
{
  auto params = evalNodes();
  if (params[0].isInteger())
    return -params[0].get<int>();
  return -params[0].get<double>();
}

Value SinNode::eval() const
{
  auto params = evalNodes();
  return std::sin(params[0].get<double>());
}

Value CosNode::eval() const
{
  auto params = evalNodes();
  return std::cos(params[0].get<double>());
}
