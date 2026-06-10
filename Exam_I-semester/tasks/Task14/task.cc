/// Слудующий код должен компилироваться и работать без ошибок
#include <assert.h>

int main() {
    PowTwo pt;

    assert(pt() == 1);
    assert(pt() == 2);
    assert(pt() == 4);
    assert(pt() == 8);

    return 0;
}