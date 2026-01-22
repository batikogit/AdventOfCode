/**
* Advent of Code 2025 - Day 2 Part 2
 * problem: mirrored numbers code
 * logic: parse ranges and sum values whose digits mirror symmetrically
 * new task: more invalid IDs
 */

#include <iostream>
#include <sstream>
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

                for (long long i = firstnum; i <= lastnum; ++i) {
                    std::string p = std::to_string(i);
                    size_t len = p.length();
                    bool found = false;

                    for (size_t L = 1; L <= len / 2; ++L) {
                        if (len % L == 0) {
                            std::string pattern = p.substr(0, L);
                            bool match = true;
                            for (size_t start = L; start <= len - L; start += L) {
                                if (p.substr(start, L) != pattern) {
                                    match = false;
                                    break;
                                }
                            }
                            if (match) {
                                found = true;
                                break;
                            }
                        }
                    }
                    if (found) {
                        sum += i;
                    }
                }
            }
        }
    }
    std::cout << sum << std::endl;
    file.close();
    return 0;
}