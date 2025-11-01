#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>


int main(){
  std::ifstream filestream("meminfo");

  if (filestream.is_open()){
    std::string line;
    while(std::getline(filestream, line)){
      std::istringstream linestream(line);
      std::string a,b,c,d,e,f,g;
      double va = 0.0, vb, vc;
      linestream >> a >> b >> c >> d;
      vb = std::stoi(b);
      
      std::cout << a << b << std::endl;
      
      }
  }
}
