#include "Parser.h"

#include "Exception.h"
#include "BinaryNode.h"
#include "NullaryNode.h"
#include "UnaryNodeFactory.h"
#include "UnaryNode.h"

#include <cassert>

Parser::Parser()
{
  m_expectedTokens = {"(", "integer", "float"};
  auto unaryFucntionNames = UnaryNodeFactory::getNames();
  std::copy(unaryFucntionNames.begin(), unaryFucntionNames.end(), std::back_inserter(m_expectedTokens));
}

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
  auto term = parseTerm();
  if (auto tail = parseExpressionTail(term))
    return tail;
  return term;
}

std::shared_ptr<Node> Parser::parseExpressionTail(std::shared_ptr<Node> i_term)
{
  if (m_tokens.empty() || m_tokens.front().type != TokenType::PLUS &&
                              m_tokens.front().type != TokenType::MINUS)
    return {};

  auto tokenType = m_tokens.front().type;
  m_tokens.pop_front();
  auto term = parseTerm();

  std::shared_ptr<Node> expression;
  if (tokenType == TokenType::PLUS)
    expression = std::make_shared<AdditionNode>(std::vector{i_term, term});
  else if (tokenType == TokenType::MINUS)
    expression = std::make_shared<SubstractionNode>(std::vector{i_term, term});
  assert(expression);

  if (auto tail = parseExpressionTail(expression))
    return tail;
  return expression;
}

std::shared_ptr<Node> Parser::parseTerm()
{
  auto factor = parseFactor();
  if (auto tail = parseTermTail(factor))
    return tail;
  return factor;
}

std::shared_ptr<Node> Parser::parseTermTail(std::shared_ptr<Node> i_factor)
{
  if (m_tokens.empty() || m_tokens.front().type != TokenType::MULTIPLY &&
                              m_tokens.front().type != TokenType::DIVIDE)
    return {};

  auto tokenType = m_tokens.front().type;
  m_tokens.pop_front();
  auto factor = parseFactor();

  std::shared_ptr<Node> term;
  if (tokenType == TokenType::MULTIPLY)
    term = std::make_shared<MultiplicationNode>(std::vector{i_factor, factor});
  else if (tokenType == TokenType::DIVIDE)
    term = std::make_shared<DivisionNode>(std::vector{i_factor, factor});
  assert(term);

  if (auto tail = parseTermTail(term))
    return tail;
  return term;
}

std::shared_ptr<Node> Parser::parseFactor()
{
  if (m_tokens.empty())
    throw UnexpectedTokenException("", m_expectedTokens);

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

  throw UnexpectedTokenException(m_tokens.front().value, m_expectedTokens);
}
