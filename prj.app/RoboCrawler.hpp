#pragma once

#include "Commands.hpp"

#include <iostream>
#include <queue>
#include <utility>
#include <string>

class RoboCrawler
{
public:
  RoboCrawler() = default;
  ~RoboCrawler() = default;

  void AddCommand(const std::string& input);
  void PrintPosition() noexcept;

  std::pair<double, double>& GetPosition() noexcept { return m_Position; }

private:
  void ParseAndPush(const std::string& input);

private:
  std::queue<Command> m_Commands;
  std::pair<double, double> m_Position;
};