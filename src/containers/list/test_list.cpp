#include <gtest/gtest.h>

#include <list>

#include "list.hpp"

TEST(ConstructorList, Default) {
  try {
    s21::list<int> a;
    SUCCEED();
  } catch (...) {
    FAIL() << "Default constructor fails";
  }
}

TEST(ConstructorList, Parametrized) {
  try {
    s21::list<int> a(5);
    SUCCEED();
  } catch (...) {
    FAIL() << "Default constructor fails";
  }
}

TEST(ConstructorList, InitializerListOk) {
  try {
    s21::list<int> a({1, 2});
    SUCCEED();
  } catch (...) {
    FAIL() << "Initializer list constructor fails";
  }
}

TEST(ConstructorList, CopyOk) {
  try {
    s21::list<int> a({1, 2});
    s21::list<int> b = a;
    SUCCEED();
  } catch (...) {
    FAIL() << "Copy constructor fails";
  }
}

TEST(ConstructorList, MoveOk) {
  try {
    s21::list<int> a({1, 2});
    s21::list<int> b(std::move(a));
    SUCCEED();
  } catch (...) {
    FAIL() << "Move constructor fails";
  }
}

TEST(ConstructorList, MoveOperOk) {
  try {
    s21::list<int> a({1, 2});
    s21::list<int> b = std::move(a);
    SUCCEED();
  } catch (...) {
    FAIL() << "Move oper constructor fails";
  }
}

TEST(ElementAccessList, Front) {
  std::list<long> a({1, 2});
  s21::list<long> b({1, 2});
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.front(), b.front());
}

TEST(ElementAccessList, Back) {
  std::list<long> a({1, 2});
  s21::list<long> b({1, 2});
  ASSERT_EQ(a.back(), b.back());
  ASSERT_EQ(a.back(), b.back());
}

TEST(CapacityList, EmptyTrue) {
  std::list<int> a;
  s21::list<int> b;
  ASSERT_EQ(a.empty(), b.empty());
}

TEST(CapacityList, EmptyFalse) {
  std::list<int> a({1, 2, 3});
  s21::list<int> b({1, 2, 3});
  ASSERT_EQ(a.empty(), b.empty());
}

TEST(CapacityList, Size0) {
  std::list<int> a;
  s21::list<int> b;
  ASSERT_EQ(a.size(), b.size());
}

TEST(CapacityList, Size3) {
  std::list<int> a({1, 2, 3});
  s21::list<int> b({1, 2, 3});
  ASSERT_EQ(a.size(), b.size());
}

TEST(CapacityList, MaxSize) {
  std::list<long> a({1, 2, 3});
  s21::list<long> b({1, 2, 3});
  ASSERT_EQ(a.max_size(), b.max_size());
}

// добавить тестов на конст итератор
TEST(IteratorList, Begin) {
  std::list<long> a({1, 2, 3});
  s21::list<long> b({1, 2, 3});
  ASSERT_EQ(*a.begin(), *b.begin());
}

TEST(IteratorList, End) {
  s21::list<long> b({1, 2, 3});
  ASSERT_EQ(*b.end(), long());
}

TEST(IteratorList, Increment) {
  std::list<long> a({1, 2, 3});
  s21::list<long> b({1, 2, 3});
  ASSERT_EQ(*(++a.begin()), *(++b.begin()));
}

TEST(IteratorList, Decrement) {
  std::list<int> a({1, 2, 3});
  s21::list<int> b({1, 2, 3});
  ASSERT_EQ(*(--a.end()), *(--b.end()));
}

TEST(IteratorList, TraverseBeginToEnd) {
  std::list<long> a({1, 2, 3});
  s21::list<long> b({1, 2, 3});
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end() && it2 != b.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(IteratorList, TraverseEndToBegin) {
  std::list<long> a({1, 2, 3});
  s21::list<long> b({1, 2, 3});
  auto it1 = a.end();
  auto it2 = b.end();
  --it1;
  --it2;
  for (; it1 != a.begin() && it2 != b.begin(); --it1, --it2) {
    ASSERT_EQ(*it1, *it2);
  }
  ASSERT_EQ(*it1, *it2);
}

TEST(ModifiersList, Clear) {
  std::list<char> a({'a', 'b', 'c'});
  s21::list<char> b({'a', 'b', 'c'});
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.back(), b.back());
  a.clear();
  b.clear();
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.back(), b.back());
  ASSERT_EQ(*b.end(), char());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end() && it2 != b.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ModifiersList, InsertBegin) {
  std::list<int> a({1, 2, 3});
  s21::list<int> b({1, 2, 3});
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.back(), b.back());
  a.insert(a.begin(), 4);
  b.insert(b.begin(), 4);
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.back(), b.back());
  ASSERT_EQ(*b.end(), int());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end() && it2 != b.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ModifiersList, InsertEnd) {
  std::list<int> a({1, 2, 3});
  s21::list<int> b({1, 2, 3});
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.back(), b.back());
  a.insert(a.end(), 4);
  b.insert(b.end(), 4);
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.back(), b.back());
  ASSERT_EQ(*b.end(), int());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end() && it2 != b.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ModifiersList, InsertWithInc) {
  std::list<int> a({1, 2, 3});
  s21::list<int> b({1, 2, 3});
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.back(), b.back());
  auto iter1 = a.begin();
  auto iter2 = b.begin();
  ++iter1;
  ++iter1;
  ++iter2;
  ++iter2;
  a.insert(iter1, 4);
  b.insert(iter2, 4);
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.back(), b.back());
  ASSERT_EQ(*b.end(), int());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end() && it2 != b.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ModifiersList, InsertWithDecr) {
  std::list<int> a({1, 2, 3});
  s21::list<int> b({1, 2, 3});
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.back(), b.back());
  auto iter1 = a.end();
  auto iter2 = b.end();
  --iter1;
  --iter1;
  --iter2;
  --iter2;
  a.insert(iter1, 4);
  b.insert(iter2, 4);
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.back(), b.back());
  ASSERT_EQ(*b.end(), int());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end() && it2 != b.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ModifiersList, PushBack) {
  std::list<char> a({'a', 'b', 'c'});
  s21::list<char> b({'a', 'b', 'c'});
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.back(), b.back());
  a.push_back('d');
  b.push_back('d');
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.back(), b.back());
  ASSERT_EQ(*b.end(), char());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end() && it2 != b.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ModifiersList, PushBackEmpty) {
  std::list<char> a;
  s21::list<char> b;
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.back(), b.back());
  a.push_back('d');
  b.push_back('d');
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.back(), b.back());
  ASSERT_EQ(*b.end(), char());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end() && it2 != b.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ModifiersList, EraseBegin) {
  std::list<int> a({1, 2, 3});
  s21::list<int> b({1, 2, 3});
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.back(), b.back());
  auto it1 = a.begin();
  auto it2 = b.begin();
  a.erase(it1);
  b.erase(it2);
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.back(), b.back());
  ASSERT_EQ(*b.end(), int());
  it1 = a.begin();
  it2 = b.begin();
  for (; it1 != a.end() && it2 != b.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ModifiersList, EraseEnd) {
  std::list<int> a({1, 2, 3});
  s21::list<int> b({1, 2, 3});
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.back(), b.back());
  auto it1 = a.end();
  auto it2 = b.end();
  a.erase(--it1);
  b.erase(it2);
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.back(), b.back());
  ASSERT_EQ(*b.end(), int());
  it1 = a.begin();
  it2 = b.begin();
  for (; it1 != a.end() && it2 != b.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ModifiersList, EraseIncr) {
  std::list<int> a({1, 2, 3});
  s21::list<int> b({1, 2, 3});
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.back(), b.back());
  auto it1 = a.begin();
  auto it2 = b.begin();
  ++it1;
  ++it1;
  ++it2;
  ++it2;
  a.erase(it1);
  b.erase(it2);
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.back(), b.back());
  ASSERT_EQ(*b.end(), int());
  it1 = a.begin();
  it2 = b.begin();
  for (; it1 != a.end() && it2 != b.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ModifiersList, EraseDecr) {
  std::list<int> a({1, 2, 3});
  s21::list<int> b({1, 2, 3});
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.back(), b.back());
  auto it1 = a.end();
  auto it2 = b.end();
  --it1;
  --it1;
  --it1;
  --it2;
  --it2;
  --it2;
  a.erase(it1);
  b.erase(it2);
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.back(), b.back());
  ASSERT_EQ(*b.end(), int());
  it1 = a.begin();
  it2 = b.begin();
  for (; it1 != a.end() && it2 != b.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ModifiersList, PopBack) {
  std::list<int> a({1, 2, 3});
  s21::list<int> b({1, 2, 3});
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.back(), b.back());
  a.pop_back();
  b.pop_back();
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.back(), b.back());
  ASSERT_EQ(*b.end(), int());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end() && it2 != b.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ModifiersList, PopBackThrow) {
  s21::list<int> b;
  ASSERT_ANY_THROW(b.pop_back());
}

TEST(ModifiersList, PushFront) {
  std::list<char> a({'a', 'b', 'c'});
  s21::list<char> b({'a', 'b', 'c'});
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.back(), b.back());
  a.push_front('d');
  b.push_front('d');
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.back(), b.back());
  ASSERT_EQ(*b.end(), char());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end() && it2 != b.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ModifiersList, PushFrontEmpty) {
  std::list<char> a;
  s21::list<char> b;
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.back(), b.back());
  a.push_front('d');
  b.push_front('d');
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.back(), b.back());
  ASSERT_EQ(*b.end(), char());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end() && it2 != b.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ModifiersList, PopFront) {
  std::list<int> a({1, 2, 3});
  s21::list<int> b({1, 2, 3});
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.back(), b.back());
  a.pop_front();
  b.pop_front();
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.back(), b.back());
  ASSERT_EQ(*b.end(), int());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end() && it2 != b.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ModifiersList, PopFrontThrow) {
  s21::list<int> b;
  ASSERT_ANY_THROW(b.pop_front());
}

TEST(ModifiersList, Swap) {
  std::list<int> a({1, 2, 3});
  std::list<int> a1({4, 5, 6});
  s21::list<int> b({1, 2, 3});
  s21::list<int> b1({4, 5, 6});

  std::swap(a, a1);
  std::swap(b, b1);
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.back(), b.back());
  ASSERT_EQ(a1.size(), b1.size());
  ASSERT_EQ(a1.empty(), b1.empty());
  ASSERT_EQ(a1.front(), b1.front());
  ASSERT_EQ(a1.back(), b1.back());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end() && it2 != b.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
  it1 = a1.begin();
  it2 = b1.begin();
  for (; it1 != a1.end() && it2 != b1.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ModifiersList, SwapEmpty) {
  std::list<int> a;
  std::list<int> a1;
  s21::list<int> b;
  s21::list<int> b1;

  std::swap(a, a1);
  std::swap(b, b1);
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.back(), b.back());
  ASSERT_EQ(a1.size(), b1.size());
  ASSERT_EQ(a1.empty(), b1.empty());
  ASSERT_EQ(a1.front(), b1.front());
  ASSERT_EQ(a1.back(), b1.back());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end() && it2 != b.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
  it1 = a1.begin();
  it2 = b1.begin();
  for (; it1 != a1.end() && it2 != b1.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ModifiersList, SpliceBegin) {
  std::list<long> a({1, 2, 3});
  std::list<long> a1({4, 5, 6});
  s21::list<long> b({1, 2, 3});
  s21::list<long> b1({4, 5, 6});

  a.splice(a.begin(), a1);
  b.splice(b.begin(), b1);
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.back(), b.back());
  ASSERT_EQ(a1.size(), b1.size());
  ASSERT_EQ(a1.empty(), b1.empty());
  ASSERT_EQ(a1.front(), b1.front());
  ASSERT_EQ(a1.back(), b1.back());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end() && it2 != b.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
  it1 = a1.begin();
  it2 = b1.begin();
  for (; it1 != a1.end() && it2 != b1.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}