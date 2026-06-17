#include <bits/stdc++.h>

// solve https://godbolt.org/z/WfnK415dE

int main() {
    constexpr auto selected = select_top<3>(Nums<10, 9, 8, 7, 11>{});
    for (const int& n : selected) {
        std::cout << n << " "; // 11 10 9
    } 
}