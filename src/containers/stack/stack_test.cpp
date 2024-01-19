#include "stack.hpp"

#include <iostream>
#include <stack>

int main(void) {
  std::stack<int> aboba({1, 2, 3});
  std::stack<int> aboba2(std::move(aboba));
  std::cout << aboba2.top() << '\n';
  std::cout << aboba.top() << '\n';
}