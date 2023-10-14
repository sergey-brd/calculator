#pragma once

#include "ReturnValue.h"

#include <cassert>
#include <memory>
#include <vector>

class Node
{
public:
  virtual ReturnValue eval() const = 0;
  virtual ~Node() = default;
};

template <int N>
class ArityNode : public Node
{
protected:
  std::vector<std::shared_ptr<Node>> m_nodes;

  std::vector<ReturnValue> evalNodes() const
  {
    std::vector<ReturnValue> ret;
    for (int i = 0; i < m_nodes.size(); ++i)
      ret.emplace_back(m_nodes[i]->eval());

    return ret;
  }

public:
  ArityNode(const std::vector<std::shared_ptr<Node>> &i_nodes) : m_nodes(i_nodes)
  {
    assert(m_nodes.size() == N);
  }
};
