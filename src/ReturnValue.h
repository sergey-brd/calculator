#pragma once

#include <cassert>

class ReturnValue
{
private:
  int m_integerValue;
  double m_floatValue;
  bool m_isInteger;

public:
  ReturnValue(int i_value) : m_integerValue(i_value), m_isInteger(true){};
  ReturnValue(double i_value) : m_floatValue(i_value), m_isInteger(false){};

  bool isInteger() { return m_isInteger; }

  template <typename T>
  T get() { assert(false); };

  template <>
  inline int get()
  {
    assert(m_isInteger);
    return m_integerValue;
  }

  template <>
  inline double get()
  {
    if (m_isInteger)
      return static_cast<double>(m_integerValue);
    return m_floatValue;
  }
};
