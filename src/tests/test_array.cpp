#include <gtest/gtest.h>

#include <array>

#include "../s21_containersplus.hpp"

TEST(ConstructorArray, Default) {
  try {
    s21::array<int, 0> b;
    SUCCEED();
  } catch (...) {
    FAIL() << "Default constructor fails";
  }
}

TEST(ConstructorArray, InitializerListOk) {
  try {
    s21::array<int, 2> b = {1, 2};
    SUCCEED();
    b[0] = 3;
  } catch (...) {
    FAIL() << "Initializer list constructor fails";
  }
}

TEST(ConstructorArray, InitializerListFillWithZerorsOk) {
  try {
    s21::array<int, 5> b = {1, 2};
    SUCCEED();
    b[0] = 3;
  } catch (...) {
    FAIL() << "Initializer list constructor fails";
  }
}

TEST(ConstructorArray, InitializerList2Ok) {
  try {
    s21::array<int, 2> b;
    b = {1, 2};
    SUCCEED();
  } catch (...) {
    FAIL() << "Initializer list constructor fails";
  }
}

TEST(ConstructorArray, InitializerListThrow) {
  try {
    s21::array<int, 0> b = {1, 2};
    FAIL() << "Doesn't throw";
  } catch (...) {
    SUCCEED();
  }
}

TEST(ConstructorArray, CopyOk) {
  try {
    s21::array<float, 2> a = {1.0, 2.0};
    s21::array<float, 2> b = a;
  } catch (...) {
    FAIL() << "Copy constructor fails";
  }
}

TEST(ConstructorArray, CopyException) {
  try {
    s21::array<float, 2> a = {1.0, 2.0, 3.0};
    FAIL() << "Copy constructor fails";
  } catch (...) {
    SUCCEED();
  }
}
// Мне буквально скомпилить не дает, так что хз чет как это протестить
// TEST(ConstructorArray, CopyFail) {
//     try {
//         std::array<float, 2> a ={1.0, 2.0};
//         std::array<float, 2> b = a;
//         b[0] = 1.0;
//         FAIL() << "Copy constructor doesn't fail";
//     } catch (...) {
//         SUCCEED();
//     }
// }

TEST(ConstructorArray, MoveOk) {
  try {
    s21::array<long, 2> a = {1, 2};
    s21::array<long, 2> b(std::move(a));
    SUCCEED();
  } catch (...) {
    FAIL() << "Move constructor fails";
  }
}

TEST(ConstructorArray, MoveLogic) {
  s21::array<int, 2> a = {1, 2};
  s21::array<int, 2> b(std::move(a));
  std::array<int, 2> c = {1, 2};
  std::array<int, 2> d(std::move(c));
  ASSERT_EQ(a[0], c[0]);
  ASSERT_EQ(a[1], c[1]);
  ASSERT_EQ(a.size(), c.size());
  ASSERT_EQ(a.max_size(), c.max_size());
  ASSERT_EQ(b[0], d[0]);
  ASSERT_EQ(b[1], d[1]);
  ASSERT_EQ(b.size(), d.size());
  ASSERT_EQ(b.max_size(), d.max_size());
}

// такая же тема, что и с копи
// TEST(ConstructorArray, MoveThrow) {
//     try {
//         std::array<int, 2> a ={1, 2};
//         std::array<int, 2> b(std::move(a));
//         FAIL() << "Move constructor doesn't fail";
//     } catch (...) {
//         SUCCEED();
//     }
// }

TEST(ConstructorArray, MoveOperOk) {
  try {
    s21::array<long, 2> a = {1, 2};
    s21::array<long, 2> b;
    b = std::move(a);
    SUCCEED();
  } catch (...) {
    FAIL() << "Move constructor fails";
  }
}

TEST(ConstructorArray, MoveOperLogic) {
  s21::array<int, 2> a = {1, 2};
  s21::array<int, 2> b = std::move(a);
  std::array<int, 2> c = {1, 2};
  std::array<int, 2> d = std::move(c);
  ASSERT_EQ(a[0], c[0]);
  ASSERT_EQ(a[1], c[1]);
  ASSERT_EQ(a.size(), c.size());
  ASSERT_EQ(a.max_size(), c.max_size());
  ASSERT_EQ(b[0], d[0]);
  ASSERT_EQ(b[1], d[1]);
  ASSERT_EQ(b.size(), d.size());
  ASSERT_EQ(b.max_size(), d.max_size());
}

// опять не компил ;(
// TEST(ConstructorArray, MoveOperFail) {
//     try {
//         s21::array<long, 2> a ={1, 2};
//         s21::array<long, 0> b = std::move(a);
//         FAIL() << "Move oper constructor doesn't fail";
//     } catch (...) {
//         SUCCEED();
//     }
// }

TEST(ElementAccessArray, AtOk) {
  std::array<int, 2> a = {1, 2};
  s21::array<int, 2> b = {1, 2};
  ASSERT_EQ(a.at(0), b.at(0));
  ASSERT_EQ(a.at(1), b.at(1));
}

TEST(ElementAccessArray, AtThrow) {
  try {
    s21::array<int, 2> a = {1, 2};
    a.at(100);
    FAIL() << "array::at";
  } catch (...) {
    SUCCEED();
  }
}

TEST(ElementAccessArray, AtConstThrow) {
  try {
    const s21::array<int, 2> a = {1, 2};
    a.at(100);
    FAIL() << "array::at";
  } catch (...) {
    SUCCEED();
  }
}

TEST(ElementAccessArray, OperAtOk) {
  std::array<int, 2> a = {1, 2};
  s21::array<int, 2> b = {1, 2};
  ASSERT_EQ(a[0], b[0]);
  ASSERT_EQ(a[1], b[1]);
}

TEST(ConstElementAccessArray, AtOk) {
  const std::array<int, 2> a = {1, 2};
  const s21::array<int, 2> b = {1, 2};
  ASSERT_EQ(a.at(0), b.at(0));
  ASSERT_EQ(a.at(1), b.at(1));
}

TEST(ConstElementAccessArray, AtThrow) {
  const std::array<int, 2> a = {1, 2};
  ASSERT_ANY_THROW(a.at(100));
}

TEST(ConstElementAccessArray, OperAtOk) {
  const std::array<int, 2> a = {1, 2};
  const s21::array<int, 2> b = {1, 2};
  ASSERT_EQ(a[0], b[0]);
  ASSERT_EQ(a[1], b[1]);
}

// TEST(ElementAccessArray, OperAtThrow) {  DEFAULT STD::ARRAY THROW UB
// (-13112412412, 21421321, 132321.. )
//   std::array<int, 2> a = {1, 2};
//   ASSERT_ANY_THROW(a[-100]);
//   ASSERT_ANY_THROW(a[100]);
// }

TEST(ElementAccessArray, Front) {
  std::array<int, 2> a = {1, 2};
  s21::array<int, 2> b = {1, 2};
  ASSERT_EQ(a.front(), b.front());
}

TEST(ElementAccessArray, Back) {
  std::array<int, 2> a = {1, 2};
  s21::array<int, 2> b = {1, 2};
  ASSERT_EQ(a.back(), b.back());
}

TEST(ElementAccessArray, Data) {
  std::array<char, 5> a = {'a', 'b', 'c', 'd', 'e'};
  s21::array<char, 5> b = {'a', 'b', 'c', 'd', 'e'};
  auto iter_a = a.data();
  auto iter_b = b.data();
  ASSERT_EQ(a.size(), b.size());
  for (size_t i = 0; i != a.size(); ++i) {
    ASSERT_EQ(*iter_a++, *iter_b++);
  }
}

TEST(ConstElementAccessArray, Front) {
  const std::array<int, 2> a = {1, 2};
  const s21::array<int, 2> b = {1, 2};
  ASSERT_EQ(a.front(), b.front());
}

TEST(ConstElementAccessArray, Back) {
  const std::array<int, 2> a = {1, 2};
  const s21::array<int, 2> b = {1, 2};
  ASSERT_EQ(a.back(), b.back());
}

TEST(ConstElementAccessArray, Data) {
  const std::array<char, 5> a = {'a', 'b', 'c', 'd', 'e'};
  const s21::array<char, 5> b = {'a', 'b', 'c', 'd', 'e'};
  auto iter_a = a.data();
  auto iter_b = b.data();
  ASSERT_EQ(a.size(), b.size());
  for (size_t i = 0; i != a.size(); ++i) {
    ASSERT_EQ(*iter_a++, *iter_b++);
  }
}

TEST(IteratorsArray, Begin) {
  std::array<int, 2> a = {1, 2};
  s21::array<int, 2> b = {1, 2};
  ASSERT_EQ(*a.begin(), *b.begin());
}

TEST(IteratorsArray, End) {
  std::array<char, 2> a = {'a', 'b'};
  s21::array<char, 2> b = {'a', 'b'};
  ASSERT_EQ(*(a.end() - 1), *(b.end() - 1));
}

TEST(IteratorsArray, CBegin) {
  std::array<int, 2> a = {1, 2};
  s21::array<int, 2> b = {1, 2};
  ASSERT_EQ(*a.cbegin(), *b.cbegin());
}

TEST(IteratorsArray, CEnd) {
  std::array<char, 2> a = {'a', 'b'};
  s21::array<char, 2> b = {'a', 'b'};
  ASSERT_EQ(*(a.cend() - 1), *(b.cend() - 1));
}

TEST(CapacityArray, EmptyTrue) {
  std::array<float, 0> a;
  s21::array<float, 0> b;
  ASSERT_EQ(a.empty(), b.empty());
}

TEST(CapacityArray, EmptyFalse) {
  std::array<long, 2> a = {1, 2};
  s21::array<long, 2> b = {1, 2};
  ASSERT_EQ(a.empty(), b.empty());
}

TEST(CapacityArray, Size0) {
  std::array<int, 0> a;
  s21::array<int, 0> b;
  ASSERT_EQ(a.size(), b.size());
}

TEST(CapacityArray, Size5) {
  std::array<char, 5> a = {'a', 'b', 'c', 'd', 'e'};
  s21::array<char, 5> b = {'a', 'b', 'c', 'd', 'e'};
  ASSERT_EQ(a.size(), b.size());
}

TEST(CapacityArray, Size2NotFull) {
  std::array<float, 5> a = {1.0, 2.0};
  s21::array<float, 5> b = {1.0, 2.0};
  ASSERT_EQ(a.size(), b.size());
}

TEST(CapacityArray, MaxSize0) {
  std::array<long, 0> a;
  s21::array<long, 0> b;
  ASSERT_EQ(a.size(), b.size());
}

TEST(CapacityArray, MaxSize10) {
  std::array<int, 10> a;
  s21::array<int, 10> b;
  ASSERT_EQ(a.size(), b.size());
}

TEST(ModifiersArray, Swap) {
  std::array<char, 5> a = {'a', 'b', 'c', 'd', 'e'};
  std::array<char, 5> b = {'e', 'f', 'g', 'h', 'i'};
  s21::array<char, 5> c = {'a', 'b', 'c', 'd', 'e'};
  s21::array<char, 5> d = {'e', 'f', 'g', 'h', 'i'};
  a.swap(b);
  c.swap(d);
  auto iter_a = a.data();
  auto iter_b = b.data();
  auto iter_c = c.data();
  auto iter_d = d.data();
  ASSERT_EQ(a.size(), c.size());
  ASSERT_EQ(b.size(), d.size());
  for (; iter_a != a.end();) {
    ASSERT_EQ(*iter_a++, *iter_c++);
  }
  for (; iter_b != b.end();) {
    ASSERT_EQ(*iter_b++, *iter_d++);
  }
}

TEST(ModifiersArray, Fill) {
  std::array<int, 3> a;
  s21::array<int, 3> b;
  a.fill(5);
  b.fill(5);
  auto iter_a = a.data();
  auto iter_b = b.data();
  ASSERT_EQ(a.size(), b.size());
  for (; iter_a != a.end();) {
    ASSERT_EQ(*iter_a++, *iter_b++);
  }
}
