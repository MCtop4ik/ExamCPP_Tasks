#include <iostream>
#include <string>

// Условие: реализуйте TFuncStorage — хранилище функций с поиском по сигнатуре.
// Работаем только с указателями на функции:
//   - Add(fn) принимает указатель на функцию и сохраняет его; типы сигнатуры
//     (тип результата и типы аргументов) должны выводиться из указателя, явно
//     их в Add указывать нельзя;
//   - FindFuncBySignature<Result, Args...>() возвращает ссылку на сохранённую
//     функцию с такой сигнатурой (с методом Call), либо бросает исключение, если
//     её нет.
// Аргументов у функции может быть сколько угодно.
//
// TODO: implement
class TFuncStorage {};

int Length(std::string s) { return static_cast<int>(s.size()); }
double Identity(double d) { return d; }
int Sum3(int a, int b, int c) { return a + b + c; }

int main() {
    TFuncStorage storage;
    storage.Add(Length);
    storage.Add(Identity);
    storage.Add(Sum3);

    auto& f1 = storage.FindFuncBySignature<int, std::string>();
    std::cout << f1.Call("hello") << '\n'; // 5

    auto& f2 = storage.FindFuncBySignature<double, double>();
    std::cout << f2.Call(2.5) << '\n'; // 2.5

    auto& f3 = storage.FindFuncBySignature<int, int, int, int>();
    std::cout << f3.Call(1, 2, 3) << '\n'; // 6
}
