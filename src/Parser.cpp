#include "Parser.h"

#include "Exception.h"
#include "BinaryNode.h"
#include "NullaryNode.h"
#include "UnaryNodeFactory.h"
#include "UnaryNode.h"

std::shared_ptr<Node> Parser::parse(const std::list<Token> &i_tokens)
{
  m_tokens = i_tokens;
  auto expression = parseExpression();
  if (!m_tokens.empty())
    throw UnexpectedTokenException(m_tokens.front().value, {});
  return expression;
}

std::shared_ptr<Node> Parser::parseExpression()
{
  auto term1 = parseTerm();
  if (!m_tokens.empty())
  {
    if (m_tokens.front().type == TokenType::PLUS)
    {
      m_tokens.pop_front();
      auto term2 = parseTerm();
      return std::make_shared<AdditionNode>(std::vector{term1, term2});
    }
    else if (m_tokens.front().type == TokenType::MINUS)
    {
      m_tokens.pop_front();
      auto term2 = parseTerm();
      return std::make_shared<SubstractionNode>(std::vector{term1, term2});
    }
  }
  return term1;
}

std::shared_ptr<Node> Parser::parseTerm()
{
  auto factor1 = parseFactor();
  if (!m_tokens.empty())
  {
    if (m_tokens.front().type == TokenType::MULTIPLY)
    {
      m_tokens.pop_front();
      auto factor2 = parseFactor();
      return std::make_shared<MultiplicationNode>(std::vector{factor1, factor2});
    }
    else if (m_tokens.front().type == TokenType::DIVIDE)
    {
      m_tokens.pop_front();
      auto factor2 = parseFactor();
      return std::make_shared<DivisionNode>(std::vector{factor1, factor2});
    }
  }
  return factor1;
}

std::shared_ptr<Node> Parser::parseFactor()
{
  auto expectedTokens = std::vector<std::string>{"(", "integer", "float"};
  auto unaryFucntionNames = UnaryNodeFactory::getNames();
  std::copy(unaryFucntionNames.begin(), unaryFucntionNames.end(), std::back_inserter(expectedTokens));

  if (m_tokens.empty())
    throw UnexpectedTokenException("", expectedTokens);

  if (m_tokens.front().type == TokenType::OPENING_BRACKET)
  {
    m_tokens.pop_front();
    auto expression = parseExpression();
    if (!m_tokens.empty() && m_tokens.front().type == TokenType::CLOSING_BRACKET)
      m_tokens.pop_front();
    else
      throw UnexpectedTokenException(!m_tokens.empty() ? m_tokens.front().value : "", {")"});
    return expression;
  }
  else if (m_tokens.front().type == TokenType::INTEGER)
  {
    auto integer = std::make_shared<IntegerNode>(m_tokens.front().value);
    m_tokens.pop_front();
    return integer;
  }
  else if (m_tokens.front().type == TokenType::FLOAT)
  {
    auto float_number = std::make_shared<FloatNode>(m_tokens.front().value);
    m_tokens.pop_front();
    return float_number;
  }
  else if (UnaryNodeFactory::isUnaryOperator(m_tokens.front().value))
  {
    auto token = m_tokens.front().value;
    m_tokens.pop_front();
    auto factor = parseFactor();
    return UnaryNodeFactory::create(token, factor);
  }

  throw UnexpectedTokenException(m_tokens.front().value, expectedTokens);
}
