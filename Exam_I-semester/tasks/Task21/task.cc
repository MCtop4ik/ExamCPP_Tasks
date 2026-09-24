// Слудующий код должен компилироваться и работать без ошибок. std запрещен
int main () {
    NumberExpression a = 1;
    NumberExpression b = 2;

    Expression c = (a + b) * (a - b);

    auto num = c.Evaluate();
    auto str = c.Format();
    std::cout << str;
    assert(num == -3);
    assert(strcmp(str, "((1 + 2) * (1 - 2))") == 0);

}
