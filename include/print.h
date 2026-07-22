#pragma once
#include <vector>
#include <string>
#include <iostream>
using namespace std;

template<typename T>
void print(std::vector<T> strs) {
    auto length = strs.size();
    for (int i = 0; i < length - 1; i++) {
        std::cout << strs[i] << ", ";
    }
    std::cout << strs[length - 1] << std::endl;
}

/**
 * 打印数
 */
template<typename T>
void print(T values) {
    std::cout << values << std::endl;
}