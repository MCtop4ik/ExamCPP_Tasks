#include <iostream>

int main() {
  using tp = std::tuple<int, const int &, double, double &&>;

  using to_rv = to_rvalue_t<tp>;

  static_assert(std::is_same_v < to_rv,
                std::tuple<int &&, int &&, double &&, double &&>);
}
