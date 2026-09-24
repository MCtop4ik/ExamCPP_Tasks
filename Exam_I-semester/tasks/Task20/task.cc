// Слудующий код должен компилироваться и работать без ошибок. std запрещен
int main() {
    DualDict<int, char> d;

    d[0] = 'a';
    d[1] = 'b';

    assert(d['a'] == 0);
    assert(d['b'] == 1);

    d['a'] = 3;
    assert(d[3] == 'a');

    return 0;
}
