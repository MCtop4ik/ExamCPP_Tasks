#include <print>

/*
    Реализуйте свою корутину — функцию, которую можно приостановить и возобновить.
    Ключевые механики:
        - CORO_DEFINE(name, return_type)
        - CORO_END(name)
        - CORO_SUSPEND(return_expression) — приостанавливает исполнение и возвращает результат выражения
    НЕ нужно:
        - поддерживать SUSPEND во вложенных scope: if, for, пустой scope и так далее
        - аргументы и локальные переменные
*/

struct CoroEndError {};

CORO_DEFINE(coro_gen2, int);
    std::println("first");
    CORO_SUSPEND(1;);
    std::println("third");
    CORO_SUSPEND(2;);
CORO_END(coro_gen2);



// OUTPUT:
// first
// coro_get: 1
// third
// coro_get: 2
// CoroEndError

int main() {
    {
        try {
            auto f = coro_gen2(29, 0);
            std::println("coro_get: {}", f());
            std::println("coro_get: {}", f());
            f();
        } catch(CoroEndError) {
            std::println("CoroEndError");
        }
    }

    return 0;
}
