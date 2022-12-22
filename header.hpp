//
// Created by Miroslava on 23.12.2022.
//

#ifndef DZ2_HEADER_HPP
#define DZ2_HEADER_HPP

#include "iostream"
#include "fstream"
#include "vector"
#include "string"

void encryption(const std::string &file_name, unsigned int key);
void decryption(const std::string &file_name, unsigned int key);

#endif //DZ2_HEADER_HPP
