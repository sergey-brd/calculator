#pragma once

#include "Exception.h"

#include <typeinfo>

class Value
{
private:
  int m_integerValue;
  double m_floatValue;
  bool m_isInteger;

public:
  Value(int i_value) : m_integerValue(i_value), m_isInteger(true){};
  Value(double i_value) : m_floatValue(i_value), m_isInteger(false){};

  bool isInteger() { return m_isInteger; }

  template <typename T>
  T get()
  {
    std::ostringstream type;
    type << "Value::get<" << typeid(T).name() << ">";
    throw UnknownImplementationException(type.str());
  };
};

template <>
inline int Value::get<int>()
{
  if (!m_isInteger)
    throw WrongValueTypeException("int");
  return m_integerValue;
}

template <>
inline double Value::get<double>()
{
  if (m_isInteger)
    return static_cast<double>(m_integerValue);
  return m_floatValue;
}
