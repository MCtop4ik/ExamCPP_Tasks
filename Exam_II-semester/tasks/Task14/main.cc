int main() {
    // Test 1: Basic tuple creation and get
    Tuple<int, double, std::string> t1(42, 3.14, "Hello, Tuple!");
    std::cout << "t1: "
              << get<0>(t1) << ", "
              << get<1>(t1) << ", "
              << get<2>(t1) << std::endl;

    // Test 2: inverted_get (from the end)
    std::cout << "inverted_get<0>(t1) = " << inverted_get<0>(t1) << std::endl;  // last element
    std::cout << "inverted_get<1>(t1) = " << inverted_get<1>(t1) << std::endl;
    std::cout << "inverted_get<2>(t1) = " << inverted_get<2>(t1) << std::endl;

    // Test 3: make_tuple and deduction guide
    auto t2 = make_tuple(100, 'X', 2.718f);
    std::cout << "t2: "
              << get<0>(t2) << ", "
              << get<1>(t2) << ", "
              << get<2>(t2) << std::endl;

    // Test 4: Tuple with single element
    Tuple<std::string> t3("Single");
    std::cout << "t3: " << get<0>(t3) << std::endl;
    std::cout << "inverted_get<0>(t3) = " << inverted_get<0>(t3) << std::endl;

    // Test 5: Empty tuple (compilation check only)
    Tuple<> empty;
    // get<0>(empty); // would not compile – as expected

    return 0;
}