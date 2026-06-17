// std::any and std::variant deprecated
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

// Another test for task
// // std::any and std::variant deprecated
// class LazyEvaluatedMap;

// int main() {
//     LazyEvaluatedMap m;

//     m["x"] = [](){ std::cout << "x "; return 2; };
//     m["y"] = [](){ std::cout << "y "; return 3; };

//     std::cout << m["x"] << '\n'; // x 2
//     std::cout << m["x"] << '\n'; // 2
    
//     std::cout << m["y"] << '\n'; // y 3
//     std::cout << m["y"] << '\n'; // 3

//     return 0;
// }


// Another test
// int main() {
//   LazyEvaluatedMap m;
//   m["x"] = []() {std::cout << "xxxx"; return 1;};

//   std::cout << m["x"]; // xxxx 1
//   std::cout << m["x"]; // 1
//   std::cout << m["x"]; // 1

//   // Kurilov's test
//   // v v v v v v v v v v v v v v v v v v v v v 
//   LazyEvaluatedMap z(m.begin(), m.end());
//   std::cout << z["x"]; // 1
//   z["x"] = [](){std::cout << "xxxx"; return 1;};
//   std::cout << z["x"]; // xxxx 1
//   std::cout << z["x"]; // 1
// }