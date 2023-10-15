#pragma once

#include "Node.h"

#include <string>

class IntegerNode : public ArityNode<0>
{
private:
  int m_int;

public:
  IntegerNode(const std::string &i_int);
  Value eval() const override;
};

class FloatNode : public ArityNode<0>
{
private:
  double m_float;

public:
  FloatNode(const std::string &i_float);
  Value eval() const override;
};
