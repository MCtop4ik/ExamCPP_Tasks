#include <cassert>
#include <functional>
#include <iostream>
#include <string>
#include <tuple>
#include <type_traits>
#include <utility>

int free_function(int a, int b, int c) {
    return a * 100 + b * 10 + c;
}

struct Functor {
    std::string operator()(int id,
                           std::string name,
                           bool active,
                           std::string suffix) const {
        return name + suffix + ":" + std::to_string(id)
            + ":" + (active ? "yes" : "no");
    }
};

struct Object {
    int base = 0;

    int add(int x, int y) const {
        return base + x + y;
    }
};

// Реализовать вызов с дефолтными значениями, если их не указали
// std::bind запрещён

int main() {
    {
        auto f = [](int a, double b, char c, bool d, std::string e) {
            assert(a == 1);
            assert(b == 3.14);
            assert(c == 'x');
            assert(d == false);
            assert(e == "hello");
            return e + ": " + std::to_string(a);
        };

        auto call = make_call_with_defaults(
            f,
            10,
            3.14,
            'x',
            false,
            std::string("default")
        );

        auto result = call(
            placed_argument<0>(1),
            placed_argument<4>(std::string("hello"))
        );

        assert(result == "hello: 1");
    }

    {
        auto call = make_call_with_defaults(
            free_function,
            1,
            2,
            3
        );

        assert(call() == 123);
        assert(call(placed_argument<0>(9)) == 923);
        assert(call(placed_argument<1>(8)) == 183);
        assert(call(placed_argument<2>(7)) == 127);
        assert(call(
            placed_argument<0>(9),
            placed_argument<1>(8),
            placed_argument<2>(7)
        ) == 987);
    }

    {
        auto call = make_call_with_defaults(
            Functor{},
            42,
            std::string("Bob"),
            false,
            std::string("_user")
        );

        auto result = call(
            placed_argument<1>(std::string("Alice")),
            placed_argument<2>(true)
        );

        assert(result == "Alice_user:42:yes");
    }

    {
        Object obj{100};

        auto call = make_call_with_defaults(
            &Object::add,
            obj,
            1,
            2
        );

        assert(call() == 103);
        assert(call(placed_argument<1>(10)) == 112);
        assert(call(placed_argument<2>(20)) == 121);
    }

    std::cout << "All tests passed\n";
}
