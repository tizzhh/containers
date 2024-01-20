#include <iostream>
#include <array>

int main(void) {
    std::array <int, 3> b = {1, 2, 3};
    auto iter = b.data();
    for (int i = 0; i < b.size(); ++i) {
        std::cout << *iter++ << '\n';
    }
}