#include "UnaryNodeFactory.h"

#include "UnaryNode.h"

class UnaryPlusCreator : public Creator
{
public:
  std::string getName() override { return "+"; };
  std::shared_ptr<Node> create(std::shared_ptr<Node> i_node) override
  {
    return std::make_shared<UnaryPlusNode>(std::vector{i_node});
  };
};

class UnaryMinusCreator : public Creator
{
public:
  std::string getName() override { return "-"; };
  std::shared_ptr<Node> create(std::shared_ptr<Node> i_node) override
  {
    return std::make_shared<UnaryMinusNode>(std::vector{i_node});
  };
};

class SinCreator : public Creator
{
public:
  std::string getName() override { return "sin"; };
  std::shared_ptr<Node> create(std::shared_ptr<Node> i_node) override
  {
    return std::make_shared<SinNode>(std::vector{i_node});
  };
};

class CosCreator : public Creator
{
public:
  std::string getName() override { return "cos"; };
  std::shared_ptr<Node> create(std::shared_ptr<Node> i_node) override
  {
    return std::make_shared<CosNode>(std::vector{i_node});
  };
};

std::vector<std::shared_ptr<Creator>> UnaryNodeFactory::m_creators =
    {std::make_shared<UnaryPlusCreator>(), std::make_shared<UnaryMinusCreator>(),
     std::make_shared<SinCreator>(), std::make_shared<CosCreator>()};

bool UnaryNodeFactory::isUnaryOperator(const std::string &i_name)
{
  for (const auto creator : m_creators)
    if (i_name == creator->getName())
      return true;
  return false;
}

std::shared_ptr<Node> UnaryNodeFactory::create(const std::string &i_name,
                                               std::shared_ptr<Node> i_node)
{
  for (const auto creator : m_creators)
    if (i_name == creator->getName())
      return creator->create(i_node);
  assert(false);
}
