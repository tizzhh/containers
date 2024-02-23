#include "../../s21_containersplus.hpp"

int main(void) {
    s21::queue<int> a({1, 2});
    s21::queue<int> b(std::move(a));
}