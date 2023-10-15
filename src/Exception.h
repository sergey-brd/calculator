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

class UnknownFunctionException : public std::runtime_error
{
  std::string m_function;
  std::vector<std::string> m_expected;
  std::string m_error;

public:
  UnknownFunctionException(const std::string &i_function, const std::vector<std::string> &i_expected)
      : std::runtime_error(""), m_function(i_function), m_expected(i_expected)
  {
    std::ostringstream error;
    error << "Function from list [";
    for (int i = 0; i < m_expected.size(); ++i)
    {
      if (i == 0)
        error << m_expected[0];
      else
        error << ", " << m_expected[i];
    }
    error << "] is expected, but ";
    error << m_function << " is found.";
    m_error = error.str();
  };

  const char *what() const noexcept
  {
    return m_error.c_str();
  }
};

class WrongArgumentNumberException : public std::runtime_error
{
  int m_actual;
  int m_expected;
  std::string m_error;

public:
  WrongArgumentNumberException(int i_actual, int i_expected)
      : std::runtime_error(""), m_actual(i_actual), m_expected(i_expected)
  {
    std::ostringstream error;
    error << "Expected " << m_expected << " argument(s), but " << m_actual << " passed.";
    m_error = error.str();
  };

  const char *what() const noexcept
  {
    return m_error.c_str();
  }
};

class UnknownImplementationException : public std::runtime_error
{
  std::string m_method;
  std::string m_error;

public:
  UnknownImplementationException(const std::string &i_method)
      : std::runtime_error(""), m_method(i_method)
  {
    std::ostringstream error;
    error << "Unknown implementation of " << m_method << " method.";
    m_error = error.str();
  };

  const char *what() const noexcept
  {
    return m_error.c_str();
  }
};

class WrongValueTypeException : public std::runtime_error
{
  std::string m_type;
  std::string m_error;

public:
  WrongValueTypeException(const std::string &i_type)
      : std::runtime_error(""), m_type(i_type)
  {
    std::ostringstream error;
    error << "Cannot get value for " << m_type << " type.";
    m_error = error.str();
  };

  const char *what() const noexcept
  {
    return m_error.c_str();
  }
};

class SymbolConvertionException : public std::runtime_error
{
  std::string m_symbol;
  std::string m_error;

public:
  SymbolConvertionException(const std::string &i_symbol)
      : std::runtime_error(""), m_symbol(i_symbol)
  {
    std::ostringstream error;
    error << "Cannot convert " << m_symbol << " to valid token.";
    m_error = error.str();
  };

  const char *what() const noexcept
  {
    return m_error.c_str();
  }
};
