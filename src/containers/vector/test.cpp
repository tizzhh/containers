#include <iostream>
#include <math.h>
// using size_type = size_t;
// constexpr size_type CapacityCalc(size_type amount_of_elements){
//         return 1 << ((size_type)log2(amount_of_elements) + 1);
// }
#include <vector>
#include "vector.hpp"
const
 int f() {
  return 7;
}
using namespace s21;
int main() {
  // std::vector<int>a(8);
  // int b;
  // std::cin >> b;
  // int a = f(); // constant expression
  // std::cout << a;
  // for(auto n : a) std::cout << n;
  // std::cout << std::endl;
  // std::cout << a.capacity() << " " << a.size() << '\n';
  // a.push_back(1);
  // std::cout << a.capacity() << " " << a.size() << '\n';
  // int* a = new int[8]();
  // for(int i=0;i != 8;++i) std::cout << *(a++);
  // vector<int>a {1, 2, 3, 4};
  // std::cout << a.capacity() << " " << a.size() << '\n';
  // a.reserve(6);
  // vector<int> b (a);

  // std::cout << b.capacity() << " " << b.size() << '\n';
  std::vector<int> a1 {1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::vector<int> a(std::move(a1));
  for(auto num : a) std::cout << num << " ";
  std::cout << '\n';
  std::cout << a.capacity() << " " << a.size() << '\n';
  for(auto num : a1) std::cout << num << " ";
  std::cout << a1.capacity() << " " << a1.size() << '\n';
  vector<int> b1 {1, 2, 3, 4, 5, 6, 7, 8, 9};
  vector<int> b(std::move(b1));
  for(int i=0;i != b.size();++i)  std::cout << b[i] << " ";
  std::cout << '\n';
  std::cout << b.capacity() << " " << b.size() << '\n';
  for(int i=0;i != b1.size();++i)  std::cout << b1[i] << " ";
  std::cout << b1.capacity() << " " << b1.size() << '\n';
}