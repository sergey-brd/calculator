#include "Interpreter.h"

#include "Lexer.h"
#include "Parser.h"

#include <cmath>
#include <gtest/gtest.h>

TEST(InterpreterTests, Eval)
{
  Parser parser;
  Interpreter interpreter;
  auto lexemes = Lexer::tokenize("0.25 * (-5 + sin(1.57))");
  auto node = parser.parse(lexemes);
  auto result = interpreter.eval(node);
  EXPECT_FALSE(result.isInteger());
  EXPECT_NEAR(result.get<double>(), 0.25 * (-5 + std::sin(1.57)), 0.001);
}
