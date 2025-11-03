#include <unistd.h>

#include <cstddef>
#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <string>
using std::istringstream;

int main() {
  std::ifstream stream("uptime");
  std::string line, val1;
    long int uptime = -1;

  if (stream.is_open()) {
    while (std::getline(stream, line)) {
      istringstream linestream(line);
      linestream >> val1;
      std::cout << val1 << std::endl;

      uptime = std::stoi(val1);
    }
  }
  std::cout << uptime << std::endl;
}
