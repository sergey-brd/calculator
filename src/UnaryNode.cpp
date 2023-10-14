#include "UnaryNode.h"

#include <cmath>

ReturnValue UnaryPlusNode::eval() const
{
  auto params = evalNodes();
  return params.at(0);
}

ReturnValue UnaryMinusNode::eval() const
{
  auto params = evalNodes();
  if (params[0].isInteger())
    return -params[0].get<int>();
  return -params[0].get<double>();
}

ReturnValue SinNode::eval() const
{
  auto params = evalNodes();
  return std::sin(params[0].get<double>());
}

ReturnValue CosNode::eval() const
{
  auto params = evalNodes();
  return std::cos(params[0].get<double>());
}
