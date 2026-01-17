#include <iostream>

class Foo {};
class Bar {};

template <unsigned SIZE> class BarFooIntArray {};

int main() {
  BarFooIntArray<3> arr;

  arr[0] = Bar{};
  arr[1] = Foo{};
  arr[2] = 10;

  std::cout << arr[0].IsBar() << arr[0].IsFoo() << arr[0].IsInt() << std::endl; // 100
  std::cout << arr[1].IsBar() << arr[1].IsFoo() << arr[1].IsInt() << std::endl; // 010
  std::cout << arr[2].IsBar() << arr[2].IsFoo() << arr[2].IsInt() << std::endl; // 001

  Bar b = arr[0];
  int i = arr[2];

  std::cout << i << std::endl; // 10
}
