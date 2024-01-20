#include <iostream>
#include <math.h>
// using size_type = size_t;
// constexpr size_type CapacityCalc(size_type amount_of_elements){
//         return 1 << ((size_type)log2(amount_of_elements) + 1);
// }
#include <vector>
// #include <list>

#include "vector.hpp"
using namespace s21;


int main() {
  // std::vector<int> a {1, 2, 3, 4,5 };
  // std::vector<int> b {1, 2, 3 };
  // a.swap(b);
  // for(int i=0;i != a.size();++i)  std::cout << a[i] << " ";
  // std::cout << '\n';
  // std::cout << a.capacity() << " " << a.size() << '\n';
  // for(int i=0;i != b.size();++i)  std::cout << b[i] << " ";
  // std::cout << '\n';
  // std::cout << b.capacity() << " " << b.size() << '\n';


  // std::cout << '\n';std::cout << '\n';
  
  std::vector<int> a {1, 2, 3, 4,5 };
  a.erase(a.begin() + 2);
  for(int i=0;i != a.size();++i)  std::cout << a[i] << " ";
  std::cout << '\n';
  std::cout << a.capacity() << " " << a.size() << '\n'<< a[3];
  // delete element move other shit to left size-- capacity state iter income
  std::cout << '\n';std::cout << '\n';

  s21::vector<int> a1 {1, 2, 3, 4,5 };
  // s21::vector<int> b1 {1, 2, 3 };
  a1.erase(a1.begin() + 2);
  for(int i=0;i != a1.size();++i)  std::cout << a1[i] << " ";
  std::cout << '\n';
  std::cout << a1.capacity() << " " << a1.size() << '\n';
  // for(int i=0;i != b1.size();++i)  std::cout << b1[i] << " ";
  // std::cout << '\n';
  // std::cout << b1.capacity() << " " << b1.size() << '\n';
  
}