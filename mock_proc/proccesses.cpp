#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
  std::ifstream filestream("meminfo");

  if (filestream.is_open()) {
    std::string line;
    std::string name, val;
    double total, free;
    while (std::getline(filestream, line)) {
      std::istringstream linestream(line);
      linestream >> name;
      if (name == "MemTotal:") {
        linestream >> val;
        total = std::stoi(val);
      } else if (name == "MemFree:") {
        linestream >> val;
        free = std::stoi(val);
      } else {
        break;
      }
    }
    std::cout << free / total << std::endl;
  }
}
