/**
* Advent of Code 2025 - Day 2 Part 1
 * problem: mirrored numbers code
 * logic: parse ranges and sum values whose digits mirror symmetrically
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

    long long sum = 0;
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string id_str;

        while (std::getline(iss, id_str, ',')) {
            auto pos = id_str.find('-');
            if (pos != std::string::npos) {
                std::string start_str = id_str.substr(0, pos);
                std::string end_str = id_str.substr(pos + 1);

                long long firstnum = std::stoll(start_str);
                long long lastnum = std::stoll(end_str);

                for (long long i = firstnum; i <= lastnum; ++i) { //input size is small
                    std::string p = std::to_string(i);
                    size_t len = p.length();
                    if (len % 2 == 0) {

                        std::string p1 = p.substr(0, len / 2);
                        std::string p2 = p.substr(len / 2);

                        if (p1 == p2) {
                            sum += i;
                        }
                    }
                }
            }
        }
    }
    std::cout << sum << std::endl;
    file.close();
    return 0;
}