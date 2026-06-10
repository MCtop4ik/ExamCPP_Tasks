int main() {
  static_assert(CountTypes<int, double, char>::value == 3);
  static_assert(CountTypes<int, double, char, int>::value == 4);
  static_assert(CountTypes<>::value == 0);
  static_assert(CountTypes<int>::value == 1);
}