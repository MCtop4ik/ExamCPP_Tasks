#include <iostream>

template <typename T> void print(T result) { std::cout << result << '\n'; }

int main() {
  Mult_3 a;
  Add_5 b;
  Minus_1 c;

  print((4, a, b, c));
  // should print 16
  //((4 * 3) + 5) - 1

  print((2, b, c, c, c, c, a));
  // should print 9
  //((2 + 5) - 1 - 1 - 1 - 1) * 3
}