int main() {
  LazyEvaluatedMap m;

  m["x"] = []() {
    std::cout << "xxx";
    return 0;
  };

  std::cout << m["x"];  // xxx 0
  std::cout << m["x"];  // 0
  std::cout << m["x"];  // 0

  return 0;
}