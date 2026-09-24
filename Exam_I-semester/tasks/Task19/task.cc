// Следующий код должен компилироваться и работать без ошибок.
int main() {
    Add<int> a(2);
    Mult<int> m(3);

    TransformChain<Add<int>, Mult<int>> chain(a, m);

    int x = 1;
    int y = chain.apply(x);   // (1 + 2) * 3 = 9

    // Следующая строка должна быть ошибкой компиляции, если
    // типы операции и аргумента "плохо сочетаются":
    // Add<double> a2(2.5);
    // TransformChain<Add<double>, Mult<int>> bad(a2, m);
    // int z = bad.apply(1);   // должны запретить неявный double->int

    return 0;
}