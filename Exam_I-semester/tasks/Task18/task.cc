#include <iostream>
int main() {
    IntSet s;
    s = 4 + 5 + s + 1 + 2 + 3;
    std::cout << s << std::endl;  // 1 2 3 4 5
    s = s + s;
    std::cout << s << std::endl;  // 1 2 3 4 5
    s = s - 2 - 3 - 4;
    std::cout << s << std::endl;  // 1 5
    IntSet s2;
    s2 = s2 + 3 + 4 + 5;
    std::cout << s + s2 << std::endl;  // 1 3 4 5
    std::cout << s - s2;  // 1
    return 0;
}