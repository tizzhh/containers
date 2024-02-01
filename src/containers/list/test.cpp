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

int main(void) {
   const std::list<int> lst = {1, 2, 3};
   const s21::list<int> lst1 = {1, 2, 3};
   auto iter = lst.begin();
   auto iter2 = lst1.begin();
//    auto iter2 = s21::ListConstIterator<int>(iter);
}