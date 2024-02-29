#include <gtest/gtest.h>

#include <set>
#include <vector>

#include "../s21_containers.hpp"

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

TEST(ConstructorSet, CopyOk) {
  try {
    s21::set<int> a({1, 2});
    s21::set<int> b = a;
    SUCCEED();
  } catch (...) {
    FAIL() << "Copy constructor fails";
  }
}

TEST(ConstructorSet, MoveOk) {
  try {
    s21::set<int> a({1, 2});
    s21::set<int> b(std::move(a));
    SUCCEED();
  } catch (...) {
    FAIL() << "Move constructor fails";
  }
}

TEST(ConstructorSet, MoveOperOk) {
  try {
    s21::set<int> a({1, 2});
    s21::set<int> b;
    b = std::move(a);
    SUCCEED();
  } catch (...) {
    FAIL() << "Move oper constructor fails";
  }
}

TEST(IteratorSet, Begin) {
  std::set<long> a({1, 2, 3});
  s21::set<long> b({1, 2, 3});
  ASSERT_EQ(*a.begin(), *b.begin());
}

TEST(IteratorSet, Eq) {
  std::set<long> a({1, 2, 3});
  std::set<long> a1({1, 2, 3});
  s21::set<long> b({1, 2, 3});
  s21::set<long> b1({1, 2, 3});
  ASSERT_EQ(a.begin() == a1.begin(), b.begin() == b1.begin());
}

TEST(IteratorSet, NotEq) {
  std::set<long> a({1, 2, 3});
  std::set<long> a1({1, 2, 3});
  s21::set<long> b({1, 2, 3});
  s21::set<long> b1({1, 2, 3});
  ASSERT_EQ(a.begin() != a1.begin(), b.begin() != b1.begin());
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

TEST(IteratorSet, IncrBackwards) {
  std::set<long> a({3, 2, 1});
  s21::set<long> b({3, 2, 1});
  auto iter1 = a.begin();
  auto iter2 = b.begin();
  ++iter1;
  ++iter2;
  ASSERT_EQ(*iter1, *iter2);
}

TEST(IteratorSet, IncrLastElem) {
  s21::set<long> b({1, 2, 3});
  auto iter2 = b.begin();
  ++iter2;
  ++iter2;
  ++iter2;
  ASSERT_EQ(*iter2, *b.end());
}

TEST(IteratorSet, Decr1) {
  std::set<long> a({1, 2, 3});
  s21::set<long> b({1, 2, 3});
  auto iter1 = a.begin();
  auto iter2 = b.begin();
  ++iter1;
  --iter1;
  ++iter2;
  --iter2;
  ASSERT_EQ(*iter1, *iter2);
}

TEST(IteratorSet, Decr2) {
  std::set<long> a({1, 2, 3, 4, 5});
  s21::set<long> b({1, 2, 3, 4, 5});
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

TEST(IteratorSet, BeginEmpty) {
  s21::set<int> b;
  ASSERT_EQ(*b.begin(), *b.end());
}

TEST(ConstIteratorSet, Begin) {
  const std::set<long> a({1, 2, 3});
  const s21::set<long> b({1, 2, 3});
  ASSERT_EQ(*a.cbegin(), *b.cbegin());
}

TEST(ConstIteratorSet, Eq) {
  const std::set<long> a({1, 2, 3});
  const std::set<long> a1({1, 2, 3});
  const s21::set<long> b({1, 2, 3});
  const s21::set<long> b1({1, 2, 3});
  ASSERT_EQ(a.cbegin() == a1.cbegin(), b.cbegin() == b1.cbegin());
}

TEST(ConstIteratorSet, NotEq) {
  const std::set<long> a({1, 2, 3});
  const std::set<long> a1({1, 2, 3});
  const s21::set<long> b({1, 2, 3});
  const s21::set<long> b1({1, 2, 3});
  ASSERT_EQ(a.cbegin() != a1.cbegin(), b.cbegin() != b1.cbegin());
}

TEST(ConstIteratorSet, Incr) {
  const std::set<long> a({1, 2, 3});
  const s21::set<long> b({1, 2, 3});
  auto iter1 = a.cbegin();
  auto iter2 = b.cbegin();
  ++iter1;
  ++iter2;
  ASSERT_EQ(*iter1, *iter2);
}

TEST(ConstIteratorSet, IncrBackwards) {
  const std::set<long> a({3, 2, 1});
  const s21::set<long> b({3, 2, 1});
  auto iter1 = a.cbegin();
  auto iter2 = b.cbegin();
  ++iter1;
  ++iter2;
  ASSERT_EQ(*iter1, *iter2);
}

TEST(ConstIteratorSet, IncrLastElem) {
  const s21::set<long> b({1, 2, 3});
  auto iter2 = b.cbegin();
  ++iter2;
  ++iter2;
  ++iter2;
  ASSERT_EQ(*iter2, *b.cend());
}

TEST(ConstIteratorSet, Decr1) {
  const std::set<long> a({1, 2, 3});
  const s21::set<long> b({1, 2, 3});
  auto iter1 = a.cbegin();
  auto iter2 = b.cbegin();
  ++iter1;
  --iter1;
  ++iter2;
  --iter2;
  ASSERT_EQ(*iter1, *iter2);
}

TEST(ConstIteratorSet, Decr2) {
  const std::set<long> a({1, 2, 3, 4, 5});
  const s21::set<long> b({1, 2, 3, 4, 5});
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

TEST(ConstIteratorSet, DecrFirstElement) {
  const s21::set<long> b({1, 2, 3});
  auto iter2 = b.cbegin();
  --iter2;
  ASSERT_EQ(*iter2, *b.cbegin());
}

TEST(ConstIteratorSet, End) {
  const s21::set<long> b({1, 2, 3});
  ASSERT_EQ(*b.cend(), long());
}

TEST(ConstIteratorSet, BeginEmpty) {
  const s21::set<int> b;
  ASSERT_EQ(*b.cbegin(), *b.cend());
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

TEST(CapacitySet, MaxSize) {
  std::set<char> a({'a'});
  s21::set<char> b({'a'});
  ASSERT_EQ(a.max_size(), b.max_size());
}

TEST(ModifiersSet, Clear) {
  std::set<char> a({'a', 'b', 'c'});
  s21::set<char> b({'a', 'b', 'c'});
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

TEST(ModifiersSet, InsertNotUnique) {
  std::set<int> a({1, 1, 1, 1, 2});
  s21::set<int> b({1, 1, 1, 1, 2});
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
  ASSERT_EQ(*res1.first, *res2.first);
  ASSERT_EQ(res1.second, res2.second);
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

TEST(ModifiersSet, InsertManyRightLeft) {
  std::set<int> a({1, 2, 3});
  s21::set<int> b({1, 2, 3});
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
  ASSERT_EQ(*res1.first, *res2.first);
  ASSERT_EQ(res1.second, res2.second);
}

TEST(ModifiersSet, InsertMany) {
  std::set<int> exp({1, 2, 3, 4});
  s21::set<int> b({1});
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
      {1, false}, {2, true}, {3, true}, {4, true}};
  ASSERT_EQ(res2.size(), exp_res.size());
  for (size_t i = 0; i != exp_res.size(); ++i) {
    ASSERT_EQ(*(res2[i].first), exp_res[i].first);
    ASSERT_EQ(res2[i].second, exp_res[i].second);
  }
}

TEST(ModifiersSet, RightSmall) {
  std::set<int> a({19, 15});
  s21::set<int> b({19, 15});
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
  ASSERT_EQ(*res1.first, *res2.first);
  ASSERT_EQ(res1.second, res2.second);
}

TEST(ModifiersSet, LeftBig) {
  std::set<int> a({1, 5, 10, 15, 11, 18, 16, 23});
  s21::set<int> b({1, 5, 10, 15, 11, 18, 16, 23});
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
  ASSERT_EQ(*res1.first, *res2.first);
  ASSERT_EQ(res1.second, res2.second);
}

TEST(ModifiersSet, RightBig) {
  std::set<int> a({23, 16, 18, 11, 15, 10, 5, 1});
  s21::set<int> b({23, 16, 18, 11, 15, 10, 5, 1});
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
  ASSERT_EQ(*res1.first, *res2.first);
  ASSERT_EQ(res1.second, res2.second);
}

TEST(ModifiersSet, EraseOneElem) {
  std::set<int> a({1});
  s21::set<int> b({1});
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

TEST(ModifiersSet, EraseTwoElem) {
  std::set<int> a({1, 2});
  s21::set<int> b({1, 2});
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

TEST(ModifiersSet, EraseTwoElem2) {
  std::set<int> a({1, 2});
  s21::set<int> b({1, 2});
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

TEST(ModifiersSet, EraseThreeElem) {
  std::set<int> a({1, 2, 3});
  s21::set<int> b({1, 2, 3});
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

TEST(ModifiersSet, EraseThreeElem2) {
  std::set<int> a({1, 2, 3});
  s21::set<int> b({1, 2, 3});
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

TEST(ModifiersSet, EraseThreeElem3) {
  std::set<int> a({1, 2, 3});
  s21::set<int> b({1, 2, 3});
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

TEST(ModifiersSet, EraseBegin) {
  std::set<int> a({1, 2, 3, 4, 5, 6, 7});
  s21::set<int> b({1, 2, 3, 4, 5, 6, 7});
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

TEST(ModifiersSet, EraseSecondElem) {
  std::set<int> a({1, 2, 3, 4, 5, 6, 7});
  s21::set<int> b({1, 2, 3, 4, 5, 6, 7});
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

TEST(ModifiersSet, EraseThirdElem) {
  std::set<int> a({1, 2, 3, 4, 5, 6, 7});
  s21::set<int> b({1, 2, 3, 4, 5, 6, 7});
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

TEST(ModifiersSet, EraseFourthElem) {
  std::set<int> a({1, 2, 3, 4, 5, 6, 7});
  s21::set<int> b({1, 2, 3, 4, 5, 6, 7});
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

TEST(ModifiersSet, EraseFifthElem) {
  std::set<int> a({1, 2, 3, 4, 5, 6, 7});
  s21::set<int> b({1, 2, 3, 4, 5, 6, 7});
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
TEST(ModifiersSet, EraseSixthElem) {
  std::set<int> a({1, 2, 3, 4, 5, 6, 7});
  s21::set<int> b({1, 2, 3, 4, 5, 6, 7});
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
TEST(ModifiersSet, EraseSeventhElem) {
  std::set<int> a({1, 2, 3, 4, 5, 6, 7});
  s21::set<int> b({1, 2, 3, 4, 5, 6, 7});
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

TEST(ModifiersSet, EraseEnd) {
  std::set<int> a({1, 2, 3});
  s21::set<int> b({1, 2, 3});
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

TEST(ModifiersSet, EraseMid) {
  std::set<int> a = {1, 2, 3};
  s21::set<int> b = {1, 2, 3};
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

TEST(ModifiersSet, SwapFromEmpty) {
  std::set<int> a({1, 2, 3});
  std::set<int> a1;
  s21::set<int> b({1, 2, 3});
  s21::set<int> b1;
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

TEST(ModifiersSet, SwapToEmpty) {
  std::set<int> a;
  std::set<int> a1({1, 2, 3});
  s21::set<int> b;
  s21::set<int> b1({1, 2, 3});
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

TEST(ModifiersSet, SwapEmpty) {
  std::set<int> a;
  std::set<int> a1;
  s21::set<int> b;
  s21::set<int> b1;
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

TEST(ModifiersSet, MergeThisSmaller) {
  std::set<int> a({1, 3, 5});
  std::set<int> a1({2, 3, 4, 7, 8});
  s21::set<int> b({1, 3, 5});
  s21::set<int> b1({2, 3, 4, 7, 8});
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

TEST(ModifiersSet, MergeOtherSmaller) {
  std::set<int> a({1, 3, 5, 9});
  std::set<int> a1({2, 3, 4, 7, 8});
  s21::set<int> b({1, 3, 5, 9});
  s21::set<int> b1({2, 3, 4, 7, 8});
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

TEST(ModifiersSet, MergeIntoEmpty) {
  std::set<int> a;
  std::set<int> a1({2, 3, 4, 7, 8});
  s21::set<int> b;
  s21::set<int> b1({2, 3, 4, 7, 8});
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

TEST(ModifiersSet, MergeFromEmpty) {
  std::set<int> a({2, 3, 4, 7, 8});
  std::set<int> a1;
  s21::set<int> b({2, 3, 4, 7, 8});
  s21::set<int> b1;
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