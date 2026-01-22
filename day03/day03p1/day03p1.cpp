
/**
* Advent of Code 2025 - Day 3 Part 1
 * problem: biggest joltage
 * logic: looping through lines to get the highest two ints by order
*/

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]) {

 if (argc < 2) {
  std::cerr << "usage: " << argv[0] << " <input_file>\n";
  return 1;
 }

 std::ifstream file(argv[1]);
 if (!file.is_open()) {
  std::cerr << "Error: Could not open the file!\n";
  return 1;
 }

 std::string line;
 long long sum = 0;

 while (std::getline(file, line)) {
  int linejolts = 0;

  for (int i = 0; i < line.size(); i++) {
   if (std::isdigit(line[i])) {
    for (int j = i + 1; j < line.size(); j++) {
     if (std::isdigit(line[j])) {
      int currentval = (line[i] - '0') * 10 + (line[j] - '0');
      if (currentval > linejolts) {
       linejolts = currentval;
      }
     }
    }
   }
  }
  sum += linejolts;
 }

 std::cout << "total output jolts: " << sum << std::endl;
 return 0;
}