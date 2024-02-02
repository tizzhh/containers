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
    std::list<int> a;
    std::list<int> a1({1, 3, 3, 5, 9});
    s21::list<int> b;
    s21::list<int> b1({1, 3, 3, 5, 9});
    a.merge(a1);
    b.merge(b1);
    std::cout << a << '\n';
    std::cout << b << '\n';
}