#pragma once

#include "Node.h"

#include <string>
#include <vector>

class Creator
{
public:
  virtual std::string getName() = 0;
  virtual std::shared_ptr<Node> create(std::shared_ptr<Node> i_node) = 0;
};

class UnaryNodeFactory
{
private:
  static std::vector<std::shared_ptr<Creator>> m_creators;

public:
  static std::vector<std::string> getNames();
  static bool isUnaryOperator(const std::string &i_name);
  static std::shared_ptr<Node> create(const std::string &i_name,
                                      const std::shared_ptr<Node> i_node);
};
