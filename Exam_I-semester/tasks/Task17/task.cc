// #include <cstdint>
// #include <cassert>
// #include <iostream> 

// // перевести строку в число, std запрещен
// int main() {
//     const char* number = "-1_231_231_239";
//     int64_t value = get_number(number);
//     std::cout << value;
//     assert(value == -1231231239);
// }

#include <iostream>

int main() {
    int* a = new int(2);
    delete a;
    std::cout << *(a + 100000);
}