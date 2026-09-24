 
#include <cassert>
#include <iostream>

int main() {
  CopyGraph a;
  CopyGraph b = a;
  assert(a.depth() == 1);
  assert(b.depth() == 0);
  {
    CopyGraph c = b;
    assert(a.depth() == 2);
    assert(b.depth() == 1);
    assert(c.depth() == 0);
  }
  assert(a.depth() == 1);
  assert(b.depth() == 0);
  std::cout << b.depth();
  return 0;
}
