int main() {
  static_assert(
      std::is_same_v<Sort<IntList<5, 1, 2, 3, 56, 73, 42, 34, 235, 12>>::type,
                     IntList<1, 2, 3, 5, 12, 34, 42, 56, 73, 235>>);
}