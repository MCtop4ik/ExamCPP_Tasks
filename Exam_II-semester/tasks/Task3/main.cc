int main() {
  static_assert(GCD_V<18, 12> == 6, "Ошибка в GCD!");
  static_assert(GCD_V<100, 25> == 25, "Ошибка в GCD!");
  static_assert(GCD_V<7, 13> == 1, "Ошибка в GCD!");
}