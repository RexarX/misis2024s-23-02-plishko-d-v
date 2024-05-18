#include "RoboCrawler.hpp"

int main(int argc, char** argv)
{
  if (argc != 5 || strcmp(argv[1], "-i") || strcmp(argv[3], "-o")) {
    std::cerr << "Usage: " << argv[0] << " -i <input file>" << " -o <output file>" << '\n';
    return 1;
  }

  RoboCrawler crawler(argv[2], argv[4]);

  crawler.Run();

  return 0;
}