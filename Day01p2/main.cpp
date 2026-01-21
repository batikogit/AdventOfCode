/**
* Advent of Code 2025 - Day 1 Part 2
 * problem: Dial Calibration Logic
 * logic: Circular buffer (0-99) with R/L wrap-around.
 * new task: count every 0 click
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
    if (!file) {
        std::cerr << "Error: Could not open the file!\n";
        return 1;
    }

    int pos = 50;
    int zerocount = 0;
    std::string line;

    while (std::getline(file, line)) {
        char direction = line[0];
        int size = std::stoi(line.substr(1));

        for (int i = 0; i < size; ++i) {
            if (direction == 'R') {
                pos = (pos + 1) % 100;
            } else if (direction == 'L'){
                pos = (pos + 99) % 100;
            }
            if (pos == 0)
                zerocount++;
        }
    }

    std::cout << zerocount << '\n';
    return 0;
}
