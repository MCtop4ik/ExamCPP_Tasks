// Следующий код должен компилироваться и выводить
// Work Exit Exit
// std запрещен

void exit1() {
    std::cout << " Exit\n"
}

void exit2() {
    std::cout << "Exit ";
}

int main() {
    call_after(exit1);
    call_after(exit2);
    std::cout << "Work ";
}