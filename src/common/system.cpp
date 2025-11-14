#include "system.h"

#include <unistd.h>

#include <cstddef>
#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

#include "linux_parser.h"
#include "process.h"
#include "processor.h"
using namespace LinuxParser;

using std::set;
using std::size_t;
using std::string;
using std::vector;
/*You need to complete the mentioned TODOs in order to satisfy the rubric
criteria "The student will be able to extract and display basic data about the
system."

You need to properly format the uptime. Refer to the comments mentioned in
format. cpp for formatting the uptime.*/
Process::Process(int process_id) {
  this->process_id = process_id;
};

// TODO: Return the system's CPU
Processor& System::Cpu() { return cpu_; }

// TODO: Return a container composed of the system's processes
vector<Process>& System::Processes() {
  vector<Process> result;
  vector<int> pids = LinuxParser::Pids();
  for (int i : pids) {
    Process process( i);
    std::cout << process.Pid() << std::endl;
    result.push_back(process);
  }



  return result;
}

std::string System::Kernel() { return LinuxParser::Kernel(); }

float System::MemoryUtilization() {
  std::ifstream filestream(kProcDirectory + kMeminfoFilename);
  if (filestream.is_open()) {
    string line, name, val;
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
    double memutil;
    memutil = free / total;
    return memutil;
  }

  return -1.0f;
}

// Return the operating system name
std::string System::OperatingSystem() { return LinuxParser::OperatingSystem(); }

int System::TotalProcesses() {
  std::ifstream stream(kProcDirectory + kStatFilename);
  if (stream.is_open()) {
    std::string line;
    string name;
    int number;
    while (std::getline(stream, line)) {
      std::istringstream linestream(line);
      linestream >> name;

      if (name == "processes") {
        linestream >> number;
        return number;
      }
    }
  } else {
    return -1;
  }
  return -1;
}

int System::RunningProcesses() {
  std::ifstream stream(kProcDirectory + kStatFilename);
  if (stream.is_open()) {
    std::string line;
    string name;
    int number;
    while (std::getline(stream, line)) {
      std::istringstream linestream(line);
      linestream >> name;

      if (name == "procs_running") {
        linestream >> number;
        return number;
      }
    }
  } else {
    return -1;
  }
  return -1;
}

long System::UpTime() {
  std::ifstream stream(kProcDirectory + kUptimeFilename);
  string line, val1, val2;
  long uptime = -1;
  if ((stream.is_open())) {

    while (std::getline(stream, line)) {
      std::istringstream linestream(line);
      linestream >> val1;
      uptime = std::stoi(val1);
      return uptime;
    }
  }
  return uptime;
}
