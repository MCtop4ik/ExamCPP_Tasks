#include <cstring>
#include <type_traits>

template <auto... Vs>
struct List {};

constexpr auto IsSpliter = []<typename T>(T data) {
    if constexpr (std::is_same_v<T, int>) {
        return data == 0;
    } else if constexpr (std::is_same_v<T, char>) {
        return data == '0';
    } else if constexpr (std::is_same_v<T, const char*>) {
        return std::string_view(data) == "0";
    } else {
        return false;
    }
};

void solut() {
    static_assert(std::is_same_v<Split<List<1, 2, 0, 3, 0, 4>, IsSpliter>::type, List<List<1, 2>, List<3>, List<4>>>);

    static_assert(std::is_same_v<Split<List<'a', 'b', '0', 'c', '0', 'd'>, IsSpliter>::type,
                                 List<List<'a', 'b'>, List<'c'>, List<'d'>>>);

    static_assert(std::is_same_v<Split<List<5, 6>, IsSpliter>::type, List<List<5, 6>>>);

    static_assert(std::is_same_v<Split<List<0>, IsSpliter>::type, List<>>);

    static_assert(std::is_same_v<Split<List<>, IsSpliter>::type, List<>>);

    constexpr auto Never = [](auto) { return false; };
    static_assert(
        std::is_same_v<Split<List<1, 2, 'a', 'b', 3>, Never>::type, List<List<1, 2>, List<'a', 'b'>, List<3>>>);

    static_assert(std::is_same_v<Split<List<1, 2, 0, 'x', 'y', 7, 0>, IsSpliter>::type,
                                 List<List<1, 2>, List<'x', 'y'>, List<7>>>);
}