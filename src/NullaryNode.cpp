#include "NullaryNode.h"

IntegerNode::IntegerNode(const std::string &i_int) : ArityNode<0>({})
{
  m_int = std::stoi(i_int);
}

Value IntegerNode::eval() const
{
  return m_int;
}

FloatNode::FloatNode(const std::string &i_float) : ArityNode<0>({})
{
  m_float = std::stod(i_float);
}

Value FloatNode::eval() const
{
  return m_float;
}
