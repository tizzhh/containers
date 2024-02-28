#include <gtest/gtest.h>

#include <stack>

#include "../s21_containers.hpp"

TEST(ConstructorStack, Default) {
  try {
    s21::stack<int> a;
    SUCCEED();
  } catch (...) {
    FAIL() << "Default constructor fails";
  }
}

TEST(ConstructorStack, InitializerListOk) {
  try {
    s21::stack<int> a({1, 2});
    SUCCEED();
  } catch (...) {
    FAIL() << "Initializer list constructor fails";
  }
}

TEST(ConstructorStack, CopyOk) {
  try {
    s21::stack<int> a({1, 2});
    s21::stack<int> b = a;
    SUCCEED();
  } catch (...) {
    FAIL() << "Copy constructor fails";
  }
}

TEST(ConstructorStack, MoveOk) {
  try {
    s21::stack<int> a({1, 2});
    s21::stack<int> b(std::move(a));
    SUCCEED();
  } catch (...) {
    FAIL() << "Move constructor fails";
  }
}

TEST(ConstructorStack, MoveOperOk) {
  try {
    s21::stack<int> a({1, 2});
    s21::stack<int> b;
    b = std::move(a);
    SUCCEED();
  } catch (...) {
    FAIL() << "Move oper constructor fails";
  }
}

TEST(ElementAccessStack, Top) {
  std::stack<long> a({1, 2});
  s21::stack<long> b({1, 2});
  ASSERT_EQ(a.top(), b.top());
}

TEST(CapacityStack, EmptyTrue) {
  std::stack<int> a;
  s21::stack<int> b;
  ASSERT_EQ(a.empty(), b.empty());
}

TEST(CapacityStack, EmptyFalse) {
  std::stack<int> a({1, 2, 3});
  s21::stack<int> b({1, 2, 3});
  ASSERT_EQ(a.empty(), b.empty());
}

TEST(CapacityStack, Size0) {
  std::stack<int> a;
  s21::stack<int> b;
  ASSERT_EQ(a.size(), b.size());
}

TEST(CapacityStack, Size3) {
  std::stack<int> a({1, 2, 3});
  s21::stack<int> b({1, 2, 3});
  ASSERT_EQ(a.size(), b.size());
}

TEST(ModifiersStack, Push) {
  std::stack<char> a;
  s21::stack<char> b;
  a.push('a');
  a.push('b');
  b.push('a');
  b.push('b');
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.top(), b.top());
}

TEST(ModifiersStack, Pop) {
  std::stack<char> a({'a', 'b'});
  s21::stack<char> b({'a', 'b'});
  a.pop();
  b.pop();
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.top(), b.top());
}

TEST(ModifiersStack, SwapSameSizes) {
  std::stack<int> a({1, 2, 3});
  std::stack<int> b({4, 5, 6});
  s21::stack<int> c({1, 2, 3});
  s21::stack<int> d({4, 5, 6});
  a.swap(b);
  c.swap(d);
  ASSERT_EQ(a.size(), c.size());
  ASSERT_EQ(b.size(), d.size());
  ASSERT_EQ(a.empty(), c.empty());
  ASSERT_EQ(b.empty(), d.empty());
  ASSERT_EQ(a.top(), c.top());
  ASSERT_EQ(b.top(), d.top());
}

TEST(ModifiersStack, InsertManyFront) {
  s21::stack<int> a({1, 2, 3});
  s21::stack<int> b({1, 2, 3, 10, 11, 12});
  a.insert_many_front(10, 11, 12);
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.empty(), b.empty());
  ASSERT_EQ(a.top(), b.top());
}