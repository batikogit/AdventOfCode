/**
* Advent of Code 2025 - Day 2 Part 1
 * problem:
 * logic:
 */

#include <iostream>
#include <sstream>
#include <fstream>

int main(int argc, char* argv[]){
    if (argc < 2) {
        std::cerr << "usage: " << argv[0] << " <input_file>\n";
        return 1;
    }

    std::ifstream file(argv[1]);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file!\n";
        return 1;
    }



    return 0;
}