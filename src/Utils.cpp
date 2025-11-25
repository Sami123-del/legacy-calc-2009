#include <fstream>
#include <string>
#include <iostream>

long double readDefaultRate() {
    std::ifstream file("config.txt");
    long double rate = 0.0;

    if (file.is_open()) {
        file >> rate;
        if(rate < 0){
            std::cerr << "Warning: Negative interest in config. Using 0.\n";
            rate = 0;
        }
    } else {
        std::cerr << "Warning: config.txt not found. Using 0 interest.\n";
    }

    return rate;
}
