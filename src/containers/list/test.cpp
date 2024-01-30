#include <list>
#include <iostream>
#include <string>
#include "list.hpp"

int main(void) {
    // std::list<int> l1 = {1, 2, 3};
    // std::list<int> l = std::move(l1);
    // std::cout << l1.front() << l1.back() << l1.size() << '\n';
    // std::cout << l.front() << l.back() << l.size() << '\n';

    s21::list<int> lst1 = {1, 2, 3};
    s21::list<int> lst = std::move(lst1);
    // std::cout << lst1.front() << lst1.back() << lst1.size() << '\n';
    // std::cout << lst.front() << lst.back() << lst.size() << '\n';
}