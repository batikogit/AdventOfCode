

#include <iostream>
#include <fstream>
#include <sstream>


int main(int argc, char*argv[]) {
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

    while (std::getline(file, line)) {

    }


    return 0;
}