int main() {
  static_assert(DigitCount<12345>::value == 5);
  static_assert(DigitCount<1>::value == 1);
  static_assert(DigitCount<12>::value == 2);
  static_assert(DigitCount<111235235235>::value == 12);
}