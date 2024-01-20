#include <gtest/gtest.h>
#include <array>
#include "../s21_containerplus.hpp"

TEST(Constructor, Default) {
    try {
        s21::array<int, 0> b;
        SUCCEED();
    } catch (...) {
        FAIL() << "Default constructor fails";
    }
}

TEST(Constructor, InitializerListOk) {
    try {
        s21::array<int, 2> b = {1, 2};
        SUCCEED();
    } catch (...) {
        FAIL() << "Initializer list constructor fails";
    }
}

TEST(Constructor, InitializerListThrow) {
    try {
        s21::array<int, 0> b = {1, 2};
        FAIL() << "Doesn't throw";
    } catch (...) {
        SUCCEED();
    }
}

TEST(Constructor, CopyOk) {
    try {
        s21::array<float, 2> a ={1.0, 2.0};
        s21::array<float, 2> b = a;
    } catch (...) {
        FAIL() << "Copy constructor fails";
    }
}

// Мне буквально скомпилить не дает, так что хз чет как это протестить
// TEST(Constructor, CopyFail) {
//     try {
//         s21::array<float, 2> a ={1.0, 2.0};
//         s21::array<float, 0> b = a;
//         FAIL() << "Copy constructor doesn't fail";
//     } catch (...) {
//         SUCCEED();
//     }
// }

TEST(Constructor, MoveOk) {
    try {
        s21::array<long, 2> a ={1, 2};
        s21::array<long, 2> b(std::move(a));
        SUCCEED();
    } catch (...) {
        FAIL() << "Move constructor fails";
    }
}

TEST(Constructor, MoveLogic) {
    s21::array<int, 2> a ={1, 2};
    s21::array<int, 2> b(std::move(a));
    std::array<int, 2> c ={1, 2};
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
// TEST(Constructor, MoveThrow) {
//     try {
//         s21::array<int, 2> a ={1, 2};
//         s21::array<int, 0> b(std::move(a));
//         FAIL() << "Move constructor doesn't fail";
//     } catch (...) {
//         SUCCEED();
//     }
// }


TEST(Constructor, MoveOperOk) {
    try {
        s21::array<long, 2> a ={1, 2};
        s21::array<long, 2> b = std::move(a);
        SUCCEED();
    } catch (...) {
        FAIL() << "Move constructor fails";
    }
}

TEST(Constructor, MoveOperLogic) {
    s21::array<int, 2> a ={1, 2};
    s21::array<int, 2> b = std::move(a);
    std::array<int, 2> c ={1, 2};
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
// TEST(Constructor, MoveOperFail) {
//     try {
//         s21::array<long, 2> a ={1, 2};
//         s21::array<long, 0> b = std::move(a);
//         FAIL() << "Move oper constructor doesn't fail";
//     } catch (...) {
//         SUCCEED();
//     }
// }

TEST(ArrayElementAccess, AtOk) {
    std::array<int, 2> a= {1, 2};
    s21::array<int, 2> b= {1, 2};
    ASSERT_EQ(a.at(0), b.at(0));
    ASSERT_EQ(a.at(1), b.at(1));
}

TEST(ArrayElementAccess, AtThrow) {
    std::array<int, 2> a= {1, 2};
    ASSERT_ANY_THROW(a.at(-100));
    ASSERT_ANY_THROW(a.at(100));
}

TEST(ArrayElementAccess, OperAtOk) {
    std::array<int, 2> a= {1, 2};
    s21::array<int, 2> b= {1, 2};
    ASSERT_EQ(a[0], b[0]);
    ASSERT_EQ(a[1], b[1]);
}

TEST(ArrayElementAccess, OperAtThrow) {
    std::array<int, 2> a= {1, 2};
    ASSERT_ANY_THROW(a[-100]);
    ASSERT_ANY_THROW(a[100]);
}

TEST(ArrayElementAccess, Front) {
    std::array<int, 2> a= {1, 2};
    s21::array<int, 2> b= {1, 2};
    ASSERT_EQ(a.front(), b.front());
}

TEST(ArrayElementAccess, Back) {
    std::array<int, 2> a= {1, 2};
    s21::array<int, 2> b= {1, 2};
    ASSERT_EQ(a.back(), b.back());
}

TEST(ArrayElementAccess, Data) {
    std::array<char, 5> a = {'a', 'b', 'c', 'd', 'e'};
    s21::array<char, 5> b = {'a', 'b', 'c', 'd', 'e'};
    auto iter_a = a.data();
    auto iter_b = b.data();
    ASSERT_EQ(a.size(), b.size());
    for (size_t i = 0; i != a.size(); ++i) {
        ASSERT_EQ(*iter_a++, *iter_b++);
    }
}

TEST(ArrayIterators, Begin) {
    std::array<int, 2> a = {1, 2};
    s21::array<int, 2> b = {1, 2};
    ASSERT_EQ(*a.begin(), *b.begin());
}


TEST(ArrayIterators, End) {
    std::array<char, 2> a = {'a', 'b'};
    s21::array<char, 2> b = {'a', 'b'};
    ASSERT_EQ(*a.end(), *b.end());
}

TEST(ArrayCapacity, EmptyTrue) {
    std::array<float, 0> a;
    s21::array<float, 0> b;
    ASSERT_EQ(a.empty(), b.empty());
}

TEST(ArrayCapacity, EmptyFalse) {
    std::array<long, 2> a = {1, 2};
    s21::array<long, 2> b = {1, 2};
    ASSERT_EQ(a.empty(), b.empty());
}

TEST(ArrayCapacity, Size0) {
    std::array<int, 0> a;
    s21::array<int, 0> b;
    ASSERT_EQ(a.size(), b.size());
}

TEST(ArrayCapacity, Size5) {
    std::array<char, 5> a = {'a', 'b', 'c', 'd', 'e'};
    s21::array<char, 5> b = {'a', 'b', 'c', 'd', 'e'};
    ASSERT_EQ(a.size(), b.size());
}

TEST(ArrayCapacity, Size2NotFull) {
    std::array<float, 5> a = {1.0, 2.0};
    s21::array<float, 5> b = {1.0, 2.0};
    ASSERT_EQ(a.size(), b.size());
}

TEST(ArrayCapacity, MaxSize0) {
    std::array<long, 0> a;
    s21::array<long, 0> b;
    ASSERT_EQ(a.size(), b.size());
}

TEST(ArrayCapacity, MaxSize10) {
    std::array<int, 10> a;
    s21::array<int, 10> b;
    ASSERT_EQ(a.size(), b.size());
}

TEST(ArrayModifiers, Swap) {
    std::array<char, 5> a = {'a', 'b', 'c', 'd', 'e'};
    std::array<char, 5> b;
    s21::array<char, 5> c = {'a', 'b', 'c', 'd', 'e'};
    s21::array<char, 5> d;
    a.swap(b);
    c.swap(d);
    auto iter_a = a.data();
    auto iter_b = b.data();
    auto iter_c = c.data();
    auto iter_d = d.data();
    ASSERT_EQ(a.size(), c.size());
    ASSERT_EQ(b.size(), d.size());
    for (size_t i = 0; i != a.size(); ++i) {
        ASSERT_EQ(*iter_a++, *iter_c++);
    }
    for (size_t i = 0; i != b.size(); ++i) {
        ASSERT_EQ(*iter_b++, *iter_d++);
    }
}

TEST(ArrayModifiers, Fill) {
    std::array<int, 3> a;
    s21::array<int, 3> b;
    a.fill(5);
    b.fill(5);
    auto iter_a = a.data();
    auto iter_b = b.data();
    ASSERT_EQ(a.size(), b.size());
    for (size_t i = 0; i != a.size(); ++i) {
        ASSERT_EQ(*iter_a++, *iter_b++);
    }
}