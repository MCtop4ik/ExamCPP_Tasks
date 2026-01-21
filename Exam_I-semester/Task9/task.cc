#include <assert.h>

// Слудующий код должен компилироваться и работать без ошибок. std запрещен
int main() {
    Array a;

    a = a + 1
    a = a + 2;

    assert(a[0] == 1);
    assert(a[1] == 2);

    a = 0 + a;

    assert(a[0] == 0);
    assert(a[1] == 1);
    assert(a[2] == 2);

    a = 2 * a;

    assert(a[0] == 0);
    assert(a[1] == 1);
    assert(a[2] == 2);
    assert(a[3] == 0);
    assert(a[4] == 1);
    assert(a[5] == 2);

    a = a - 1;

    assert(a[0] == 0);
    assert(a[1] == 2);
    assert(a[2] == 0);
    assert(a[3] == 2);

}
