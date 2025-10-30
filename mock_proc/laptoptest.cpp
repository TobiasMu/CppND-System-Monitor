#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>


int main(){
  std::ifstream filestream("stat");

  if (filestream.is_open()){
    std::string line;
    while(std::getline(filestream, line)){
      std::istringstream linestream(line);
      
      if (linestream.str().substr(0,4)== "cpu ") {
        std::string name;
        double val;
        std::vector<double> values;
        linestream >> name;

        while (linestream >> val) {
          values.push_back(val);
        }
        double& usertime = values[0];
        double& nice = values[1];
        double& system = values[2];
        double& idle = values[3];
        double& iowait = values[4];
        double& irq = values[5];
        double& softirq = values[6];
        double& steal = values[7];
        double& guest = values[8];
        double& guestnice = values[9];
        // calcs

        double a_idle =  idle + iowait;
        // guest and guestnice already in guest and nice
        double nonidle = usertime + nice + system + irq + softirq + steal; 
        
        double percentage = nonidle / (a_idle + nonidle);
 
        std::cout << "percentage "<<  percentage <<"\n"; 
        //
        // for (double v : values) {
        //   std::cout << v << std::endl;
        //
        //
        // }
      }
  }
}
}

