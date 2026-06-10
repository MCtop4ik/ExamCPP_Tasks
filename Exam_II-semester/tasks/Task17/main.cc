// ИСХОДНО таска на 20
// НО если делать сравнение с помощью tag dispatch idiom или sfinae это таска на 30

int main() {
    //constexpr function deprecated 
    ordered_print<5, 3, 4, 1, 2>(); // 1 2 3 4 5

}