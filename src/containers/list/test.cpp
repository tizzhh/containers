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
    std::list<int> a = {1, 2, 3};
    s21::list<int> b = {1, 2, 3};
    b.insert_many(b.begin(), 10, 11, 12, 13);
    std::cout << b << '\n';
}