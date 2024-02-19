#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "list.hpp"
std::ostream& operator<<(std::ostream& ostr, const std::list<int>& list) {
  for (auto& i : list) ostr << ' ' << i;

  return ostr;
}

std::ostream& operator<<(std::ostream& ostr, const s21::list<int>& list) {
  for (auto& i : list) ostr << ' ' << i;

  return ostr;
}

int main(void) {
  s21::list<int> a = {3, 2, 1};
  std::cout << a << '\n';
  // auto iter = a.begin();
  // auto iter2 = a.begin();
  a.sort();
  std::cout << a << '\n';
}