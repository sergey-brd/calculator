#include "BinaryNode.h"

Value AdditionNode::eval() const
{
  auto params = evalNodes();
  if (params[0].isInteger() && params[1].isInteger())
    return params[0].get<int>() + params[1].get<int>();
  return params[0].get<double>() + params[1].get<double>();
}

Value SubstractionNode::eval() const
{
  auto params = evalNodes();
  if (params[0].isInteger() && params[1].isInteger())
    return params[0].get<int>() - params[1].get<int>();
  return params[0].get<double>() - params[1].get<double>();
}

Value MultiplicationNode::eval() const
{
  auto params = evalNodes();
  if (params[0].isInteger() && params[1].isInteger())
    return params[0].get<int>() * params[1].get<int>();
  return params[0].get<double>() * params[1].get<double>();
}

Value DivisionNode::eval() const
{
  auto params = evalNodes();
  if (params[0].isInteger() && params[1].isInteger())
  {
    if (params[1].get<int>() == 0)
      throw std::runtime_error("Devision by zero.");
    return params[0].get<int>() / params[1].get<int>();
  }
  return params[0].get<double>() / params[1].get<double>();
}
