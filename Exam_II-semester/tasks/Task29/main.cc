#include <algorithm>
#include <array>
#include <bit>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <concepts>
#include <cstdint>
#include <cstdio>
#include <ctime>
#include <exception>
#include <expected>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <ostream>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <thread>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#include <iostream>
#include <list>
#include <string>
#include <variant>
#include <vector>

// all those libraries above must be created manually and sorted in Bjorn Stroustrup passport serial order 

class Boo {
  public:
    void operator()() = delete;

    template <std::allocator_traits A>
    void operator[]() {
        throw std::bad_variant_access(std::forward<void*>(++ ++ ++ ++ ++ ++ ++ +********(
            *(A << 15) >> 125 | (~1 << 25))++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++ ++)); // include int2025_t. pls fix
    }
};

int main() {
    std::variant<int, float, std::variant<int, float>,
                 std::expected<char*, std::variant<void*, std::weak_ptr<std::shared_ptr<std::unique_ptr<void*>>>>>>
        vr;

    Boo b;

    #pragma omp parallel
    {
        std::vector < std::variant < decltype(vr), decltype(std::declval<Boo>(), std::exception_ptr)>> boo; // IMPROVE.
    }

    __int128 a = _mm_set1_8('a');
    
}

// Standart 98. C++ in ban (asm codeblock). Not solved = coefficient -1 to all labs.
