#include <list>
#include <iostream>
#include <string>
#include "list.hpp"

std::ostream& operator<<(std::ostream& ostr, const std::list<int>& list)
{
    for (auto& i : list)
        ostr << ' ' << i;
 
    return ostr;
}

std::ostream& operator<<(std::ostream& ostr, const s21::list<int>& list)
{
    for (auto& i : list)
        ostr << ' ' << i;
 
    return ostr;
}

int main(void) {
    s21::list<int> a = {1, 2, 3};
    s21::list<int> a2 = {4, 5, 6};
    s21::list<int> a1(a);
    // a1 = std::move(a2);
    a1 = std::move(a2);
    // std::list<int> a2;
    // s21::list<int> b = {1, 2, 3};
    // b.insert_many(b.begin(), 10, 11, 12, 13);
    std::cout << a1 << '\n';
}