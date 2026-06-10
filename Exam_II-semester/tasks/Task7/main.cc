int main() {
  static_assert(std::is_same_v<DeletePointers<int>::type, int>);
  static_assert(std::is_same_v<DeletePointers<int *>::type, int>);
  static_assert(std::is_same_v<DeletePointers<int **>::type, int>);
  static_assert(std::is_same_v<DeletePointers<int ***>::type, int>);
}