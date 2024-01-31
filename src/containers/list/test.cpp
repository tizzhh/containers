#include <list>
#include <iostream>
#include <string>
#include "list.hpp"

int main(void) {
    std::list<int> lst;
    for (const auto &elem : lst) {
        std::cout << elem << ' ';
    }
    std::cout << '\n';
    // lst.pop_back();
    for (const auto &elem : lst) {
        std::cout << elem << ' ';
    }
    std::cout << '\n';

    s21::list<int> ls;
    for (const auto &elem : ls) {
        std::cout << elem << ' ';
    }
    std::cout << '\n';
    ls.push_back(10);
    ls.pop_back();
    for (const auto &elem : ls) {
        std::cout << elem << ' ';
    }
    std::cout << '\n';
}