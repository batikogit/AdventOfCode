
/**
* Advent of Code 2025 - Day 3 Part 2
 * problem: biggest joltage
 * logic: looping through lines to get the highest two ints by order
 * new task: now get the highest 12 in order
*/


#include <iostream>
#include <fstream>
#include <string>

unsigned  long solve(const std::string& line) {
 if (line.length() <= 12) return std::stoll(line);

 std::string result = "";
 int toremove = line.length() - 12;

 for (char c : line) {
  int digit = c - '0';
  while (toremove > 0 && !result.empty() && (result.back() - '0') < digit) {
   result.pop_back();
   toremove--;
  }
  result.push_back(c);
 }
 result = result.substr(0, 12);

 return std::stoull(result);
}

int main(int argc, char* argv[]) {

 if (argc < 2) {
  std::cerr << "Usage: " << argv[0] << " <input_file>\n";
  return 1;
 }
 std::ifstream file(argv[1]);
 if (!file.is_open()) {
  std::cerr << "Error: Could not open the file!\n";
  return 1;
 }

 std::string line;

 unsigned long long totalsum = 0;
 while (std::getline(file, line)) {
  totalsum += solve(line);
 }

 std::cout << "Total output jolts: " << totalsum << std::endl;
 return 0;
}