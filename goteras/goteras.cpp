#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>

std::string formatTime(const int tot_seconds){
    int secs = tot_seconds % 60;
    int mins = (tot_seconds - secs) % 3600;  // minutes in seconds
    int hours = tot_seconds - secs - mins;   // hours in seconds

    std::stringstream ss;
    ss  << std::setw(2) << std::setfill('0') << hours / 3600 << ":"
        << std::setw(2) << std::setfill('0') << mins / 60 << ":"
        << std::setw(2) << std::setfill('0') << secs;

    return ss.str();
}

void readFile(const std::string& input, const std::string& output) {
    std::ifstream input_file(input);
    std::ofstream output_file(output);
    
    if (!input_file.is_open()) {
        std::cerr << "Could not open input file: " << input << std::endl;
        return;
    }

    if (!output_file.is_open()) {
        std::cerr << "Could not open/create output file: " << output << std::endl;
        return;
    }

    std::string line;
    if (std::getline(input_file, line)){
        int n_cases = std::stoi(line);
    } else {
        return;
    }
    
    while (std::getline(input_file, line)) {
        output_file << formatTime(std::stoi(line)) << std::endl;
    }
    
    input_file.close();
    output_file.close();
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <input_filename> <output_filename>" << std::endl;
        return 1;
    }

    readFile(argv[1], argv[2]);

    return 0;
}
