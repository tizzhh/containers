#include <gtest/gtest.h>

#include <queue>

#include "../s21_containers.hpp"

TEST(ConstructorQueue, Default) {
  try {
    s21::queue<int> a;
    SUCCEED();
  } catch (...) {
    FAIL() << "Default constructor fails";
  }
}

TEST(ConstructorQueue, InitializerListOk) {
  try {
    s21::queue<int> a({1, 2});
    SUCCEED();
  } catch (...) {
    FAIL() << "Initializer list constructor fails";
  }
}

TEST(ConstructorQueue, CopyOk) {
  try {
    s21::queue<int> a({1, 2});
    s21::queue<int> b = a;
    SUCCEED();
  } catch (...) {
    FAIL() << "Copy constructor fails";
  }
}

TEST(ConstructorQueue, MoveOk) {
  try {
    s21::queue<int> a({1, 2});
    s21::queue<int> b(std::move(a));
    SUCCEED();
  } catch (...) {
    FAIL() << "Move constructor fails";
  }
}

TEST(ConstructorQueue, MoveOperOk) {
  try {
    s21::queue<int> a({1, 2});
    s21::queue<int> b;
    b = std::move(a);
    SUCCEED();
  } catch (...) {
    FAIL() << "Move oper constructor fails";
  }
}

TEST(ElementAccessQueue, Front) {
  std::queue<long> a({1, 2});
  s21::queue<long> b({1, 2});
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.front(), b.front());
}

TEST(ElementAccessQueue, Back) {
  std::queue<long> a({1, 2});
  s21::queue<long> b({1, 2});
  ASSERT_EQ(a.back(), b.back());
  ASSERT_EQ(a.back(), b.back());
}

TEST(CapacityQueue, EmptyTrue) {
  std::queue<int> a;
  s21::queue<int> b;
  ASSERT_EQ(a.empty(), b.empty());
}

TEST(CapacityQueue, EmptyFalse) {
  std::queue<int> a({1, 2, 3});
  s21::queue<int> b({1, 2, 3});
  ASSERT_EQ(a.empty(), b.empty());
}

TEST(CapacityQueue, Size0) {
  std::queue<int> a;
  s21::queue<int> b;
  ASSERT_EQ(a.size(), b.size());
}

TEST(CapacityQueue, Size3) {
  std::queue<int> a({1, 2, 3});
  s21::queue<int> b({1, 2, 3});
  ASSERT_EQ(a.size(), b.size());
}

TEST(ModifiersQueue, Push) {
  std::queue<char> a;
  s21::queue<char> b;
  a.push('a');
  a.push('b');
  b.push('a');
  b.push('b');
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.back(), b.back());
}

TEST(ModifiersQueue, Pop) {
  std::queue<char> a({'a', 'b'});
  s21::queue<char> b({'a', 'b'});
  a.pop();
  b.pop();
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.back(), b.back());
}

TEST(ModifiersQueue, SwapSameSizes) {
  std::queue<int> a({1, 2, 3});
  std::queue<int> b({4, 5, 6});
  s21::queue<int> c({1, 2, 3});
  s21::queue<int> d({4, 5, 6});
  a.swap(b);
  c.swap(d);
  ASSERT_EQ(a.size(), c.size());
  ASSERT_EQ(b.size(), d.size());
  ASSERT_EQ(a.empty(), c.empty());
  ASSERT_EQ(b.empty(), d.empty());
  ASSERT_EQ(a.front(), c.front());
  ASSERT_EQ(a.back(), c.back());
  ASSERT_EQ(b.front(), d.front());
  ASSERT_EQ(b.back(), d.back());
}

TEST(ModifiersQueue, InsertManyBack) {
  s21::queue<int> a({1, 2, 3});
  s21::queue<int> b({1, 2, 3, 10, 11, 12});
  a.insert_many_back(10, 11, 12);
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.back(), b.back());
}