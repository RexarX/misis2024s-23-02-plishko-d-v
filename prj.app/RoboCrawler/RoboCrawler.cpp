#include "RoboCrawler.hpp"

#include <stdexcept>

RoboCrawler::RoboCrawler(const std::string& inputPath, const std::string& outputPath)
  : m_Input(inputPath), m_Output(outputPath)
{
  if (!m_Input.is_open()) { PrintError("Error opening the input file!"); }
  else if (!m_Output.is_open()) { PrintError("Error opening the output file!"); }
}

RoboCrawler::~RoboCrawler()
{
  m_Input.close();
  m_Output.close();
}

void RoboCrawler::Run()
{
  while (!IsStop()) {
    ReadLineFromFile();
  }
}

void RoboCrawler::AddCommand()
{
  std::string command, argument;
  double lhs_value(0.0), rhs_value(0.0);

  size_t pos = m_InputString.find(' ');
  if (pos != std::string::npos) {
    command = m_InputString.substr(0, pos);

    argument = m_InputString.substr(pos + 1);

    if (argument == "" || argument == " ") {
      PrintError("Argument is empty!");
      m_Stop = true;
      return;
    }

    lhs_value = std::stod(argument);

    pos = argument.find(' ');
    if (pos != std::string::npos) {
      rhs_value = std::stod(argument.substr(pos + 1));
    }
  } else {
    PrintError("Input is not correct: \"" + m_InputString + "\"!");
    m_Stop = true;
    return;
  }

  if (command == "GO") {
    WriteToFile(m_Position.first + lhs_value, m_Position.second + rhs_value);
  } else if (command == "GW") {
    m_Commands.push_back(std::make_unique<GoWest>(GoWest(lhs_value)));
    m_Commands.back()->Execute(m_Position.first, m_Position.second);
  } else if (command == "GE") {
    m_Commands.push_back(std::make_unique<GoEast>(GoEast(lhs_value)));
    m_Commands.back()->Execute(m_Position.first, m_Position.second);
  } else if (command == "GN") {
    m_Commands.push_back(std::make_unique<GoNorth>(GoNorth(lhs_value)));
    m_Commands.back()->Execute(m_Position.first, m_Position.second);
  } else if (command == "GS") {
    m_Commands.push_back(std::make_unique<GoSouth>(GoSouth(lhs_value)));
    m_Commands.back()->Execute(m_Position.first, m_Position.second);
  } else if (command == "RE") {
    if (lhs_value > m_Commands.size()) {
      PrintError("RE value in bigger than commands pool!\n");
    }
    for (uint32_t i = 0; i < lhs_value; ++i) {
      m_Position.first -= m_Commands.back()->GetDistance().first;
      m_Position.second -= m_Commands.back()->GetDistance().second;
      m_Commands.pop_back();
    }
  } else {
    PrintError("Unknown command: \"" + command + "\"!");
    m_Stop = true;
    return;
  }
}

void RoboCrawler::ReadLineFromFile() noexcept
{
  if (!m_Input.eof() && std::getline(m_Input, m_InputString)) { AddCommand(); }
  else { m_Stop = true; }
}

void RoboCrawler::WriteToFile(const double x, const double y) noexcept
{
  m_Output << x << ' ' << y << '\n';
}

void RoboCrawler::PrintError(std::string_view error) noexcept
{
  std::cerr << error << '\n';
}