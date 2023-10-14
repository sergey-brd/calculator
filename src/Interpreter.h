#pragma once

#include "Node.h"

#include <memory>

class Interpreter
{
public:
  ReturnValue eval(const std::shared_ptr<Node> i_node) const;
};
