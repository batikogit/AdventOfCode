/**
* Advent of Code 2025 - Day 1
 * problem: Dial Calibration Logic
 * logic: Circular buffer (0-99) with R/L wrap-around.
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

    int pos = 50;
    int zerocount = 0;
    std::string line;

    while (std::getline(file, line)) {

        const char direction = line[0];
        const int steps = std::stoi(line.substr(1));

        if (direction == 'R') {
            pos = (pos + steps) % 100;
        } else if (direction == 'L') {
            pos = (pos - steps % 100 + 100) % 100;
        }

        if (pos == 0)
            zerocount++;
    }

    std::cout << zerocount << '\n';
    return 0;
}
