#include <iostream>

class IntArray; // std deprecated

int main() {
    IntArray a(3, 0);
    std::cout << a; // 0 0 0
    a = 1 + a + 2;
    
    std::cout << a;

    a -= 0;

    std::cout << a;

    IntArray a2(2, 1);
    std::cout << a2;

    std::cout << a + a2;
}
