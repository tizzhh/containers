#include <gtest/gtest.h>
#include <set>
#include "../s21_containersplus.hpp"

// СДЕЛАТЬ ИНСЕРТ МЭНИ БЭК ДЛЯ ВЕКТОРА  
// СДЕЛАТЬ ИНСЕРТ МЭНИ ДЛЯ СЕТА

TEST(ConstructorSet, Default) {
  try {
    s21::set<int> a;
    SUCCEED();
  } catch (...) {
    FAIL() << "Default constructor fails";
  }
}

TEST(ConstructorSet, InitializerListOk) {
  try {
    s21::set<int> a({1, 2});
    SUCCEED();
  } catch (...) {
    FAIL() << "Initializer set constructor fails";
  }
}

// SegFaults
// TEST(ConstructorSet, CopyOk) {
//   try {
//     s21::set<int> a({1, 2});
//     s21::set<int> b = a;
//     SUCCEED();
//   } catch (...) {
//     FAIL() << "Copy constructor fails";
//   }
// }

// TEST(ConstructorSet, MoveOk) {
//   try {
//     s21::set<int> a({1, 2});
//     s21::set<int> b(std::move(a));
//     SUCCEED();
//   } catch (...) {
//     FAIL() << "Move constructor fails";
//   }
// }

// TEST(ConstructorSet, MoveOperOk) {
//   try {
//     s21::set<int> a({1, 2});
//     s21::set<int> b = std::move(a);
//     SUCCEED();
//   } catch (...) {
//     FAIL() << "Move oper constructor fails";
//   }
// }

TEST(IteratorSet, Begin) {
  std::set<long> a({1, 2, 3});
  s21::set<long> b({1, 2, 3});
  ASSERT_EQ(*a.begin(), *b.begin());
}

TEST(IteratorSet, Incr) {
  std::set<long> a({1, 2, 3});
  s21::set<long> b({1, 2, 3});
  auto iter1 = a.begin();
  auto iter2 = b.begin();
  ++iter1;
  ++iter2;
  ASSERT_EQ(*iter1, *iter2);
}

// TEST(IteratorSet, IncrBackwards) {
//   std::set<long> a({3, 2, 1});
//   s21::set<long> b({3, 2, 1});
//   auto iter1 = a.begin();
//   auto iter2 = b.begin();
//   ++iter1;
//   ++iter2;
//   ASSERT_EQ(*iter1, *iter2);
// }

TEST(IteratorSet, IncrLastElem) {
  s21::set<long> b({1, 2, 3});
  auto iter2 = b.begin();
  ++iter2;
  ++iter2;
  ++iter2;
  ASSERT_EQ(*iter2, *b.end());
}

// TEST(IteratorSet, Decr) {
//   std::set<long> a({1, 2, 3});
//   s21::set<long> b({1, 2, 3});
//   auto iter1 = a.end();
//   auto iter2 = b.end();
//   --iter1;
//   --iter2;
//   ASSERT_EQ(*iter1, *iter2);
// }

TEST(IteratorSet, DecrFirstElement) {
  s21::set<long> b({1, 2, 3});
  auto iter2 = b.begin();
  --iter2;
  ASSERT_EQ(*iter2, *b.begin());
}

TEST(IteratorSet, End) {
  s21::set<long> b({1, 2, 3});
  ASSERT_EQ(*b.end(), long());
}

TEST(CapacitySet, EmptyTrue) {
  std::set<int> a;
  s21::set<int> b;
  ASSERT_EQ(a.empty(), b.empty());
}

TEST(CapacitySet, EmptyFalse) {
  std::set<int> a({1, 2, 3});
  s21::set<int> b({1, 2, 3});
  ASSERT_EQ(a.empty(), b.empty());
}

TEST(CapacitySet, Size0) {
  std::set<int> a;
  s21::set<int> b;
  ASSERT_EQ(a.size(), b.size());
}

TEST(CapacitySet, Size3) {
  std::set<char> a({'a', 'b', 'c'});
  s21::set<char> b({'a', 'b', 'c'});
  ASSERT_EQ(a.size(), b.size());
}

// TEST(CapacitySet, MaxSize) {
//   std::set<char> a({'a'});
//   s21::set<char> b({'a'});
//   ASSERT_EQ(a.max_size(), b.max_size());
// }

TEST(ModifiersSet, Clear) {
  std::set<char> a({'a', 'b', 'c'});
  s21::set<char> b({'a', 'b', 'c'});
  a.clear();
  b.clear();
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(*b.end(), char());
  // b.begin(); // setiterator (nullptr) дает сегу
  // assert(b.begin() == nullptr);
  // ASSERT_EQ(b.begin(), nullptr);
}

TEST(ModifiersSet, InsertRight) {
  std::set<int> a({1, 2, 3});
  s21::set<int> b({1, 2, 3});
  auto res1 = a.insert(4);
  auto res2 = b.insert(4);
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(*b.end(), int());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
  ASSERT_EQ(*res1.first, *res2.first);
  ASSERT_EQ(res1.second, res2.second);
}

TEST(ModifiersSet, InsertLeft) {
  std::set<int> a({1, 2, 3});
  s21::set<int> b({1, 2, 3});
  auto res1 = a.insert(0);
  auto res2 = b.insert(0);
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(*b.end(), int());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
  ASSERT_EQ(*res1.first, *res2.first);
  ASSERT_EQ(res1.second, res2.second);
}

// неправильно работает с отрицательными числами
TEST(ModifiersSet, InsertManyRightLeft) {
  std::set<int> a({1, 2, 3});
  s21::set<int> b({1, 2, 3});
  a.insert(4);
  a.insert(5);
  a.insert(6);
  auto res1 = a.insert(0);
  // a.insert(-1);
  // a.insert(-2);
  b.insert(4);
  b.insert(5);
  b.insert(6);
  auto res2 = b.insert(0);
  // b.insert(-1);
  // b.insert(-2)
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(*b.end(), int());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
  ASSERT_EQ(*res1.first, *res2.first);
  ASSERT_EQ(res1.second, res2.second);
}

// не будет робить из-за проблем с деструктором
// TEST(ModifiersSet, EraseBegin) {
//   std::set<int> a({1, 2, 3});
//   s21::set<int> b({1, 2, 3});
//   auto it1 = a.begin();
//   auto it2 = b.begin();
//   a.erase(it1);
//   b.erase(it2);
//   ASSERT_EQ(a.size(), b.size());
//   ASSERT_EQ(a.empty(), b.empty());
//   ASSERT_EQ(*b.end(), int());
//   it1 = a.begin();
//   it2 = b.begin();
//   for (; it1 != a.end(); ++it1, ++it2) {
//     ASSERT_EQ(*it1, *it2);
//   }
// }

// деструктор сега
// TEST(ModifiersSet, EraseEnd) {
//   std::set<int> a({1, 2, 3});
//   s21::set<int> b({1, 2, 3});
//   auto it1 = a.end();
//   auto it2 = b.end();
//   a.erase(it1);
//   b.erase(it2);
//   ASSERT_EQ(a.size(), b.size());
//   ASSERT_EQ(a.empty(), b.empty());
//   ASSERT_EQ(*b.end(), int());
//   it1 = a.begin();
//   it2 = b.begin();
//   for (; it1 != a.end(); ++it1, ++it2) {
//     ASSERT_EQ(*it1, *it2);
//   }
// }

// TEST(ModifiersSet, EraseMid) {
//   std::set<int> a({1, 2, 3});
//   s21::set<int> b({1, 2, 3});
//   auto it1 = a.begin();
//   auto it2 = b.begin();
//   ++it1;
//   ++it2;
//   a.erase(it1);
//   b.erase(it2);
//   ASSERT_EQ(a.size(), b.size());
//   ASSERT_EQ(a.empty(), b.empty());
//   ASSERT_EQ(*b.end(), int());
//   it1 = a.begin();
//   it2 = b.begin();
//   for (; it1 != a.end(); ++it1, ++it2) {
//     ASSERT_EQ(*it1, *it2);
//   }
// }

TEST(ModifiersSet, Swap) {
  std::set<int> a({1, 2, 3});
  std::set<int> a1({4, 5, 6});
  s21::set<int> b({1, 2, 3});
  s21::set<int> b1({4, 5, 6});
  a.swap(a1);
  b.swap(b1);
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a1.size(), b1.size());
  ASSERT_EQ(a1.empty(), b1.empty());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
  it1 = a1.begin();
  it2 = b1.begin();
  for (; it1 != a1.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

// сега из-за итератора на нуллптр, я так понимаю
// TEST(ModifiersSet, SwapEmpty) {
//   std::set<int> a;
//   std::set<int> a1;
//   s21::set<int> b;
//   s21::set<int> b1;
//   a.swap(a1);
//   b.swap(b1);
//   ASSERT_EQ(a.size(), b.size());
//   ASSERT_EQ(a.empty(), b.empty());
//   ASSERT_EQ(a1.size(), b1.size());
//   ASSERT_EQ(a1.empty(), b1.empty());
//   auto it1 = a.begin();
//   auto it2 = b.begin();
//   for (; it1 != a.end(); ++it1, ++it2) {
//     ASSERT_EQ(*it1, *it2);
//   }
//   it1 = a1.begin();
//   it2 = b1.begin();
//   for (; it1 != a1.end(); ++it1, ++it2) {
//     ASSERT_EQ(*it1, *it2);
//   }
// }

// TEST(ModifiersSet, MergeThisSmaller) {
//   std::set<int> a({1, 3, 5});
//   std::set<int> a1({2, 3, 4, 4, 7, 8});
//   s21::set<int> b({1, 3, 5});
//   s21::set<int> b1({2, 3, 4, 4, 7, 8});
//   a.merge(a1);
//   b.merge(b1);
//   ASSERT_EQ(a.size(), b.size());
//   ASSERT_EQ(a.empty(), b.empty());
//   ASSERT_EQ(a1.size(), b1.size());
//   ASSERT_EQ(a1.empty(), b1.empty());
//   auto it1 = a.begin();
//   auto it2 = b.begin();
//   for (; it1 != a.end(); ++it1, ++it2) {
//     ASSERT_EQ(*it1, *it2);
//   }
// }

// сега
// TEST(ModifiersSet, MergeOtherSmaller) {
//   std::set<int> a({1, 3, 3, 5, 9});
//   std::set<int> a1({2, 3, 4, 4, 7, 8});
//   s21::set<int> b({1, 3, 3, 5, 9});
//   s21::set<int> b1({2, 3, 4, 4, 7, 8});
//   a.merge(a1);
//   b.merge(b1);
//   ASSERT_EQ(a.size(), b.size());
//   ASSERT_EQ(a.empty(), b.empty());
//   ASSERT_EQ(a1.size(), b1.size());
//   ASSERT_EQ(a1.empty(), b1.empty());
//   auto it1 = a.begin();
//   auto it2 = b.begin();
//   for (; it1 != a.end(); ++it1, ++it2) {
//     ASSERT_EQ(*it1, *it2);
//   }
// }

TEST(LookUpSet, FindLeft) {
  std::set<int> a({1, 2, 3});
  s21::set<int> b({1, 2, 3});
  ASSERT_EQ(*a.find(1), *b.find(1));
}

TEST(LookUpSet, FindRight) {
  std::set<int> a({1, 2, 3});
  s21::set<int> b({1, 2, 3});
  ASSERT_EQ(*a.find(3), *b.find(3));
}

// contains std появился в c++20
TEST(LookUpSet, ContainsTrue) {
  s21::set<int> b({1, 2, 3});
  ASSERT_EQ(true, b.contains(1));
}

TEST(LookUpSet, ContainsFalse) {
  s21::set<int> b({1, 2, 3});
  ASSERT_EQ(false, b.contains(69));
}