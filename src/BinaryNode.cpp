#include "BinaryNode.h"

ReturnValue AdditionNode::eval() const
{
  auto params = evalNodes();
  if (params[0].isInteger() && params[1].isInteger())
    return params[0].get<int>() + params[1].get<int>();
  return params[0].get<double>() + params[1].get<double>();
}

ReturnValue SubstractionNode::eval() const
{
  auto params = evalNodes();
  if (params[0].isInteger() && params[1].isInteger())
    return params[0].get<int>() - params[1].get<int>();
  return params[0].get<double>() - params[1].get<double>();
}

ReturnValue MultiplicationNode::eval() const
{
  auto params = evalNodes();
  if (params[0].isInteger() && params[1].isInteger())
    return params[0].get<int>() * params[1].get<int>();
  return params[0].get<double>() * params[1].get<double>();
}

ReturnValue DivisionNode::eval() const
{
  auto params = evalNodes();
  if (params[0].isInteger() && params[1].isInteger())
    return params[0].get<int>() / params[1].get<int>();
  return params[0].get<double>() / params[1].get<double>();
}
