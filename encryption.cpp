//
// Created by Miroslava on 23.12.2022.
//

#include "header.hpp"

void encryption(const std::string &file_name, unsigned int key) {
    std::string str;
    std::cout << "Enter str:";
    std::cin >> str;
    unsigned char b1, b2;
    unsigned int block, xorblock, shiftblock, gamma;
    srand(key);
    std::ofstream out;
    out.open(file_name, std::ios::binary);
    for (size_t i = 0; i < str.size(); i += 2) {
        gamma = rand();
        b1 = str[i];
        b2 = i + 1 < str.size() ? str[i+1] : 0u;
        block = (static_cast<unsigned int>(b1) << 8u | static_cast<unsigned int>(b2));
        xorblock = block ^ gamma;
        shiftblock = ((xorblock << 4u) | (xorblock >> 12u));
        b1 = shiftblock >> 8u;
        b2 = shiftblock;
        out << b1 << b2;
    }
}
