int main() {
  static_assert(std::is_same_v<NthType<0, int, double, char>::type, int>);
  static_assert(std::is_same_v<NthType<1, int, double, char>::type, double>);
  static_assert(std::is_same_v<NthType<2, int, double, char>::type, char>);
  static_assert(NthType<3, int, double, char>::type); // compile error
  static_assert(NthType<1>::type);                    // compile error
}