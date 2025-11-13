#include <string>

#include "format.h"

using std::string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds[[maybe_unused]]) { 
  int hours = seconds/3600;
  int minutes = seconds%3600/60;
  int seconds_ = (seconds%3600)%60;

  string result = EnsureStringLength(hours)+":"+EnsureStringLength(minutes)+":"+EnsureStringLength(seconds_);

  return result; 



}
string Format::EnsureStringLength(int number){
  string str = std::to_string(number);
  if (str.size()==1) {
    return "0"+str;
  }else
    return str;
  }
