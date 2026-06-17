#include <iostream>

struct S {};

int main() {
  using left = std::tuple<int, double, std::string, int>;
  using right = std::tuple<S, int, float, double>;

  using inter = tuple_intersection_t<left, right>;
  static_assert(std::is_same_v<inter, std::tuple<int, double>>);
}
