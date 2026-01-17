// След код должен компилироваться и выводить в консоль вывода то,
// что записано в комментарии к соотв строке
// std запрещен
int main() {
    Queue q;

    q = q + 1;
    q = q + 2;

    std::cout << q << std::endl;  // 1 2

    q = 0 + q;

    std::cout << q << std::endl;  // 0 1 2

    q--;
    std::cout << q << std::endl;  // 0 1

    --q;
    std::cout << q << std::endl;  // 1
}