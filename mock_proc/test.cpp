#include <dirent.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>
using std::string;
using std::vector;

int main() {
  string line;
  std::ifstream filestream("stat");
  if (filestream.is_open()) {
    while (std::getline(filestream, line) && line.substr(0, 4) == "cpu ") {
      vector<long> cpuvalues;
      string name;
      long value;
      std::istringstream linestream(line);

      linestream >> name;

      while (linestream >> value) {
        // user,
        cpuvalues.push_back(value);
      }
      std::cout << "name: " << name << "\n";
      for (long val : cpuvalues) {
        std::cout << "val " << val << "\n";
      }
    }

  } else {
    std::cout << "file not readable" << "\n";
  }
}
