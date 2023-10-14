#include "Interpreter.h"

ReturnValue Interpreter::eval(const std::shared_ptr<Node> i_node) const
{
  return {i_node->eval()};
}
