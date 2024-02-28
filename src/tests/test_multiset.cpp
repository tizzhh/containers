#include <gtest/gtest.h>

#include <set>

#include "../s21_containersplus.hpp"

TEST(ConstructorMultiSet, Default) {
  try {
    s21::multiset<int> a;
    SUCCEED();
  } catch (...) {
    FAIL() << "Default constructor fails";
  }
}

TEST(ConstructorMultiSet, InitializerListOk) {
  try {
    s21::multiset<int> a({1, 2});
    SUCCEED();
  } catch (...) {
    FAIL() << "Initializer multiset constructor fails";
  }
}

TEST(ConstructorMultiSet, CopyOk) {
  try {
    s21::multiset<int> a({1, 2});
    s21::multiset<int> b = a;
    SUCCEED();
  } catch (...) {
    FAIL() << "Copy constructor fails";
  }
}

TEST(ConstructorMultiSet, MoveOk) {
  try {
    s21::multiset<int> a({1, 2});
    s21::multiset<int> b(std::move(a));
    SUCCEED();
  } catch (...) {
    FAIL() << "Move constructor fails";
  }
}

TEST(ConstructorMultiSet, MoveOperOk) {
  try {
    s21::multiset<int> a({1, 2});
    s21::multiset<int> b;
    b = std::move(a);
    SUCCEED();
  } catch (...) {
    FAIL() << "Move oper constructor fails";
  }
}

TEST(IteratorMultiSet, Begin) {
  std::multiset<long> a({1, 2, 3});
  s21::multiset<long> b({1, 2, 3});
  ASSERT_EQ(*a.begin(), *b.begin());
}

TEST(IteratorMultiSet, Eq) {
  std::multiset<long> a({1, 2, 3});
  std::multiset<long> a1({1, 2, 3});
  s21::multiset<long> b({1, 2, 3});
  s21::multiset<long> b1({1, 2, 3});
  ASSERT_EQ(a.begin() == a1.begin(), b.begin() == b1.begin());
}

TEST(IteratorMultiSet, NotEq) {
  std::multiset<long> a({1, 2, 3});
  std::multiset<long> a1({1, 2, 3});
  s21::multiset<long> b({1, 2, 3});
  s21::multiset<long> b1({1, 2, 3});
  ASSERT_EQ(a.begin() != a1.begin(), b.begin() != b1.begin());
}

TEST(IteratorMultiSet, Incr) {
  std::multiset<long> a({1, 2, 3});
  s21::multiset<long> b({1, 2, 3});
  auto iter1 = a.begin();
  auto iter2 = b.begin();
  ++iter1;
  ++iter2;
  ASSERT_EQ(*iter1, *iter2);
}

TEST(IteratorMultiSet, IncrBackwards) {
  std::multiset<long> a({3, 2, 1});
  s21::multiset<long> b({3, 2, 1});
  auto iter1 = a.begin();
  auto iter2 = b.begin();
  ++iter1;
  ++iter2;
  ASSERT_EQ(*iter1, *iter2);
}

TEST(IteratorMultiSet, IncrLastElem) {
  s21::multiset<long> b({1, 2, 3});
  auto iter2 = b.begin();
  ++iter2;
  ++iter2;
  ++iter2;
  ASSERT_EQ(*iter2, *b.end());
}

TEST(IteratorMultiSet, Decr1) {
  std::multiset<long> a({1, 2, 3});
  s21::multiset<long> b({1, 2, 3});
  auto iter1 = a.begin();
  auto iter2 = b.begin();
  ++iter1;
  --iter1;
  ++iter2;
  --iter2;
  ASSERT_EQ(*iter1, *iter2);
}

TEST(IteratorMultiSet, Decr2) {
  std::multiset<long> a({1, 2, 3, 4, 5});
  s21::multiset<long> b({1, 2, 3, 4, 5});
  auto iter1 = a.begin();
  auto iter2 = b.begin();
  ++iter1;
  ++iter1;
  --iter1;
  ++iter2;
  ++iter2;
  --iter2;
  ASSERT_EQ(*iter1, *iter2);
}

TEST(IteratorSet, DecrNotUnique) {
  std::multiset<long> a({1, 1, 1, 1, 1});
  s21::multiset<long> b({1, 1, 1, 1, 1});
  auto iter1 = a.begin();
  auto iter2 = b.begin();
  ++iter1;
  ++iter1;
  ++iter1;
  ++iter1;
  --iter1;
  --iter1;
  --iter1;
  --iter1;
  ++iter2;
  ++iter2;
  ++iter2;
  ++iter2;
  --iter2;
  --iter2;
  --iter2;
  --iter2;
  ASSERT_EQ(*iter1, *iter2);
}

TEST(IteratorMultiSet, DecrFirstElement) {
  s21::multiset<long> b({1, 2, 3});
  auto iter2 = b.begin();
  --iter2;
  ASSERT_EQ(*iter2, *b.begin());
}

TEST(IteratorMultiSet, End) {
  s21::multiset<long> b({1, 2, 3});
  ASSERT_EQ(*b.end(), long());
}

TEST(IteratorMultiSet, BeginEmpty) {
  s21::set<int> b;
  ASSERT_EQ(*b.begin(), *b.end());
}

TEST(ConstIteratorMultiset, Begin) {
  const std::multiset<long> a({1, 2, 3});
  const s21::multiset<long> b({1, 2, 3});
  ASSERT_EQ(*a.cbegin(), *b.cbegin());
}

TEST(ConstIteratorMultiset, Eq) {
  const std::multiset<long> a({1, 2, 3});
  const std::multiset<long> a1({1, 2, 3});
  const s21::multiset<long> b({1, 2, 3});
  const s21::multiset<long> b1({1, 2, 3});
  ASSERT_EQ(a.cbegin() == a1.cbegin(), b.cbegin() == b1.cbegin());
}

TEST(ConstIteratorMultiset, NotEq) {
  const std::multiset<long> a({1, 2, 3});
  const std::multiset<long> a1({1, 2, 3});
  const s21::multiset<long> b({1, 2, 3});
  const s21::multiset<long> b1({1, 2, 3});
  ASSERT_EQ(a.cbegin() != a1.cbegin(), b.cbegin() != b1.cbegin());
}

TEST(ConstIteratorMultiset, Incr) {
  const std::multiset<long> a({1, 2, 3});
  const s21::multiset<long> b({1, 2, 3});
  auto iter1 = a.cbegin();
  auto iter2 = b.cbegin();
  ++iter1;
  ++iter2;
  ASSERT_EQ(*iter1, *iter2);
}

TEST(ConstIteratorMultiset, IncrBackwards) {
  const std::multiset<long> a({3, 2, 1});
  const s21::multiset<long> b({3, 2, 1});
  auto iter1 = a.cbegin();
  auto iter2 = b.cbegin();
  ++iter1;
  ++iter2;
  ASSERT_EQ(*iter1, *iter2);
}

TEST(ConstIteratorMultiset, IncrLastElem) {
  const s21::multiset<long> b({1, 2, 3});
  auto iter2 = b.cbegin();
  ++iter2;
  ++iter2;
  ++iter2;
  ASSERT_EQ(*iter2, *b.cend());
}

TEST(ConstIteratorMultiset, Decr1) {
  const std::multiset<long> a({1, 2, 3});
  const s21::multiset<long> b({1, 2, 3});
  auto iter1 = a.cbegin();
  auto iter2 = b.cbegin();
  ++iter1;
  --iter1;
  ++iter2;
  --iter2;
  ASSERT_EQ(*iter1, *iter2);
}

TEST(ConstIteratorMultiset, Decr2) {
  const std::multiset<long> a({1, 2, 3, 4, 5});
  const s21::multiset<long> b({1, 2, 3, 4, 5});
  auto iter1 = a.cbegin();
  auto iter2 = b.cbegin();
  ++iter1;
  ++iter1;
  --iter1;
  ++iter2;
  ++iter2;
  --iter2;
  ASSERT_EQ(*iter1, *iter2);
}

TEST(ConstIteratorMultiset, DecrFirstElement) {
  const s21::multiset<long> b({1, 2, 3});
  auto iter2 = b.cbegin();
  --iter2;
  ASSERT_EQ(*iter2, *b.cbegin());
}

TEST(ConstIteratorMultiset, End) {
  const s21::multiset<long> b({1, 2, 3});
  ASSERT_EQ(*b.cend(), long());
}

TEST(ConstIteratorMultiSet, BeginEmpty) {
  const s21::multiset<int> b;
  ASSERT_EQ(*b.cbegin(), *b.cend());
}

TEST(CapacityMultiSet, EmptyTrue) {
  std::multiset<int> a;
  s21::multiset<int> b;
  ASSERT_EQ(a.empty(), b.empty());
}

TEST(CapacityMultiSet, EmptyFalse) {
  std::multiset<int> a({1, 2, 3});
  s21::multiset<int> b({1, 2, 3});
  ASSERT_EQ(a.empty(), b.empty());
}

TEST(CapacityMultiSet, Size0) {
  std::multiset<int> a;
  s21::multiset<int> b;
  ASSERT_EQ(a.size(), b.size());
}

TEST(CapacityMultiSet, Size3) {
  std::multiset<char> a({'a', 'b', 'c'});
  s21::multiset<char> b({'a', 'b', 'c'});
  ASSERT_EQ(a.size(), b.size());
}

TEST(CapacityMultiSet, MaxSize) {
  std::multiset<char> a({'a'});
  s21::multiset<char> b({'a'});
  ASSERT_EQ(a.max_size(), b.max_size());
}

TEST(ModifiersMultiSet, Clear) {
  std::multiset<char> a({'a', 'b', 'c'});
  s21::multiset<char> b({'a', 'b', 'c'});
  a.clear();
  b.clear();
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(*b.end(), char());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ModifiersMultiSet, InsertNotUnique) {
  std::multiset<int> a({1, 1, 1, 1, 2});
  s21::multiset<int> b({1, 1, 1, 1, 2});
  auto res1 = a.insert(2);
  auto res2 = b.insert(2);
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(*b.end(), int());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
  ASSERT_EQ(*res1, *res2);
}

TEST(ModifiersMultiSet, InsertRight) {
  std::multiset<int> a({1, 2, 3});
  s21::multiset<int> b({1, 2, 3});
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
  ASSERT_EQ(*res1, *res2);
}

TEST(ModifiersMultiSet, InsertLeft) {
  std::multiset<int> a({1, 2, 3});
  s21::multiset<int> b({1, 2, 3});
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
  ASSERT_EQ(*res1, *res2);
}

TEST(ModifiersMultiSet, InsertManyRightLeft) {
  std::multiset<int> a({1, 2, 3});
  s21::multiset<int> b({1, 2, 3});
  a.insert(4);
  a.insert(5);
  a.insert(6);
  auto res1 = a.insert(0);
  a.insert(-1);
  a.insert(-2);
  b.insert(4);
  b.insert(5);
  b.insert(6);
  auto res2 = b.insert(0);
  b.insert(-1);
  b.insert(-2);
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(*b.end(), int());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
  ASSERT_EQ(*res1, *res2);
}

TEST(ModifiersMultiSet, InsertMany) {
  std::multiset<int> exp({1, 1, 2, 3, 4});
  s21::multiset<int> b({1});
  auto res2 = b.insert_many(1, 2, 3, 4);
  ASSERT_EQ(exp.size(), b.size());
  ASSERT_EQ(exp.empty(), b.empty());
  ASSERT_EQ(*b.end(), int());
  auto it1 = exp.begin();
  auto it2 = b.begin();
  for (; it1 != exp.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
  std::vector<std::pair<int, bool>> exp_res = {
      {1, true}, {2, true}, {3, true}, {4, true}};
  ASSERT_EQ(res2.size(), exp_res.size());
  for (size_t i = 0; i != exp_res.size(); ++i) {
    ASSERT_EQ(*(res2[i].first), exp_res[i].first);
    ASSERT_EQ(res2[i].second, exp_res[i].second);
  }
}

TEST(ModifiersMultiSet, RightSmall) {
  std::multiset<int> a({19, 15});
  s21::multiset<int> b({19, 15});
  auto res1 = a.insert(12);
  auto res2 = b.insert(12);
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(*b.end(), int());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
  ASSERT_EQ(*res1, *res2);
}

TEST(ModifiersMultiSet, LeftBig) {
  std::multiset<int> a({1, 5, 10, 15, 11, 18, 16, 23});
  s21::multiset<int> b({1, 5, 10, 15, 11, 18, 16, 23});
  auto res1 = a.insert(17);
  auto res2 = b.insert(17);
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(*b.end(), int());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
  ASSERT_EQ(*res1, *res2);
}

TEST(ModifiersMultiSet, RightBig) {
  std::multiset<int> a({23, 16, 18, 11, 15, 10, 5, 1});
  s21::multiset<int> b({23, 16, 18, 11, 15, 10, 5, 1});
  auto res1 = a.insert(17);
  auto res2 = b.insert(17);
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(*b.end(), int());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
  ASSERT_EQ(*res1, *res2);
}

TEST(ModifiersMultiSet, EraseBegin) {
  std::multiset<int> a({1, 2, 3, 4, 5, 6, 7});
  s21::multiset<int> b({1, 2, 3, 4, 5, 6, 7});
  auto it1 = a.begin();
  auto it2 = b.begin();
  a.erase(it1);
  b.erase(it2);
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(*b.end(), int());
  it1 = a.begin();
  it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ModifiersMultiSet, EraseSecondElem) {
  std::multiset<int> a({1, 2, 3, 4, 5, 6, 7});
  s21::multiset<int> b({1, 2, 3, 4, 5, 6, 7});
  auto it1 = a.begin();
  auto it2 = b.begin();
  ++it1;
  ++it2;
  a.erase(it1);
  b.erase(it2);
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(*b.end(), int());
  it1 = a.begin();
  it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ModifiersMultiSet, EraseThirdElem) {
  std::multiset<int> a({1, 2, 3, 4, 5, 6, 7});
  s21::multiset<int> b({1, 2, 3, 4, 5, 6, 7});
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
  ASSERT_EQ(*b.end(), int());
  it1 = a.begin();
  it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ModifiersMultiSet, EraseFourthElem) {
  std::multiset<int> a({1, 2, 3, 4, 5, 6, 7});
  s21::multiset<int> b({1, 2, 3, 4, 5, 6, 7});
  auto it1 = a.begin();
  auto it2 = b.begin();
  ++it1;
  ++it1;
  ++it1;
  ++it2;
  ++it2;
  ++it2;
  a.erase(it1);
  b.erase(it2);
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(*b.end(), int());
  it1 = a.begin();
  it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ModifiersMultiSet, EraseFifthElem) {
  std::multiset<int> a({1, 2, 3, 4, 5, 6, 7});
  s21::multiset<int> b({1, 2, 3, 4, 5, 6, 7});
  auto it1 = a.begin();
  auto it2 = b.begin();
  ++it1;
  ++it1;
  ++it1;
  ++it1;
  ++it2;
  ++it2;
  ++it2;
  ++it2;
  a.erase(it1);
  b.erase(it2);
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(*b.end(), int());
  it1 = a.begin();
  it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}
TEST(ModifiersMultiSet, EraseSixthElem) {
  std::multiset<int> a({1, 2, 3, 4, 5, 6, 7});
  s21::multiset<int> b({1, 2, 3, 4, 5, 6, 7});
  auto it1 = a.begin();
  auto it2 = b.begin();
  ++it1;
  ++it1;
  ++it1;
  ++it1;
  ++it1;
  ++it2;
  ++it2;
  ++it2;
  ++it2;
  ++it2;
  a.erase(it1);
  b.erase(it2);
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(*b.end(), int());
  it1 = a.begin();
  it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}
TEST(ModifiersMultiSet, EraseSeventhElem) {
  std::multiset<int> a({1, 2, 3, 4, 5, 6, 7});
  s21::multiset<int> b({1, 2, 3, 4, 5, 6, 7});
  auto it1 = a.begin();
  auto it2 = b.begin();
  ++it1;
  ++it1;
  ++it1;
  ++it1;
  ++it1;
  ++it2;
  ++it2;
  ++it2;
  ++it2;
  ++it2;
  a.erase(it1);
  b.erase(it2);
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(*b.end(), int());
  it1 = a.begin();
  it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ModifiersMultiSet, EraseEnd) {
  std::multiset<int> a({1, 2, 3});
  s21::multiset<int> b({1, 2, 3});
  b.erase(b.end());
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(*b.end(), int());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ModifiersMultiSet, EraseMid) {
  std::multiset<int> a = {1, 2, 3};
  s21::multiset<int> b = {1, 2, 3};
  auto it1 = a.begin();
  auto it2 = b.begin();
  ++it1;
  ++it2;
  a.erase(it1);
  b.erase(it2);
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(*b.end(), int());
  it1 = a.begin();
  it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ModifiersMultiSet, Swap) {
  std::multiset<int> a({1, 2, 3});
  std::multiset<int> a1({4, 5, 6});
  s21::multiset<int> b({1, 2, 3});
  s21::multiset<int> b1({4, 5, 6});
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

TEST(ModifiersMultiSet, SwapFromEmpty) {
  std::multiset<int> a({1, 2, 3});
  std::multiset<int> a1;
  s21::multiset<int> b({1, 2, 3});
  s21::multiset<int> b1;
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

TEST(ModifiersMultiSet, SwapToEmpty) {
  std::multiset<int> a;
  std::multiset<int> a1({1, 2, 3});
  s21::multiset<int> b;
  s21::multiset<int> b1({1, 2, 3});
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

TEST(ModifiersMultiSet, SwapEmpty) {
  std::multiset<int> a;
  std::multiset<int> a1;
  s21::multiset<int> b;
  s21::multiset<int> b1;
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

TEST(ModifiersMultiSet, MergeThisSmaller) {
  std::multiset<int> a({1, 3, 5});
  std::multiset<int> a1({2, 3, 4, 7, 8});
  s21::multiset<int> b({1, 3, 5});
  s21::multiset<int> b1({2, 3, 4, 7, 8});
  a.merge(a1);
  b.merge(b1);
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a1.size(), b1.size());
  ASSERT_EQ(a1.empty(), b1.empty());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ModifiersMultiSet, MergeOtherSmaller) {
  std::multiset<int> a({1, 3, 5, 9});
  std::multiset<int> a1({2, 3, 4, 7, 8});
  s21::multiset<int> b({1, 3, 5, 9});
  s21::multiset<int> b1({2, 3, 4, 7, 8});
  a.merge(a1);
  b.merge(b1);
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a1.size(), b1.size());
  ASSERT_EQ(a1.empty(), b1.empty());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ModifiersMultiSet, MergeIntoEmpty) {
  std::multiset<int> a;
  std::multiset<int> a1({2, 3, 4, 7, 8});
  s21::multiset<int> b;
  s21::multiset<int> b1({2, 3, 4, 7, 8});
  a.merge(a1);
  b.merge(b1);
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a1.size(), b1.size());
  ASSERT_EQ(a1.empty(), b1.empty());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(ModifiersMultiSet, MergeFromEmpty) {
  std::multiset<int> a({2, 3, 4, 7, 8});
  std::multiset<int> a1;
  s21::multiset<int> b({2, 3, 4, 7, 8});
  s21::multiset<int> b1;
  a.merge(a1);
  b.merge(b1);
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a1.size(), b1.size());
  ASSERT_EQ(a1.empty(), b1.empty());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(*it1, *it2);
  }
}

TEST(LookUpMultiSet, FindLeft) {
  std::multiset<int> a({1, 2, 3});
  s21::multiset<int> b({1, 2, 3});
  ASSERT_EQ(*a.find(1), *b.find(1));
}

TEST(LookUpMultiSet, FindRight) {
  std::multiset<int> a({1, 2, 3});
  s21::multiset<int> b({1, 2, 3});
  ASSERT_EQ(*a.find(3), *b.find(3));
}

// contains std появился в c++20
TEST(LookUpMultiSet, ContainsTrue) {
  s21::multiset<int> b({1, 2, 3});
  ASSERT_EQ(true, b.contains(1));
}

TEST(LookUpMultiSet, ContainsFalse) {
  s21::multiset<int> b({1, 2, 3});
  ASSERT_EQ(false, b.contains(69));
}

TEST(LookUpMultiSet, CountExists) {
  std::multiset<long> a({1, 1, 1, 1, 1});
  s21::multiset<long> b({1, 1, 1, 1, 1});
  ASSERT_EQ(a.count(1), b.count(1));
}

TEST(LookUpMultiSet, CountDoesNotExist) {
  std::multiset<long> a({1, 1, 1, 1, 1});
  s21::multiset<long> b({1, 1, 1, 1, 1});
  ASSERT_EQ(a.count(0), b.count(0));
}

TEST(LookUpMultiSet, LowerBound) {
  std::multiset<long> a({1, 2, 3, 3, 3, 4, 5});
  s21::multiset<long> b({1, 2, 3, 3, 3, 4, 5});
  auto iter1 = a.lower_bound(3);
  auto iter2 = b.lower_bound(3);
  for (; iter1 != a.end(); ++iter1, ++iter2) {
    ASSERT_EQ(*iter1, *iter2);
  }
}

TEST(LookUpMultiSet, UpperBound) {
  std::multiset<long> a({1, 2, 3, 3, 3, 4, 5});
  s21::multiset<long> b({1, 2, 3, 3, 3, 4, 5});
  auto iter1 = a.upper_bound(3);
  auto iter2 = b.upper_bound(3);
  for (; iter1 != a.end(); ++iter1, ++iter2) {
    ASSERT_EQ(*iter1, *iter2);
  }
}

TEST(LookUpMultiSet, EqualRange) {
  std::multiset<long> a({1, 2, 3, 3, 3, 4, 5});
  s21::multiset<long> b({1, 2, 3, 3, 3, 4, 5});
  auto pair1 = a.equal_range(3);
  auto pair2 = b.equal_range(3);
  auto iter1 = pair1.first;
  auto iter2 = pair2.first;
  for (; iter1 != pair1.second; ++iter1, ++iter2) {
    ASSERT_EQ(*iter1, *iter2);
  }
}