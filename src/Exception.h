#pragma once

#include <sstream>
#include <stdexcept>

class EmptyTokenException : public std::runtime_error
{
public:
  EmptyTokenException()
      : std::runtime_error("Token from list [(, integer, float, +, -, sin, cos] is expected, but is was not found"){};
};
