//
// Created by Miroslava on 23.12.2022.
//

#include "header.hpp"

void decryption(const std::string &file_name, unsigned int key) {
    unsigned char b1, b2;
    unsigned int block, xorblock, shiftblock, gamma;
    srand(key);
    std::ifstream in;
    in.open(file_name, std::ios::binary);
    std::vector<char> result;
    std::string outdata;
    getline(in, outdata);
    in.close();
    for (size_t i = 0; i < outdata.size(); i+=2) {
        gamma = rand();
        b1 = outdata[i];
        b2 = i + 1 < outdata.size() ? outdata[i+1] : 0u;
        block = (static_cast<unsigned int>(b1) << 8u | static_cast<unsigned int>(b2));
        shiftblock = (block >> 4u) | (block << 12u);
        xorblock = shiftblock ^ gamma;
        result.push_back(xorblock >> 8u);
        result.push_back(xorblock);
    }
    for (char symbol: result) std::cout << symbol;
}
