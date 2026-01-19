int main() {
  BitArray a{16};

  // This line nonsence. This by the way mean you need just allocate 2 bytes at
  // a heap. On stack there is no limits for memory. 
  // assert(sizeof(a) == 2);

  a[1] = true;
  a[10] = true;

  for (int i = 0; i < 16; ++i) {
    if (i == 1 || i == 10)
      assert(a[i]);
    else
      assert(!a[i]);
  }
}