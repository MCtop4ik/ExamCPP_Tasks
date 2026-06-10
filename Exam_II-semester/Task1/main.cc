int main() {
  static_assert(
      std::is_same_v<details::flip_t<std::tuple<std::pair<float, int>,
                                                std::pair<double, int>,
                                                std::pair<char, bool>>>,
                     std::tuple<std::pair<int, float>, std::pair<int, double>,
                                std::pair<bool, char>>>);
  static_assert(std::is_same_v<
                details::flip_t<
                    std::tuple<std::pair<float, int>, std::pair<long long, int>,
                               std::pair<char, double>, std::pair<char, bool>>>,
                std::tuple<std::pair<int, float>, std::pair<int, long long>,
                           std::pair<double, char>, std::pair<bool, char>>>);
  static_assert(
      std::is_same_v<details::flip_t<std::tuple<std::pair<float, int>,
                                                std::pair<char, bool>>>,
                     std::tuple<std::pair<int, float>, std::pair<bool, char>>>);
  static_assert(std::is_same_v<details::flip_t<std::tuple<>>, std::tuple<>>);
}
