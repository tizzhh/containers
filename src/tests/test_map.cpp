#include <gtest/gtest.h>

#include <map>

#include "../s21_containers.hpp"

TEST(ConstructorMap, Default) {
  try {
    s21::map<char, int> a;
    SUCCEED();
  } catch (...) {
    FAIL() << "Default constructor fails";
  }
}

TEST(ConstructorMap, InitializerListOk) {
  try {
    s21::map<char, int> a({{'a', 1}});
    SUCCEED();
  } catch (...) {
    FAIL() << "Initializer map constructor fails";
  }
}

TEST(ConstructorMap, CopyOk) {
  try {
    s21::map<char, int> a({{'a', 1}});
    s21::map<char, int> b = a;
    SUCCEED();
  } catch (...) {
    FAIL() << "Copy constructor fails";
  }
}

TEST(ConstructorMap, MoveOk) {
  try {
    s21::map<char, int> a({{'a', 1}});
    s21::map<char, int> b(std::move(a));
    SUCCEED();
  } catch (...) {
    FAIL() << "Move constructor fails";
  }
}

TEST(ConstructorMap, MoveOperOk) {
  try {
    s21::map<char, int> a({{'a', 1}});
    s21::map<char, int> b;
    b = std::move(a);
    SUCCEED();
  } catch (...) {
    FAIL() << "Move oper constructor fails";
  }
}

TEST(ElementAccessMap, At) {
  std::map<char, int> a({{'a', 1}});
  s21::map<char, int> b({{'a', 1}});
  ASSERT_EQ(a.at('a'), b.at('a'));
}

TEST(ElementAccessMap, AtException) {
  try {
    s21::map<char, int> b({{'a', 1}});
    b.at('b');
    FAIL() << "map::at";
  } catch (...) {
    SUCCEED();
  }
}

TEST(ElementAccessMap, AtChange) {
  std::map<char, int> a({{'a', 1}});
  s21::map<char, int> b({{'a', 1}});
  a.at('a') = 5;
  b.at('a') = 5;
  ASSERT_EQ(a.at('a'), b.at('a'));
}

TEST(ElementAccessMap, ConstAt) {
  const std::map<char, int> a({{'a', 1}});
  const s21::map<char, int> b({{'a', 1}});
  ASSERT_EQ(a.at('a'), b.at('a'));
}

TEST(ElementAccessMap, ConstAtException) {
  try {
    const s21::map<char, int> b({{'a', 1}});
    b.at('b');
    FAIL() << "map::at";
  } catch (...) {
    SUCCEED();
  }
}

TEST(ElementAccessMap, AtOper) {
  std::map<char, int> a({{'a', 1}});
  s21::map<char, int> b({{'a', 1}});
  ASSERT_EQ(a['a'], b['a']);
}

TEST(ElementAccessMap, AtOperChange) {
  std::map<char, int> a({{'a', 1}});
  s21::map<char, int> b({{'a', 1}});
  a['a'] = 5;
  b['a'] = 5;
  ASSERT_EQ(a['a'], b['a']);
}

TEST(ElementAccessMap, ConstAtOper) {
  std::map<char, int> a({{'a', 1}});
  const s21::map<char, int> b({{'a', 1}});
  ASSERT_EQ(a['a'], b['a']);
}

TEST(IteratorMap, Begin) {
  std::map<char, long> a({{'a', 1}, {'b', 2}, {'c', 3}});
  s21::map<char, long> b({{'a', 1}, {'b', 2}, {'c', 3}});
  ASSERT_EQ(a.begin()->first, b.begin()->first);
  ASSERT_EQ(a.begin()->second, b.begin()->second);
}

TEST(IteratorMap, Eq) {
  std::map<char, long> a({{'a', 1}, {'b', 2}, {'c', 3}});
  std::map<char, long> a1({{'a', 1}, {'b', 2}, {'c', 3}});
  s21::map<char, long> b({{'a', 1}, {'b', 2}, {'c', 3}});
  s21::map<char, long> b1({{'a', 1}, {'b', 2}, {'c', 3}});
  ASSERT_EQ(a.begin() == a1.begin(), b.begin() == b1.begin());
}

TEST(IteratorMap, NotEq) {
  std::map<char, long> a({{'a', 1}, {'b', 2}, {'c', 3}});
  std::map<char, long> a1({{'a', 1}, {'b', 2}, {'c', 3}});
  s21::map<char, long> b({{'a', 1}, {'b', 2}, {'c', 3}});
  s21::map<char, long> b1({{'a', 1}, {'b', 2}, {'c', 3}});
  ASSERT_EQ(a.begin() != a1.begin(), b.begin() != b1.begin());
}

TEST(IteratorMap, Incr) {
  std::map<char, long> a({{'a', 1}, {'b', 2}, {'c', 3}});
  s21::map<char, long> b({{'a', 1}, {'b', 2}, {'c', 3}});
  auto iter1 = a.begin();
  auto iter2 = b.begin();
  ++iter1;
  ++iter2;
  ASSERT_EQ(iter1->first, iter2->first);
  ASSERT_EQ(iter1->second, iter2->second);
}

TEST(IteratorMap, IncrBackwards) {
  std::map<char, long> a({{'c', 3}, {'b', 2}, {'a', 1}});
  s21::map<char, long> b({{'c', 3}, {'b', 2}, {'a', 1}});
  auto iter1 = a.begin();
  auto iter2 = b.begin();
  ++iter1;
  ++iter2;
  ASSERT_EQ(iter1->first, iter2->first);
  ASSERT_EQ(iter1->second, iter2->second);
}

TEST(IteratorMap, IncrLastElem) {
  s21::map<char, long> b({{'a', 1}, {'b', 2}, {'c', 3}});
  auto iter2 = b.begin();
  ++iter2;
  ++iter2;
  ++iter2;
  ASSERT_EQ(iter2->first, b.end()->first);
  ASSERT_EQ(iter2->second, b.end()->second);
}

TEST(IteratorMap, Decr1) {
  std::map<char, long> a({{'a', 1}, {'b', 2}, {'c', 3}});
  s21::map<char, long> b({{'a', 1}, {'b', 2}, {'c', 3}});
  auto iter1 = a.begin();
  auto iter2 = b.begin();
  ++iter1;
  --iter1;
  ++iter2;
  --iter2;
  ASSERT_EQ(iter1->first, iter2->first);
  ASSERT_EQ(iter1->second, iter2->second);
}

TEST(IteratorMap, Decr2) {
  std::map<char, long> a({{'a', 1}, {'b', 2}, {'c', 3}, {'d', 4}, {'e', 5}});
  s21::map<char, long> b({{'a', 1}, {'b', 2}, {'c', 3}, {'d', 4}, {'e', 5}});
  auto iter1 = a.begin();
  auto iter2 = b.begin();
  ++iter1;
  ++iter1;
  --iter1;
  ++iter2;
  ++iter2;
  --iter2;
  ASSERT_EQ(iter1->first, iter2->first);
  ASSERT_EQ(iter1->second, iter2->second);
}

TEST(IteratorMap, DecrFirstElement) {
  s21::map<char, long> b({{'a', 1}, {'b', 2}, {'c', 3}});
  auto iter2 = b.begin();
  --iter2;
  ASSERT_EQ(iter2->first, b.begin()->first);
  ASSERT_EQ(iter2->second, b.begin()->second);
}

TEST(IteratorMap, End) {
  s21::map<char, long> b({{'a', 1}, {'b', 2}, {'c', 3}});
  ASSERT_EQ(b.end()->first, char());
  ASSERT_EQ(b.end()->second, long());
}

TEST(IteratorMap, BeginEmpty) {
  s21::map<char, long> b;
  ASSERT_EQ(b.begin()->first, b.end()->first);
  ASSERT_EQ(b.begin()->second, b.end()->second);
}

TEST(ConstIteratorMap, Begin) {
  const std::map<char, long> a({{'a', 1}, {'b', 2}, {'c', 3}});
  const s21::map<char, long> b({{'a', 1}, {'b', 2}, {'c', 3}});
  ASSERT_EQ(a.cbegin()->first, b.cbegin()->first);
  ASSERT_EQ(a.cbegin()->second, b.cbegin()->second);
}

TEST(ConstIteratorMap, Eq) {
  const std::map<char, long> a({{'a', 1}, {'b', 2}, {'c', 3}});
  const std::map<char, long> a1({{'a', 1}, {'b', 2}, {'c', 3}});
  const s21::map<char, long> b({{'a', 1}, {'b', 2}, {'c', 3}});
  const s21::map<char, long> b1({{'a', 1}, {'b', 2}, {'c', 3}});
  ASSERT_EQ(a.cbegin() == a1.cbegin(), b.cbegin() == b1.cbegin());
}

TEST(ConstIteratorMap, NotEq) {
  const std::map<char, long> a({{'a', 1}, {'b', 2}, {'c', 3}});
  const std::map<char, long> a1({{'a', 1}, {'b', 2}, {'c', 3}});
  const s21::map<char, long> b({{'a', 1}, {'b', 2}, {'c', 3}});
  const s21::map<char, long> b1({{'a', 1}, {'b', 2}, {'c', 3}});
  ASSERT_EQ(a.cbegin() != a1.cbegin(), b.cbegin() != b1.cbegin());
}

TEST(ConstIteratorMap, Incr) {
  const std::map<char, long> a({{'a', 1}, {'b', 2}, {'c', 3}});
  const s21::map<char, long> b({{'a', 1}, {'b', 2}, {'c', 3}});
  auto iter1 = a.cbegin();
  auto iter2 = b.cbegin();
  ++iter1;
  ++iter2;
  ASSERT_EQ(iter1->first, iter2->first);
  ASSERT_EQ(iter1->second, iter2->second);
}

TEST(ConstIteratorMap, IncrBackwards) {
  const std::map<char, long> a({{'c', 3}, {'b', 2}, {'a', 1}});
  const s21::map<char, long> b({{'c', 3}, {'b', 2}, {'a', 1}});
  auto iter1 = a.cbegin();
  auto iter2 = b.cbegin();
  ++iter1;
  ++iter2;
  ASSERT_EQ(iter1->first, iter2->first);
  ASSERT_EQ(iter1->second, iter2->second);
}

TEST(ConstIteratorMap, IncrLastElem) {
  const s21::map<char, long> b({{'a', 1}, {'b', 2}, {'c', 3}});
  auto iter2 = b.cbegin();
  ++iter2;
  ++iter2;
  ++iter2;
  ASSERT_EQ(iter2->first, b.cend()->first);
  ASSERT_EQ(iter2->second, b.cend()->second);
}

TEST(ConstIteratorMap, Decr1) {
  const std::map<char, long> a({{'a', 1}, {'b', 2}, {'c', 3}});
  const s21::map<char, long> b({{'a', 1}, {'b', 2}, {'c', 3}});
  auto iter1 = a.cbegin();
  auto iter2 = b.cbegin();
  ++iter1;
  --iter1;
  ++iter2;
  --iter2;
  ASSERT_EQ(iter1->first, iter2->first);
  ASSERT_EQ(iter1->second, iter2->second);
}

TEST(ConstIteratorMap, Decr2) {
  const std::map<char, long> a(
      {{'a', 1}, {'b', 2}, {'c', 3}, {'d', 4}, {'e', 5}});
  const s21::map<char, long> b(
      {{'a', 1}, {'b', 2}, {'c', 3}, {'d', 4}, {'e', 5}});
  auto iter1 = a.cbegin();
  auto iter2 = b.cbegin();
  ++iter1;
  ++iter1;
  --iter1;
  ++iter2;
  ++iter2;
  --iter2;
  ASSERT_EQ(iter1->first, iter2->first);
  ASSERT_EQ(iter1->second, iter2->second);
}

TEST(ConstIteratorMap, DecrFirstElement) {
  const s21::map<char, long> b({{'a', 1}, {'b', 2}, {'c', 3}});
  auto iter2 = b.cbegin();
  --iter2;
  ASSERT_EQ(iter2->first, b.cbegin()->first);
  ASSERT_EQ(iter2->second, b.cbegin()->second);
}

TEST(ConstIteratorMap, End) {
  const s21::map<char, long> b({{'a', 1}, {'b', 2}, {'c', 3}});
  ASSERT_EQ(b.cend()->first, char());
  ASSERT_EQ(b.cend()->second, long());
}

TEST(ConstIteratorMap, BeginEmpty) {
  const s21::map<char, long> b;
  ASSERT_EQ(b.cbegin()->first, b.cend()->first);
  ASSERT_EQ(b.cbegin()->second, b.cend()->second);
}

TEST(CapacityMap, EmptyTrue) {
  std::map<char, int> a;
  s21::map<char, int> b;
  ASSERT_EQ(a.empty(), b.empty());
}

TEST(CapacityMap, EmptyFalse) {
  std::map<char, int> a({{'a', 1}, {'b', 2}, {'c', 3}});
  s21::map<char, int> b({{'a', 1}, {'b', 2}, {'c', 3}});
  ASSERT_EQ(a.empty(), b.empty());
}

TEST(CapacityMap, Size0) {
  std::map<char, int> a;
  s21::map<char, int> b;
  ASSERT_EQ(a.size(), b.size());
}

TEST(CapacityMap, Size3) {
  std::map<char, char> a({{'a', 'a'}, {'b', 'b'}, {'c', 'c'}});
  s21::map<char, char> b({{'a', 'a'}, {'b', 'b'}, {'c', 'c'}});
  ASSERT_EQ(a.size(), b.size());
}

TEST(CapacityMap, MaxSize) {
  std::map<char, char> a({{'a', 'a'}, {'b', 'b'}});
  s21::map<char, char> b({{'a', 'a'}, {'b', 'b'}});
  ASSERT_EQ(a.max_size(), b.max_size());
}

TEST(ModifiersMap, Clear) {
  std::map<char, char> a({{'a', 'a'}, {'b', 'b'}, {'c', 'c'}});
  s21::map<char, char> b({{'a', 'a'}, {'b', 'b'}, {'c', 'c'}});
  a.clear();
  b.clear();
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(b.end()->first, char());
  ASSERT_EQ(b.end()->second, char());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(it1->first, it2->first);
    ASSERT_EQ(it1->second, it2->second);
  }
}

TEST(ModifiersMap, InsertNotUnique) {
  std::map<char, int> a({{'a', 1}, {'a', 1}, {'a', 1}, {'a', 1}, {'e', 5}});
  s21::map<char, int> b({{'a', 1}, {'a', 1}, {'a', 1}, {'a', 1}, {'e', 5}});
  auto res1 = a.insert({'e', 5});
  auto res2 = b.insert({'e', 5});
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(b.end()->first, char());
  ASSERT_EQ(b.end()->second, int());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(it1->first, it2->first);
    ASSERT_EQ(it1->second, it2->second);
  }
  ASSERT_EQ(res1.first->first, res2.first->first);
  ASSERT_EQ(res1.first->second, res2.first->second);
  ASSERT_EQ(res1.second, res2.second);
}

TEST(ModifiersMap, InsertRight) {
  std::map<char, int> a({{'a', 1}, {'b', 2}, {'c', 3}});
  s21::map<char, int> b({{'a', 1}, {'b', 2}, {'c', 3}});
  auto res1 = a.insert({'d', 4});
  auto res2 = b.insert({'d', 4});
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(b.end()->first, char());
  ASSERT_EQ(b.end()->second, int());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(it1->first, it2->first);
    ASSERT_EQ(it1->second, it2->second);
  }
  ASSERT_EQ(res1.first->first, res2.first->first);
  ASSERT_EQ(res1.first->second, res2.first->second);
  ASSERT_EQ(res1.second, res2.second);
}

TEST(ModifiersMap, InsertLeft) {
  std::map<char, int> a({{'b', 1}, {'c', 2}, {'d', 3}});
  s21::map<char, int> b({{'b', 1}, {'c', 2}, {'d', 3}});
  // std map doesn't have key, obj insert
  auto res1 = a.insert({'a', 0});
  auto res2 = b.insert('a', 0);
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(b.end()->first, char());
  ASSERT_EQ(b.end()->second, int());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(it1->first, it2->first);
    ASSERT_EQ(it1->second, it2->second);
  }
  ASSERT_EQ(res1.first->first, res2.first->first);
  ASSERT_EQ(res1.first->second, res2.first->second);
  ASSERT_EQ(res1.second, res2.second);
}

TEST(ModifiersMap, InsertOrAssign) {
  std::map<char, int> a({{'b', 1}, {'c', 2}, {'d', 3}});
  s21::map<char, int> b({{'b', 1}, {'c', 2}, {'d', 3}});
  a['b'] = 0;
  auto res2 = b.insert_or_assign('b', 0);
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(b.end()->first, char());
  ASSERT_EQ(b.end()->second, int());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(it1->first, it2->first);
    ASSERT_EQ(it1->second, it2->second);
  }
  ASSERT_EQ('b', res2.first->first);
  ASSERT_EQ(0, res2.first->second);
  ASSERT_EQ(true, res2.second);
}

TEST(ModifiersMap, InsertManyRightLeft) {
  std::map<long, int> a({{5, 1}, {6, 2}, {7, 3}});
  s21::map<long, int> b({{5, 1}, {6, 2}, {7, 3}});
  a.insert({4, 4});
  a.insert({5, 5});
  a.insert({6, 6});
  a.insert({0, 0});
  a.insert({-1, -1});
  auto res1 = a.insert({-2, -2});
  b.insert({4, 4});
  b.insert({5, 5});
  b.insert({6, 6});
  b.insert({0, 0});
  b.insert({-1, -1});
  auto res2 = b.insert({-2, -2});
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(b.end()->first, char());
  ASSERT_EQ(b.end()->second, int());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(it1->first, it2->first);
    ASSERT_EQ(it1->second, it2->second);
  }
  ASSERT_EQ(res1.first->first, res2.first->first);
  ASSERT_EQ(res1.first->second, res2.first->second);
  ASSERT_EQ(res1.second, res2.second);
}

TEST(ModifiersMap, InsertMany) {
  std::map<long, int> exp({{1, 1}, {2, 2}, {3, 3}, {4, 4}});
  s21::map<long, int> b({{1, 1}});
  auto res2 = b.insert_many(std::make_pair(1, 1), std::make_pair(2, 2),
                            std::make_pair(3, 3), std::make_pair(4, 4));
  ASSERT_EQ(exp.size(), b.size());
  ASSERT_EQ(exp.empty(), b.empty());
  ASSERT_EQ(b.end()->first, long());
  ASSERT_EQ(b.end()->second, int());
  auto it1 = exp.begin();
  auto it2 = b.begin();
  for (; it1 != exp.end(); ++it1, ++it2) {
    ASSERT_EQ(it1->first, it2->first);
    ASSERT_EQ(it1->second, it2->second);
  }
  std::vector<std::pair<std::pair<int, int>, bool>> exp_res = {
      {{1, 1}, true}, {{2, 2}, true}, {{3, 3}, true}, {{4, 4}, true}};
  ASSERT_EQ(res2.size(), exp_res.size());
  for (size_t i = 0; i != exp_res.size(); ++i) {
    ASSERT_EQ(res2[i].first->first, exp_res[i].first.first);
    ASSERT_EQ(res2[i].first->second, exp_res[i].first.second);
    ASSERT_EQ(res2[i].second, exp_res[i].second);
  }
}

TEST(ModifiersMap, EraseBegin) {
  std::map<char, int> a(
      {{'a', 1}, {'b', 2}, {'c', 3}, {'d', 4}, {'e', 5}, {'f', 6}, {'g', 7}});
  s21::map<char, int> b(
      {{'a', 1}, {'b', 2}, {'c', 3}, {'d', 4}, {'e', 5}, {'f', 6}, {'g', 7}});
  auto it1 = a.begin();
  auto it2 = b.begin();
  a.erase(it1);
  b.erase(it2);
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(b.end()->first, char());
  ASSERT_EQ(b.end()->second, int());
  it1 = a.begin();
  it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(it1->first, it2->first);
    ASSERT_EQ(it1->second, it2->second);
  }
}

TEST(ModifiersMap, EraseSecondElem) {
  std::map<char, int> a(
      {{'a', 1}, {'b', 2}, {'c', 3}, {'d', 4}, {'e', 5}, {'f', 6}, {'g', 7}});
  s21::map<char, int> b(
      {{'a', 1}, {'b', 2}, {'c', 3}, {'d', 4}, {'e', 5}, {'f', 6}, {'g', 7}});
  auto it1 = a.begin();
  auto it2 = b.begin();
  ++it1;
  ++it2;
  a.erase(it1);
  b.erase(it2);
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(b.end()->first, char());
  ASSERT_EQ(b.end()->second, int());
  it1 = a.begin();
  it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(it1->first, it2->first);
    ASSERT_EQ(it1->second, it2->second);
  }
}

TEST(ModifiersMap, EraseThirdElem) {
  std::map<char, int> a(
      {{'a', 1}, {'b', 2}, {'c', 3}, {'d', 4}, {'e', 5}, {'f', 6}, {'g', 7}});
  s21::map<char, int> b(
      {{'a', 1}, {'b', 2}, {'c', 3}, {'d', 4}, {'e', 5}, {'f', 6}, {'g', 7}});
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
  ASSERT_EQ(b.end()->first, char());
  ASSERT_EQ(b.end()->second, int());
  it1 = a.begin();
  it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(it1->first, it2->first);
    ASSERT_EQ(it1->second, it2->second);
  }
}

TEST(ModifiersMap, EraseFourthElem) {
  std::map<char, int> a(
      {{'a', 1}, {'b', 2}, {'c', 3}, {'d', 4}, {'e', 5}, {'f', 6}, {'g', 7}});
  s21::map<char, int> b(
      {{'a', 1}, {'b', 2}, {'c', 3}, {'d', 4}, {'e', 5}, {'f', 6}, {'g', 7}});
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
  ASSERT_EQ(b.end()->first, char());
  ASSERT_EQ(b.end()->second, int());
  it1 = a.begin();
  it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(it1->first, it2->first);
    ASSERT_EQ(it1->second, it2->second);
  }
}

TEST(ModifiersMap, EraseFifthElem) {
  std::map<char, int> a(
      {{'a', 1}, {'b', 2}, {'c', 3}, {'d', 4}, {'e', 5}, {'f', 6}, {'g', 7}});
  s21::map<char, int> b(
      {{'a', 1}, {'b', 2}, {'c', 3}, {'d', 4}, {'e', 5}, {'f', 6}, {'g', 7}});
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
  ASSERT_EQ(b.end()->first, char());
  ASSERT_EQ(b.end()->second, int());
  it1 = a.begin();
  it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(it1->first, it2->first);
    ASSERT_EQ(it1->second, it2->second);
  }
}
TEST(ModifiersMap, EraseSixthElem) {
  std::map<char, int> a(
      {{'a', 1}, {'b', 2}, {'c', 3}, {'d', 4}, {'e', 5}, {'f', 6}, {'g', 7}});
  s21::map<char, int> b(
      {{'a', 1}, {'b', 2}, {'c', 3}, {'d', 4}, {'e', 5}, {'f', 6}, {'g', 7}});
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
  ASSERT_EQ(b.end()->first, char());
  ASSERT_EQ(b.end()->second, int());
  it1 = a.begin();
  it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(it1->first, it2->first);
    ASSERT_EQ(it1->second, it2->second);
  }
}
TEST(ModifiersMap, EraseSeventhElem) {
  std::map<char, int> a(
      {{'a', 1}, {'b', 2}, {'c', 3}, {'d', 4}, {'e', 5}, {'f', 6}, {'g', 7}});
  s21::map<char, int> b(
      {{'a', 1}, {'b', 2}, {'c', 3}, {'d', 4}, {'e', 5}, {'f', 6}, {'g', 7}});
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
  ASSERT_EQ(b.end()->first, char());
  ASSERT_EQ(b.end()->second, int());
  it1 = a.begin();
  it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(it1->first, it2->first);
    ASSERT_EQ(it1->second, it2->second);
  }
}

TEST(ModifiersMap, EraseEnd) {
  std::map<char, int> a({{'a', 1}, {'b', 2}, {'c', 3}});
  s21::map<char, int> b({{'a', 1}, {'b', 2}, {'c', 3}});
  b.erase(b.end());
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(b.end()->first, char());
  ASSERT_EQ(b.end()->second, int());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(it1->first, it2->first);
    ASSERT_EQ(it1->second, it2->second);
  }
}

TEST(ModifiersMap, EraseMid) {
  std::map<char, int> a = {{'a', 1}, {'b', 2}, {'c', 3}};
  s21::map<char, int> b = {{'a', 1}, {'b', 2}, {'c', 3}};
  auto it1 = a.begin();
  auto it2 = b.begin();
  ++it1;
  ++it2;
  a.erase(it1);
  b.erase(it2);
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(b.end()->first, char());
  ASSERT_EQ(b.end()->second, int());
  it1 = a.begin();
  it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(it1->first, it2->first);
    ASSERT_EQ(it1->second, it2->second);
  }
}

TEST(ModifiersMap, Swap) {
  std::map<char, int> a({{'a', 1}, {'b', 2}, {'c', 3}});
  std::map<char, int> a1({{'d', 4}, {'e', 5}, {'f', 6}});
  s21::map<char, int> b({{'a', 1}, {'b', 2}, {'c', 3}});
  s21::map<char, int> b1({{'d', 4}, {'e', 5}, {'f', 6}});
  a.swap(a1);
  b.swap(b1);
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a1.size(), b1.size());
  ASSERT_EQ(a1.empty(), b1.empty());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(it1->first, it2->first);
    ASSERT_EQ(it1->second, it2->second);
  }
  it1 = a1.begin();
  it2 = b1.begin();
  for (; it1 != a1.end(); ++it1, ++it2) {
    ASSERT_EQ(it1->first, it2->first);
    ASSERT_EQ(it1->second, it2->second);
  }
}

TEST(ModifiersMap, SwapFromEmpty) {
  std::map<char, int> a({{'a', 1}, {'b', 2}, {'c', 3}});
  std::map<char, int> a1;
  s21::map<char, int> b({{'a', 1}, {'b', 2}, {'c', 3}});
  s21::map<char, int> b1;
  a.swap(a1);
  b.swap(b1);
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a1.size(), b1.size());
  ASSERT_EQ(a1.empty(), b1.empty());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(it1->first, it2->first);
    ASSERT_EQ(it1->second, it2->second);
  }
  it1 = a1.begin();
  it2 = b1.begin();
  for (; it1 != a1.end(); ++it1, ++it2) {
    ASSERT_EQ(it1->first, it2->first);
    ASSERT_EQ(it1->second, it2->second);
  }
}

TEST(ModifiersMap, SwapToEmpty) {
  std::map<char, int> a;
  std::map<char, int> a1({{'a', 1}, {'b', 2}, {'c', 3}});
  s21::map<char, int> b;
  s21::map<char, int> b1({{'a', 1}, {'b', 2}, {'c', 3}});
  a.swap(a1);
  b.swap(b1);
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a1.size(), b1.size());
  ASSERT_EQ(a1.empty(), b1.empty());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(it1->first, it2->first);
    ASSERT_EQ(it1->second, it2->second);
  }
  it1 = a1.begin();
  it2 = b1.begin();
  for (; it1 != a1.end(); ++it1, ++it2) {
    ASSERT_EQ(it1->first, it2->first);
    ASSERT_EQ(it1->second, it2->second);
  }
}

TEST(ModifiersMap, SwapEmpty) {
  std::map<char, int> a;
  std::map<char, int> a1;
  s21::map<char, int> b;
  s21::map<char, int> b1;
  a.swap(a1);
  b.swap(b1);
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a1.size(), b1.size());
  ASSERT_EQ(a1.empty(), b1.empty());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(it1->first, it2->first);
    ASSERT_EQ(it1->second, it2->second);
  }
  it1 = a1.begin();
  it2 = b1.begin();
  for (; it1 != a1.end(); ++it1, ++it2) {
    ASSERT_EQ(it1->first, it2->first);
    ASSERT_EQ(it1->second, it2->second);
  }
}

TEST(ModifiersMap, MergeThisSmaller) {
  std::map<char, int> a({{'a', 1}, {'c', 3}, {'e', 5}});
  std::map<char, int> a1({{'b', 2}, {'c', 3}, {'d', 4}, {'g', 7}, {'h', 8}});
  s21::map<char, int> b({{'a', 1}, {'c', 3}, {'e', 5}});
  s21::map<char, int> b1({{'b', 2}, {'c', 3}, {'d', 4}, {'g', 7}, {'h', 8}});
  a.merge(a1);
  b.merge(b1);
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a1.size(), b1.size());
  ASSERT_EQ(a1.empty(), b1.empty());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(it1->first, it2->first);
    ASSERT_EQ(it1->second, it2->second);
  }
}

TEST(ModifiersMap, MergeOtherSmaller) {
  std::map<char, int> a({{'a', 1}, {'c', 3}, {'e', 5}, {'i', 9}});
  std::map<char, int> a1({{'b', 2}, {'c', 3}, {'d', 4}, {'g', 7}, {'h', 8}});
  s21::map<char, int> b({{'a', 1}, {'c', 3}, {'e', 5}, {'i', 9}});
  s21::map<char, int> b1({{'b', 2}, {'c', 3}, {'d', 4}, {'g', 7}, {'h', 8}});
  a.merge(a1);
  b.merge(b1);
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a1.size(), b1.size());
  ASSERT_EQ(a1.empty(), b1.empty());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(it1->first, it2->first);
    ASSERT_EQ(it1->second, it2->second);
  }
}

TEST(ModifiersMap, MergeIntoEmpty) {
  std::map<char, int> a;
  std::map<char, int> a1({{'b', 2}, {'c', 3}, {'d', 4}, {'g', 7}, {'h', 8}});
  s21::map<char, int> b;
  s21::map<char, int> b1({{'b', 2}, {'c', 3}, {'d', 4}, {'g', 7}, {'h', 8}});
  a.merge(a1);
  b.merge(b1);
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a1.size(), b1.size());
  ASSERT_EQ(a1.empty(), b1.empty());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(it1->first, it2->first);
    ASSERT_EQ(it1->second, it2->second);
  }
}

TEST(ModifiersMap, MergeFromEmpty) {
  std::map<char, int> a({{'b', 2}, {'c', 3}, {'d', 4}, {'g', 7}, {'h', 8}});
  std::map<char, int> a1;
  s21::map<char, int> b({{'b', 2}, {'c', 3}, {'d', 4}, {'g', 7}, {'h', 8}});
  s21::map<char, int> b1;
  a.merge(a1);
  b.merge(b1);
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a1.size(), b1.size());
  ASSERT_EQ(a1.empty(), b1.empty());
  auto it1 = a.begin();
  auto it2 = b.begin();
  for (; it1 != a.end(); ++it1, ++it2) {
    ASSERT_EQ(it1->first, it2->first);
    ASSERT_EQ(it1->second, it2->second);
  }
}

TEST(LookUpMap, ContainsTrue) {
  s21::map<char, int> b({{'a', 1}, {'b', 2}, {'c', 3}});
  ASSERT_EQ(true, b.contains('a'));
}

TEST(LookUpMap, ContainsFalse) {
  s21::map<char, int> b({{'a', 1}, {'b', 2}, {'c', 3}});
  ASSERT_EQ(false, b.contains(69));
}
