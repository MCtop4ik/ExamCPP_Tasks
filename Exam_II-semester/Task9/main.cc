int main() {
  static_assert(IsArray<int[]>::value);
  static_assert(IsArray<int[5]>::value);
  static_assert(!IsArray<int>::value);
  static_assert(!IsArray<>::value);
}