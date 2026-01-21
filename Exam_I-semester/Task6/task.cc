#include <iostream>




int main() {
    int a = 2;
    std::cout << (10 | minus(2) | div(4) | multiply(2)); // 4

    std::cout << (1 | plus(2)); // 3
}
