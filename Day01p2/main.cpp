/**
* Advent of Code 2025 - Day 2
 * problem: Dial Calibration Logic
 * logic: Circular buffer (0-99) with R/L wrap-around.
 * new task: count every 0 click
 */


#include <iostream>
#include <fstream>
#include <string>


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
    int pos = 50;
    int zerocount = 0;
    std::string line;
    int old_pos = pos;

    while (getline(file, line)) {

        char direction = line[0];
        std::string temp = line.substr(1);
        int size = std::stoi(temp);

        if (direction == 'R') {
            pos = (pos + size) % 100;
            if (old_pos + size >= 100){
                zerocount++;
            }
        }
        else if (direction == 'L') {
            pos = (pos - (size % 100) + 100) % 100;
            if (pos < 0) pos += 100;
            if (old_pos - size < 0) {
                zerocount++;
            }
            old_pos = pos;
        }


    }
    std::cout << zerocount << std::endl;
    file.close();
    return 0;
}