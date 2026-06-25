// ЗАДАЧА:
// Написать каррирующую функцию (каррирование - частичная подстановка аргуменов в функцию, порождающая новую, из другого множества отображения)
// аргументы произвользые по типу и уникальности
// неуникальные аргументы должны подставлться в порадке их объявления в сигнатуре функции
// функцией называем все что похоже на функцию: функция, функтор, лямбда
// функция не имеет шаблонных параметров
// std::println(smth) <=> std::cout << smth << std::endl

int main() {
    {
        // OUTPUT:
        //      a 3.4 1
        //      a 3.4 1
        //      a 3.4 1
        //      a 3.4 1
        //      a 3.4 1
        //      a 3.4 1
        //      a 3.4 1
        //      a 3.4 1
        //      a 3.4 1

        auto some_func = [](int a, double b, char c) {
            std::println("{} {} {}", a, b, c);
        };

        auto f1 = typed_carrier(some_func, 'a', 3.4, 1);
        auto f2 = typed_carrier(some_func, 1, 'a', 3.4);
        auto f3 = typed_carrier(some_func, 1, 3.4, 'a');
        auto f4 = typed_carrier(some_func, 3.4, 'a');
        auto f5 = typed_carrier(some_func, 1, 3.4);
        auto f6 = typed_carrier(some_func, 3.4);
        auto f7 = typed_carrier(some_func, 'a');
        auto f8 = typed_carrier(some_func, 1);

        std::invoke(f1);
        std::invoke(f2);
        std::invoke(f3);
        std::invoke(f4, 1);
        std::invoke(f5, 'a');
        std::invoke(f6, 1, 'a');
        std::invoke(f6, 'a', 1);
        std::invoke(f7, 3.4, 1);
        std::invoke(f8, 'a', 3.4);
        // std::invoke(f8, 'a'); CE   
        // std::invoke(f8, "bushido zho"); CE   
        // std::invoke(f8, 'a', 3.4, 3.4); CE   
    }

    {
        // OUTPUT:
        // (1)      2 1 3.4
        // (2)      1 2 3.4
        // (3)      1 2 3.4
        // (4)      2 1 3.4
        // (5)      1 2 3.4
        // (6)      1 2 3.4
        // (7)      2 1 3.4
        // (8)      2 1 3.4
        // (9)      1 2 3.4

        auto some_func = [](int a, int b, double c) {
            std::println("{} {} {}", a, b, c);
        };

        auto f1 = typed_carrier(some_func, 2, 3.4, 1);
        auto f2 = typed_carrier(some_func, 1, 2, 3.4);
        auto f3 = typed_carrier(some_func, 1, 3.4, 2);
        auto f4 = typed_carrier(some_func, 3.4, 2);
        auto f5 = typed_carrier(some_func, 1, 3.4);
        auto f6 = typed_carrier(some_func, 3.4);
        auto f7 = typed_carrier(some_func, 2);
        auto f8 = typed_carrier(some_func, 1);

        std::invoke(f1);                // 1
        std::invoke(f2);                // 2
        std::invoke(f3);                // 3
        std::invoke(f4, 1);             // 4
        std::invoke(f5, 2);             // 5
        std::invoke(f6, 1, 2);          // 6
        std::invoke(f6, 2, 1);          // 7
        std::invoke(f7, 3.4, 1);        // 8
        std::invoke(f8, 2, 3.4);        // 9
        // std::invoke(f8, 'a'); CE   
        // std::invoke(f8, 1); CE   
        // std::invoke(f8, 1, 2, 3); CE   
    }
}
