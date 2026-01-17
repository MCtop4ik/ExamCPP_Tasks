#include <iostream>
#include <cassert>

#include <bit_arr.hpp>
// class Bit11Array; // std deprecated

using namespace exame1_1;

int main() {
    auto pr = [](const Bit11Array& val) {
        for (int i = 0; i < 16; ++i) {
            std::cout << val[i] << ' ';
            if (i == 7)
                std::cout << "| ";
        }
        std::cout << std::endl;
    };



    // Bit11Array test;
    // test[10] = 1;

    // pr(test);

    // Bit11Array test2 = !test;
    // pr(test2);


    constinit static Bit11Array a;
    assert(sizeof(a) <= 2); 
    a[0] = 1;
    *(a + 3) = 1;
    a[10] = 1;

    std::cout << a[0]; // 1
    std::cout << std::endl;

    std::cout << a[1]; // 0
    std::cout << std::endl;

    std::cout << a; // 1 0 0 0 0 0 0 0 0 0 1
    std::cout << std::endl;

    
    Bit11Array a2 = !a;

    std::cout << a2; // 0 1 1 1 1 1 1 1 1 1 0
    std::cout << std::endl;


    Bit11Array a3 = !a;

}
