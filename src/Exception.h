#pragma once

#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

class UnexpectedTokenException : public std::runtime_error
{
  std::string m_token;
  std::vector<std::string> m_expectedToken;
  std::string m_error;

public:
  UnexpectedTokenException(const std::string &i_token, const std::vector<std::string> &i_expectedToken)
      : std::runtime_error(""), m_token(i_token), m_expectedToken(i_expectedToken)
  {
    std::ostringstream error;
    if (m_expectedToken.empty())
      error << "No token expected, but ";
    else
    {
      error << "Token from list [";
      for (int i = 0; i < m_expectedToken.size(); ++i)
      {
        if (i == 0)
          error << m_expectedToken[0];
        else
          error << ", " << m_expectedToken[i];
      }
      error << "] is expected, but ";
    }
    if (m_token.empty())
      error << "is was not found.";
    else
      error << m_token << " is found.";
    m_error = error.str();
  };

  const char *what() const noexcept
  {
    return m_error.c_str();
  }
};
