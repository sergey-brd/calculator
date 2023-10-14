#pragma once

#include <cassert>
#include <memory>
#include <vector>

class Node
{
public:
  virtual ~Node() = default;
};

template <int N>
class ArityNode : public Node
{
protected:
  std::vector<std::shared_ptr<Node>> m_nodes;

public:
  ArityNode(const std::vector<std::shared_ptr<Node>> &i_nodes) : m_nodes(i_nodes)
  {
    assert(m_nodes.size() == N);
  }

  std::shared_ptr<Node> getChild(int i_idx) const
  {
    assert(0 <= i_idx && i_idx < N);
    return m_nodes[i_idx];
  }
};
