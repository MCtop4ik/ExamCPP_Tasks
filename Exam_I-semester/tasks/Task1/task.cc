#include <iostream>

class Int2StrDict {
}; // std deprecated 


int main() {
  Int2StrDict d;
  d[1] = "aa";
  d[2] = "bb";
  d[3] = "cc";

  std::cout << d; // {1 : aa, 2 : bb, 3 : cc};


  std::cout << d["aa"]; // 1;
  d["aa"] = 10;

  std::cout << d; // {2 : bb, 3 : cc, 10 : aa};

  Int2StrDict d2 = d;
  std::cout << d2; //  {2 : bb, 3 : cc, 10 : aa};
  d2 -= 2;
  d2 = d2 - "cc";
  std::cout << d2; //  {10 : aa};
}
