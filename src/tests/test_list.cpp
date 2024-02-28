#include <gtest/gtest.h>

#include <list>

#include "../s21_containers.hpp"

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
    s21::list<int> b;
    b = std::move(a);
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
  for (; it1 != a.end(); ++it1, ++it2) {
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
  for (; it1 != a.begin(); --it1, --it2) {
    ASSERT_EQ(*it1, *it2);
  }
  ASSERT_EQ(*it1, *it2);
}

TEST(IteratorList, Advance) {
  std::list<long> a({1, 2, 3});
  s21::list<long> b({1, 2, 3});
  auto it1 = a.begin();
  auto it2 = b.begin();
  std::advance(it1, 1);
  it2.advance(1);
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(IteratorList, AdvanceFromEnd) {
  std::list<long> a({1, 2, 3});
  s21::list<long> b({1, 2, 3});
  auto it1 = a.end();
  auto it2 = b.end();
  std::advance(it1, -1);
  it2.advance(-1);
  for (; it1 != a.begin(); --it1, --it2) {
    ASSERT_EQ(*it1, *it2);
  }
  ASSERT_EQ(*it1, *it2);
}

TEST(IteratorList, Next) {
  std::list<long> a({1, 2, 3});
  s21::list<long> b({1, 2, 3});
  auto it1 = a.begin();
  auto it2 = b.begin();
  it1 = std::next(it1);
  it2.next();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(IteratorList, Prev) {
  std::list<long> a({1, 2, 3});
  s21::list<long> b({1, 2, 3});
  auto it1 = a.end();
  auto it2 = b.end();
  it1 = std::prev(it1);
  it2.prev();
  for (; it1 != a.begin(); --it1, --it2) {
    ASSERT_EQ(*it1, *it2);
  }
  ASSERT_EQ(*it1, *it2);
}

TEST(IteratorList, Eq) {
  std::list<long> a({1, 2, 3});
  s21::list<long> b({1, 2, 3});
  auto it1 = a.begin();
  auto it2 = a.begin();
  auto it3 = b.begin();
  auto it4 = b.begin();
  ASSERT_EQ(it1 == it2, it3 == it4);
}

TEST(ConstIteratorList, Begin) {
  const std::list<long> a({1, 2, 3});
  const s21::list<long> b({1, 2, 3});
  ASSERT_EQ(*a.begin(), *b.begin());
}

TEST(ConstIteratorList, End) {
  const s21::list<long> b({1, 2, 3});
  ASSERT_EQ(*b.end(), long());
}

TEST(ConstIteratorList, Increment) {
  const std::list<long> a({1, 2, 3});
  const s21::list<long> b({1, 2, 3});
  ASSERT_EQ(*(++a.begin()), *(++b.begin()));
}

TEST(ConstIteratorList, Decrement) {
  const std::list<int> a({1, 2, 3});
  const s21::list<int> b({1, 2, 3});
  ASSERT_EQ(*(--a.end()), *(--b.end()));
}

TEST(ConstIteratorList, TraverseBeginToEnd) {
  const std::list<long> a({1, 2, 3});
  const s21::list<long> b({1, 2, 3});
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ConstIteratorList, TraverseEndToBegin) {
  const std::list<long> a({1, 2, 3});
  const s21::list<long> b({1, 2, 3});
  auto it1 = a.end();
  auto it2 = b.end();
  --it1;
  --it2;
  for (; it1 != a.begin(); --it1, --it2) {
    ASSERT_EQ(*it1, *it2);
  }
  ASSERT_EQ(*it1, *it2);
}

TEST(ConstIteratorList, Eq) {
  const std::list<long> a({1, 2, 3});
  const s21::list<long> b({1, 2, 3});
  auto it1 = a.begin();
  auto it2 = a.begin();
  auto it3 = b.begin();
  auto it4 = b.begin();
  ASSERT_EQ(it1 == it2, it3 == it4);
}

TEST(ConstIteratorList, Advance) {
  const std::list<long> a({1, 2, 3});
  const s21::list<long> b({1, 2, 3});
  auto it1 = a.begin();
  auto it2 = b.begin();
  std::advance(it1, 1);
  it2.advance(1);
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ConstIteratorList, AdvanceFromEnd) {
  const std::list<long> a({1, 2, 3});
  const s21::list<long> b({1, 2, 3});
  auto it1 = a.end();
  auto it2 = b.end();
  std::advance(it1, -1);
  it2.advance(-1);
  for (; it1 != a.begin(); --it1, --it2) {
    ASSERT_EQ(*it1, *it2);
  }
  ASSERT_EQ(*it1, *it2);
}

TEST(ConstIteratorList, Next) {
  const std::list<long> a({1, 2, 3});
  const s21::list<long> b({1, 2, 3});
  auto it1 = a.begin();
  auto it2 = b.begin();
  it1 = std::next(it1);
  it2.next();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ConstIteratorList, Prev) {
  const std::list<long> a({1, 2, 3});
  const s21::list<long> b({1, 2, 3});
  auto it1 = a.end();
  auto it2 = b.end();
  it1 = std::prev(it1);
  it2.prev();
  for (; it1 != a.begin(); --it1, --it2) {
    ASSERT_EQ(*it1, *it2);
  }
  ASSERT_EQ(*it1, *it2);
}

TEST(ConstIteratorList, OperArrow) {
  const s21::list<long> b({1, 2, 3});
  auto it2 = b.begin();
  it2 = it2->next;
  int res = *it2;
  ASSERT_EQ(res, 2);
}

TEST(ModifiersList, Clear) {
  std::list<char> a({'a', 'b', 'c'});
  s21::list<char> b({'a', 'b', 'c'});
  a.clear();
  b.clear();
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.back(), b.back());
  ASSERT_EQ(*b.end(), char());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ModifiersList, InsertBegin) {
  std::list<int> a({1, 2, 3});
  s21::list<int> b({1, 2, 3});
  a.insert(a.begin(), 4);
  b.insert(b.begin(), 4);
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.back(), b.back());
  ASSERT_EQ(*b.end(), int());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ModifiersList, InsertEnd) {
  std::list<int> a({1, 2, 3});
  s21::list<int> b({1, 2, 3});
  a.insert(a.end(), 4);
  b.insert(b.end(), 4);
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.back(), b.back());
  ASSERT_EQ(*b.end(), int());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ModifiersList, InsertWithInc) {
  std::list<int> a({1, 2, 3});
  s21::list<int> b({1, 2, 3});
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
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ModifiersList, InsertWithDecr) {
  std::list<int> a({1, 2, 3});
  s21::list<int> b({1, 2, 3});
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
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ModifiersList, PushBack) {
  std::list<char> a({'a', 'b', 'c'});
  s21::list<char> b({'a', 'b', 'c'});
  a.push_back('d');
  b.push_back('d');
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.back(), b.back());
  ASSERT_EQ(*b.end(), char());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ModifiersList, PushBackEmpty) {
  std::list<char> a;
  s21::list<char> b;
  a.push_back('d');
  b.push_back('d');
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.back(), b.back());
  ASSERT_EQ(*b.end(), char());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ModifiersList, EraseBegin) {
  std::list<int> a({1, 2, 3});
  s21::list<int> b({1, 2, 3});
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
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ModifiersList, EraseEnd) {
  std::list<int> a({1, 2, 3});
  s21::list<int> b({1, 2, 3});
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
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ModifiersList, EraseIncr) {
  std::list<int> a({1, 2, 3});
  s21::list<int> b({1, 2, 3});
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
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ModifiersList, EraseDecr) {
  std::list<int> a({1, 2, 3});
  s21::list<int> b({1, 2, 3});
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
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ModifiersList, PopBack) {
  std::list<int> a({1, 2, 3});
  s21::list<int> b({1, 2, 3});
  a.pop_back();
  b.pop_back();
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.back(), b.back());
  ASSERT_EQ(*b.end(), int());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ModifiersList, PopBackThrow) {
  s21::list<int> b;
  ASSERT_ANY_THROW(b.pop_back());
}

TEST(ModifiersList, PopBackOneELem) {
  std::list<int> a({1});
  s21::list<int> b({1});
  a.pop_back();
  b.pop_back();
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.back(), b.back());
  ASSERT_EQ(*b.end(), int());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ModifiersList, PushFront) {
  std::list<char> a({'a', 'b', 'c'});
  s21::list<char> b({'a', 'b', 'c'});
  a.push_front('d');
  b.push_front('d');
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.back(), b.back());
  ASSERT_EQ(*b.end(), char());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ModifiersList, PushFrontEmpty) {
  std::list<char> a;
  s21::list<char> b;
  a.push_front('d');
  b.push_front('d');
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.back(), b.back());
  ASSERT_EQ(*b.end(), char());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ModifiersList, PopFront) {
  std::list<int> a({1, 2, 3});
  s21::list<int> b({1, 2, 3});
  a.pop_front();
  b.pop_front();
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.back(), b.back());
  ASSERT_EQ(*b.end(), int());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ModifiersList, PopFrontThrow) {
  s21::list<int> b;
  ASSERT_ANY_THROW(b.pop_front());
}

TEST(ModifiersList, PopFrontOneELem) {
  std::list<int> a({1});
  s21::list<int> b({1});
  a.pop_front();
  b.pop_front();
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.back(), b.back());
  ASSERT_EQ(*b.end(), int());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ModifiersList, Swap) {
  std::list<int> a({1, 2, 3});
  std::list<int> a1({4, 5, 6});
  s21::list<int> b({1, 2, 3});
  s21::list<int> b1({4, 5, 6});
  a.swap(a1);
  b.swap(b1);
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
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
  it1 = a1.begin();
  it2 = b1.begin();
  for (; it1 != a1.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ModifiersList, SwapEmpty) {
  std::list<int> a;
  std::list<int> a1;
  s21::list<int> b;
  s21::list<int> b1;
  a.swap(a1);
  b.swap(b1);
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
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
  it1 = a1.begin();
  it2 = b1.begin();
  for (; it1 != a1.end(); ++it1, ++it2) {
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
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
  it1 = a1.begin();
  it2 = b1.begin();
  for (; it1 != a1.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ModifiersList, SpliceEnd) {
  std::list<long> a({1, 2, 3});
  std::list<long> a1({4, 5, 6});
  s21::list<long> b({1, 2, 3});
  s21::list<long> b1({4, 5, 6});
  a.splice(a.end(), a1);
  b.splice(b.end(), b1);
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
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
  it1 = a1.begin();
  it2 = b1.begin();
  for (; it1 != a1.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ModifiersList, SpliceMid) {
  std::list<long> a({1, 2, 3});
  std::list<long> a1({4, 5, 6});
  s21::list<long> b({1, 2, 3});
  s21::list<long> b1({4, 5, 6});
  auto it1 = a.begin();
  auto it2 = b.begin();
  ++it1;
  ++it1;
  ++it2;
  ++it2;
  a.splice(it1, a1);
  b.splice(it2, b1);
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.back(), b.back());
  ASSERT_EQ(a1.size(), b1.size());
  ASSERT_EQ(a1.empty(), b1.empty());
  ASSERT_EQ(a1.front(), b1.front());
  ASSERT_EQ(a1.back(), b1.back());
  it1 = a.begin();
  it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
  it1 = a1.begin();
  it2 = b1.begin();
  for (; it1 != a1.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ModifiersList, Reverse) {
  std::list<char> a({1, 2, 3, 4, 5});
  s21::list<char> b({1, 2, 3, 4, 5});
  a.reverse();
  b.reverse();
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.back(), b.back());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ModifiersList, ReverseEmpty) {
  std::list<char> a;
  s21::list<char> b;
  a.reverse();
  b.reverse();
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.back(), b.back());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ModifiersList, Unique) {
  std::list<long> a({1, 2, 2, 3, 3, 2, 1, 1, 2});
  s21::list<long> b({1, 2, 2, 3, 3, 2, 1, 1, 2});
  a.unique();
  b.unique();
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.back(), b.back());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ModifiersList, UniqueEmpty) {
  std::list<long> a;
  s21::list<long> b;
  a.unique();
  b.unique();
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.back(), b.back());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ModifiersList, MergeThisSmaller) {
  std::list<int> a({1, 3, 3, 5});
  std::list<int> a1({2, 3, 4, 4, 7, 8});
  s21::list<int> b({1, 3, 3, 5});
  s21::list<int> b1({2, 3, 4, 4, 7, 8});
  a.merge(a1);
  b.merge(b1);
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
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ModifiersList, MergeOtherSmaller) {
  std::list<int> a({1, 3, 3, 5, 9});
  std::list<int> a1({2, 3, 4, 4, 7, 8});
  s21::list<int> b({1, 3, 3, 5, 9});
  s21::list<int> b1({2, 3, 4, 4, 7, 8});
  a.merge(a1);
  b.merge(b1);
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
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ModifiersList, MergeFromEmpty) {
  std::list<int> a({1, 3, 3, 5, 9});
  std::list<int> a1;
  s21::list<int> b({1, 3, 3, 5, 9});
  s21::list<int> b1;
  a.merge(a1);
  b.merge(b1);
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
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ModifiersList, MergeIntoEmpty) {
  std::list<int> a({1, 3, 3, 5, 9});
  std::list<int> a1;
  s21::list<int> b({1, 3, 3, 5, 9});
  s21::list<int> b1;
  a1.merge(a);
  b1.merge(b);
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
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ModifiersList, MergeThrow) {
  s21::list<int> b({3, 2, 1});
  s21::list<int> b1({2, 3, 4, 4, 7, 8});
  ASSERT_ANY_THROW(b.merge(b1));
}

TEST(ModifiersList, InsertManyBegin) {
  s21::list<int> a({1, 2, 3});
  s21::list<int> b({10, 11, 12, 1, 2, 3});
  a.insert_many(a.begin(), 10, 11, 12);
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.back(), b.back());
  ASSERT_EQ(*b.end(), int());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ModifiersList, InsertManyEnd) {
  s21::list<int> a({1, 2, 3});
  s21::list<int> b({1, 2, 3, 10, 11, 12});
  a.insert_many(a.end(), 10, 11, 12);
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.back(), b.back());
  ASSERT_EQ(*b.end(), int());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ModifiersList, InsertManyMid) {
  s21::list<int> a({1, 2, 3, 4});
  s21::list<int> b({1, 2, 10, 11, 12, 3, 4});
  auto iter = a.begin();
  ++iter;
  ++iter;
  a.insert_many(iter, 10, 11, 12);
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.back(), b.back());
  ASSERT_EQ(*b.end(), int());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ModifiersList, InsertManyBack) {
  s21::list<int> a({1, 2, 3});
  s21::list<int> b({1, 2, 3, 10, 11, 12});
  a.insert_many_back(10, 11, 12);
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.back(), b.back());
  ASSERT_EQ(*b.end(), int());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ModifiersList, InsertManyBackEmpty) {
  s21::list<int> a;
  s21::list<int> b({10, 11, 12});
  a.insert_many_back(10, 11, 12);
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.back(), b.back());
  ASSERT_EQ(*b.end(), int());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ModifiersList, InsertManyFront) {
  s21::list<int> a({1, 2, 3});
  s21::list<int> b({12, 11, 10, 1, 2, 3});
  a.insert_many_front(10, 11, 12);
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.back(), b.back());
  ASSERT_EQ(*b.end(), int());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ModifiersList, InsertManyFrontEmpty) {
  s21::list<int> a;
  s21::list<int> b({12, 11, 10});
  a.insert_many_front(10, 11, 12);
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.back(), b.back());
  ASSERT_EQ(*b.end(), int());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ModifiersList, Sort) {
  std::list<long> a = {3, 2, 1};
  s21::list<long> b = {3, 2, 1};
  a.sort();
  b.sort();
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.back(), b.back());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ModifiersList, SortNothing) {
  std::list<long> a = {1, 2, 3};
  s21::list<long> b = {1, 2, 3};
  a.sort();
  b.sort();
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.back(), b.back());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ModifiersList, SortEmpty) {
  std::list<long> a;
  s21::list<long> b;
  a.sort();
  b.sort();
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.back(), b.back());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}
