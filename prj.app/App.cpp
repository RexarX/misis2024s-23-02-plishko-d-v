#include "RoboCrawler.hpp"

int main()
{
  RoboCrawler crawler;
  std::string input;

  std::cin >> input;
  while (input != "quit") {
    crawler.AddCommand(input);
    crawler.PrintPosition();
    std::cin >> input;
  }

  return 0;
}