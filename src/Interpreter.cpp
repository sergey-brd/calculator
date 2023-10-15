#include "Interpreter.h"

Value Interpreter::eval(const std::shared_ptr<Node> i_node) const
{
  return {i_node->eval()};
}
