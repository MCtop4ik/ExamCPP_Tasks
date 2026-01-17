#include <iostream>

class IntArray;

int main() {
    IntArray a(3, 0);
    std::cout << a; // 0 0 0
    a = 1 + a + 2;
    
}
