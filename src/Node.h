#pragma once

#include "Exception.h"
#include "Value.h"

#include <memory>
#include <vector>

class Node
{
public:
  virtual Value eval() const = 0;
  virtual ~Node() = default;
};

template <int N>
class ArityNode : public Node
{
protected:
  std::vector<std::shared_ptr<Node>> m_nodes;

  std::vector<Value> evalNodes() const
  {
    std::vector<Value> ret;
    for (int i = 0; i < m_nodes.size(); ++i)
      ret.emplace_back(m_nodes[i]->eval());

    return ret;
  }

public:
  ArityNode(const std::vector<std::shared_ptr<Node>> &i_nodes) : m_nodes(i_nodes)
  {
    if (m_nodes.size() != N)
      throw WrongArgumentNumberException(m_nodes.size(), N);
  }
};
