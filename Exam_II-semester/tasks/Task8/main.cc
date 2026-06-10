int main() {
  static_assert(Contains<int, float, double, int, int>::value == true);
  static_assert(Contains<char, float, double>::value == false);
  static_assert(Contains<>::value == false);
  static_assert(Contains<int>::value == false);
  static_assert(Count<int, int, float, int, double>::value == 2);
  static_assert(Count<int, int, float>::value == 1);
  static_assert(Count<char, int, float>::value == 0);
  static_assert(Count<char>::value == 0);
  static_assert(Count<>::value == 0);
  static_assert(Count<char, int, char>::value == 1);
}