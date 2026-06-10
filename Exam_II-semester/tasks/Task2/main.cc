int main() {
  static_assert(IsPrime<2>::value, "2 должно быть простым");
  static_assert(IsPrime<17>::value, "17 должно быть простым");
  static_assert(!IsPrime<15>::value, "15 не должно быть простым");
  static_assert(!IsPrime<4>::value, "15 не должно быть простым");
}