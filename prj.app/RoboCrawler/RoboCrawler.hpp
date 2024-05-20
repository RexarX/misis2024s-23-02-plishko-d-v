#pragma once

#include "Commands.hpp"

#include <iostream>
#include <fstream>
#include <deque>
#include <string>
#include <memory>

class RoboCrawler
{
public:
  RoboCrawler() = default;
  RoboCrawler(const std::string& inputPath, const std::string& outputPath);
  ~RoboCrawler();
  
  void Run();
  void AddCommand();

  void ReadLineFromFile() noexcept;
  void WriteToFile(const double x = 0, const double y = 0) noexcept;

  std::pair<double, double>& GetPosition() noexcept { return m_Position; }

  bool IsStop() noexcept { return m_Stop; }

private:
  void PrintError(std::string_view error) noexcept;

private:
  std::deque<std::unique_ptr<ICommand>> m_Commands;
  std::pair<double, double> m_Position = { 0.0, 0.0 };

  std::ifstream m_Input;
  std::ofstream m_Output;

  std::string m_InputString;

  bool m_Stop = false;
};