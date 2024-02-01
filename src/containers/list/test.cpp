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
   std::list<int> lst;
   s21::list<int> lst1;
   std::cout << lst << '\n';
   std::cout << lst1 << '\n';
   lst.unique();
   lst1.unique();
   std::cout << lst << '\n';
   std::cout << lst1 << '\n';
}