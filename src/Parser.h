#pragma once

#include "Node.h"
#include "Token.h"

#include <list>
#include <memory>
#include <string>
#include <vector>

// Grammar to parse:
// expression = term | term expression_tail
// expression_tail = <empty> | + term expression_tail | - term expression_tail
// term = factor | factor term_tail
// term_tail = <empty> | * factor term_tail | / factor term_tail
// factor = (expression) | unary_function factor | nullary_function
// unary_function is sin, cos, -, +, etc
// nullary_function is number, const, variable, etc

class Parser
{
  std::list<Token> m_tokens;
  std::shared_ptr<Node> parseExpression();
  std::shared_ptr<Node> parseExpressionTail(std::shared_ptr<Node> i_term);
  std::shared_ptr<Node> parseTerm();
  std::shared_ptr<Node> parseTermTail(std::shared_ptr<Node> i_factor);
  std::shared_ptr<Node> parseFactor();
  std::vector<std::string> m_expectedTokens;

public:
  Parser();
  std::shared_ptr<Node> parse(const std::list<Token> &i_tokens);
};
