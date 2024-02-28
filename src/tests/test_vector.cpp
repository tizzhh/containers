#include <gtest/gtest.h>

#include <vector>

#include "../s21_containers.hpp"

TEST(ConstructorVector, Default) {
  try {
    s21::vector<int> a;
    SUCCEED();
  } catch (...) {
    FAIL() << "Default constructor fails";
  }
}

TEST(ConstructorVector, ParametrizedSizeN) {
  try {
    s21::vector<int> a(3);
    SUCCEED();
  } catch (...) {
    FAIL() << "Parametrized constructor fails";
  }
}

TEST(ConstructorVector, InitializerListOk) {
  try {
    s21::vector<int> a = {1, 2};
    SUCCEED();
  } catch (...) {
    FAIL() << "Initializer list constructor fails";
  }
}

TEST(ConstructorVector, CopyOk) {
  try {
    s21::vector<int> a = {1, 2};
    s21::vector<int> b = a;
    SUCCEED();
  } catch (...) {
    FAIL() << "Copy constructor fails";
  }
}

TEST(ConstructorVector, MoveOk) {
  try {
    s21::vector<int> a = {1, 2};
    s21::vector<int> b(std::move(a));
    SUCCEED();
  } catch (...) {
    FAIL() << "Move constructor fails";
  }
}

TEST(ConstructorVector, MoveOperOk) {
  try {
    s21::vector<int> a = {1, 2};
    s21::vector<int> b;
    b = std::move(a);
    SUCCEED();
  } catch (...) {
    FAIL() << "Move oper constructor fails";
  }
}

TEST(ElementAccessVector, AtOk) {
  std::vector<float> a = {1.0, 2.0};
  s21::vector<float> b = {1.0, 2.0};
  ASSERT_EQ(a.at(0), b.at(0));
  ASSERT_EQ(a.at(1), b.at(1));
}

TEST(ElementAccessVector, AtThrow) {
  s21::vector<float> b = {1.0, 2.0};
  ASSERT_ANY_THROW(b.at(-100));
  ASSERT_ANY_THROW(b.at(100));
}

TEST(ElementAccessVector, AtOperOk) {
  std::vector<float> a = {1.0, 2.0};
  s21::vector<float> b = {1.0, 2.0};
  ASSERT_EQ(a[0], b[0]);
  ASSERT_EQ(a[1], b[1]);
}

TEST(ElementAccessVector, AtOperNotThrow) {
  s21::vector<float> b = {1.0, 2.0};
  ASSERT_NO_THROW(b[-100]);
  ASSERT_NO_THROW(b[100]);
}

TEST(ConstElementAccessVector, AtOk) {
  const std::vector<float> a = {1.0, 2.0};
  const s21::vector<float> b = {1.0, 2.0};
  ASSERT_EQ(a.at(0), b.at(0));
  ASSERT_EQ(a.at(1), b.at(1));
}

TEST(ConstElementAccessVector, AtThrow) {
  const s21::vector<float> b = {1.0, 2.0};
  ASSERT_ANY_THROW(b.at(-100));
  ASSERT_ANY_THROW(b.at(100));
}

TEST(ConstElementAccessVector, AtOperOk) {
  const std::vector<float> a = {1.0, 2.0};
  const s21::vector<float> b = {1.0, 2.0};
  ASSERT_EQ(a[0], b[0]);
  ASSERT_EQ(a[1], b[1]);
}

TEST(ConstElementAccessVector, AtOperNotThrow) {
  const s21::vector<float> b = {1.0, 2.0};
  ASSERT_NO_THROW(b[-100]);
  ASSERT_NO_THROW(b[100]);
}

TEST(ElementAccessVector, Front) {
  std::vector<long> a = {1, 2};
  s21::vector<long> b = {1, 2};
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.front(), b.front());
}

TEST(ElementAccessVector, Back) {
  std::vector<long> a = {1, 2};
  s21::vector<long> b = {1, 2};
  ASSERT_EQ(a.back(), b.back());
  ASSERT_EQ(a.back(), b.back());
}

TEST(ElementAccessVector, Data) {
  std::vector<char> a = {'a', 'b', 'c'};
  s21::vector<char> b = {'a', 'b', 'c'};
  auto iter_a = a.data();
  auto iter_b = b.data();
  ASSERT_EQ(a.size(), b.size());
  for (size_t i = 0; i != a.size(); ++i) {
    ASSERT_EQ(*iter_a++, *iter_b++);
  }
}

TEST(ConstElementAccessVector, Front) {
  const std::vector<long> a = {1, 2};
  const s21::vector<long> b = {1, 2};
  ASSERT_EQ(a.front(), b.front());
  ASSERT_EQ(a.front(), b.front());
}

TEST(ConstElementAccessVector, Back) {
  const std::vector<long> a = {1, 2};
  const s21::vector<long> b = {1, 2};
  ASSERT_EQ(a.back(), b.back());
  ASSERT_EQ(a.back(), b.back());
}

TEST(ConstElementAccessVector, Data) {
  const std::vector<char> a = {'a', 'b', 'c'};
  const s21::vector<char> b = {'a', 'b', 'c'};
  auto iter_a = a.data();
  auto iter_b = b.data();
  ASSERT_EQ(a.size(), b.size());
  for (size_t i = 0; i != a.size(); ++i) {
    ASSERT_EQ(*iter_a++, *iter_b++);
  }
}

TEST(IteratorsVector, Begin) {
  std::vector<char> a = {'a', 'b', 'c'};
  s21::vector<char> b = {'a', 'b', 'c'};
  auto iter_a = a.begin();
  auto iter_b = b.begin();
  for (; iter_a != a.end();) {
    ASSERT_EQ(*iter_a++, *iter_b++);
  }
}

TEST(IteratorsVector, End) {
  std::vector<char> a = {'a', 'b', 'c'};
  s21::vector<char> b = {'a', 'b', 'c'};
  auto iter_a = a.end();
  auto iter_b = b.end();
  for (; iter_a != a.end();) {
    ASSERT_EQ(*iter_a++, *iter_b++);
  }
}

TEST(CapacityVector, EmptyTrue) {
  std::vector<int> a;
  s21::vector<int> b;
  ASSERT_EQ(a.empty(), b.empty());
}

TEST(CapacityVector, EmptyFalse) {
  std::vector<int> a = {1, 2, 3};
  s21::vector<int> b = {1, 2, 3};
  ASSERT_EQ(a.empty(), b.empty());
}

TEST(CapacityVector, Size0) {
  std::vector<int> a;
  s21::vector<int> b;
  ASSERT_EQ(a.size(), b.size());
}

TEST(CapacityVector, Size5WithParamConstructor) {
  std::vector<int> a(5);
  s21::vector<int> b(5);
  ASSERT_EQ(a.size(), b.size());
}

TEST(CapacityVector, Size5) {
  std::vector<int> a = {1, 2, 3};
  s21::vector<int> b = {1, 2, 3};
  ASSERT_EQ(a.size(), b.size());
}

TEST(CapacityVector, MaxSize) {
  std::vector<int> a;
  s21::vector<int> b;
  ASSERT_EQ(a.max_size(), b.max_size());
}

TEST(CapacityVector, Reserve) {
  std::vector<int> a;
  s21::vector<int> b;
  a.reserve(25);
  b.reserve(25);
  ASSERT_EQ(a.capacity(), b.capacity());
}

TEST(CapacityVector, ReserveLow) {
  std::vector<int> a(3);
  s21::vector<int> b(3);
  a.reserve(1);
  b.reserve(1);
  ASSERT_EQ(a.capacity(), b.capacity());
}

TEST(CapacityVector, Capacity) {
  std::vector<int> a(3);
  s21::vector<int> b(3);
  ASSERT_EQ(a.capacity(), b.capacity());
}

TEST(CapacityVector, ShrinkToFit) {
  std::vector<int> a = {1, 2, 3};
  s21::vector<int> b = {1, 2, 3};
  a.reserve(10);
  b.reserve(10);
  a.shrink_to_fit();
  b.shrink_to_fit();
  ASSERT_EQ(a.capacity(), b.capacity());
  ASSERT_EQ(a.size(), b.size());
}

TEST(CapacityVector, Resize) {
  std::vector<int> a = {1, 2, 3};
  s21::vector<int> b = {1, 2, 3};
  a.resize(10);
  b.resize(10);
  ASSERT_EQ(a.capacity(), b.capacity());
  ASSERT_EQ(a.size(), b.size());
}

TEST(ModifiersVector, Clear) {
  std::vector<float> a = {1.0, 2.0, 3.0};
  s21::vector<float> b = {1.0, 2.0, 3.0};
  a.clear();
  b.clear();
  ASSERT_EQ(a.capacity(), b.capacity());
  ASSERT_EQ(a.size(), b.size());
  for (size_t i = 0; i != a.capacity(); ++i) {
    ASSERT_EQ(a[i], b[i]);
  }
}

TEST(ModifiersVector, Insert) {
  std::vector<float> a = {1.0, 2.0, 3.0};
  s21::vector<float> b = {1.0, 2.0, 3.0};
  auto iter_a = a.begin();
  auto iter_b = b.begin();
  a.insert(iter_a, 500);
  b.insert(iter_b, 500);
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.capacity(), b.capacity());
  for (size_t i = 0; i != a.size(); ++i) {
    ASSERT_EQ(a[i], b[i]);
  }
}

TEST(ModifiersVector, InsertManyBegin) {
  s21::vector<int> a({1, 2, 3});
  s21::vector<int> b({10, 11, 12, 1, 2, 3});
  a.insert_many(a.begin(), 10, 11, 12);
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

TEST(ModifiersVector, InsertManyEnd) {
  s21::vector<int> a({1, 2, 3});
  s21::vector<int> b({1, 2, 3, 10, 11, 12});
  a.insert_many(a.end(), 10, 11, 12);
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

TEST(ModifiersVector, InsertManyMid) {
  s21::vector<int> a({1, 2, 3, 4});
  s21::vector<int> b({1, 2, 10, 11, 12, 3, 4});
  auto iter = a.begin();
  ++iter;
  ++iter;
  a.insert_many(iter, 10, 11, 12);
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

TEST(ModifiersVector, InsertManyBack) {
  s21::vector<int> a({1, 2, 3});
  s21::vector<int> b({1, 2, 3, 10, 11, 12});
  a.insert_many_back(10, 11, 12);
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

TEST(ModifiersVector, InsertManyBackEmpty) {
  s21::vector<int> a;
  s21::vector<int> b({10, 11, 12});
  a.insert_many_back(10, 11, 12);
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

TEST(ModifiersVector, Erase) {
  std::vector<float> a = {1.0, 2.0, 3.0};
  s21::vector<float> b = {1.0, 2.0, 3.0};
  auto iter_a = a.begin();
  auto iter_b = b.begin();
  a.erase(iter_a);
  b.erase(iter_b);
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.capacity(), b.capacity());
  for (size_t i = 0; i != a.size(); ++i) {
    ASSERT_EQ(a[i], b[i]);
  }
}

TEST(ModifiersVector, PushBack) {
  std::vector<float> a = {1.0, 2.0, 3.0};
  s21::vector<float> b = {1.0, 2.0, 3.0};
  a.push_back(5.0);
  b.push_back(5.0);
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.capacity(), b.capacity());
  for (size_t i = 0; i != a.size(); ++i) {
    ASSERT_EQ(a[i], b[i]);
  }
}

TEST(ModifiersVector, PopBack) {
  std::vector<float> a = {1.0, 2.0, 3.0};
  s21::vector<float> b = {1.0, 2.0, 3.0};
  a.pop_back();
  b.pop_back();
  ASSERT_EQ(a.size(), b.size());
  ASSERT_EQ(a.capacity(), b.capacity());
  for (size_t i = 0; i != a.size(); ++i) {
    ASSERT_EQ(a[i], b[i]);
  }
}

TEST(ModifiersVector, Swap) {
  std::vector<float> a = {1.0, 2.0, 3.0};
  std::vector<float> b = {4.0, 5.0, 6.0};
  s21::vector<float> c = {1.0, 2.0, 3.0};
  s21::vector<float> d = {4.0, 5.0, 6.0};
  a.swap(b);
  c.swap(d);
  ASSERT_EQ(a.size(), c.size());
  ASSERT_EQ(a.capacity(), c.capacity());
  ASSERT_EQ(b.size(), d.size());
  ASSERT_EQ(b.capacity(), d.capacity());
  for (size_t i = 0; i != a.size(); ++i) {
    ASSERT_EQ(a[i], c[i]);
  }
  for (size_t i = 0; i != b.size(); ++i) {
    ASSERT_EQ(b[i], d[i]);
  }
}
