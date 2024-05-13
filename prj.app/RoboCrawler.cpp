#include "RoboCrawler.hpp"

void RoboCrawler::AddCommand(const std::string& input)
{
}

void RoboCrawler::PrintPosition() noexcept
{
  std::cout << "Current posotion: " << GetPosition().first << ','
                                    << GetPosition().second;
}

void RoboCrawler::ParseAndPush(const std::string& input)
{
  //m_Commands.push();
}
