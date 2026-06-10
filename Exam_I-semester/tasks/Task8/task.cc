#include <assert.h>

int plus(int a, int b) {
    return a + b;
}

int minus(int a, int b) {
    return a - b;
}

int main(int, char**){
    auto increment = toOneArg(plus, 1);
    assert(increment(2) == 3);

    auto decrement = toOneArg(minus, 1);
    assert(decrement(2) == 1);
    return 0;
}