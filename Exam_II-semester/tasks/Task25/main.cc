#include <iostream>
#include <list>
#include <string>
#include <variant>
#include <vector>

// Реализуйте ленивое flatten одного уровня вложенности. Если на
// этом уровне встречаются variant-ы, листовые типы объединяются в один плоский
// variant (с дедупликацией):
//   container<int>                                        -> range<int>
//   container<container<int>>                             -> range<int>
//   container<container<variant<int, double>>>            -> range<variant<int, double>>
//   container<variant<container<int>, container<string>>> -> range<variant<int, string>>

template <typename Outer>
struct flatten {};

// Вспомогательный вывод variant для проверки.
template <typename... Ts>
std::ostream& operator<<(std::ostream& os, const std::variant<Ts...>& v) {
    std::visit([&](const auto& x) { os << x; }, v);
    return os;
}

int main() {
    // (a) контейнер значений
    std::vector<int> a = {1, 2, 3};
    for (auto&& x : flatten(a)) std::cout << x << ' '; // 1 2 3
    std::cout << '\n';

    // (b) контейнер контейнеров
    std::vector<std::vector<int>> b = {{1, 2}, {}, {3}};
    for (auto&& x : flatten(b)) std::cout << x << ' '; // 1 2 3
    std::cout << '\n';

    // (c) контейнер variant-ов разных контейнеров
    using V = std::variant<std::list<int>, std::vector<std::string>>;
    std::vector<V> c;
    c.push_back(std::list<int>{1, 2, 3});
    c.push_back(std::vector<std::string>{"a", "b"});
    for (auto&& x : flatten(c)) std::cout << x << ' '; // 1 2 3 a b
    std::cout << '\n';

    // (d) контейнер контейнеров с variant-элементами
    using W = std::variant<int, double>;
    std::vector<std::vector<W>> d = {{W{1}, W{2.5}}, {}, {W{3}}};
    for (auto&& x : flatten(d)) std::cout << x << ' '; // 1 2.5 3
    std::cout << '\n';
}
