int main() {
  static_assert(s_v<1, 3, 5, 7, 9, 11>);
  static_assert(s_v<11, 9, 7, 5, 3, 1>);
  static_assert(s_v<11, 1>);
  static_assert(s_v<11>);
  static_assert(!s_v<>);
  static_assert(!s_v<1, 2, 4>);
}