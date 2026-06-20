int main() {
    static_assert(is_same_v<ToBit<8>::value, BitVector<1, 0, 0>>, "print"); // 8 = 100

    static_assert(is_same_v < Sum<ToBit<9>::value, ToBit<7>::value>::value, BitVector<1, 0, 0, 0, 0>,
                  "sum"); // 1001 + 111 = 10000

    static_assert(is_same_v < Sub<ToBit<9>::value, ToBit<7>::value>::value, BitVector<1, 0>, "sub"); // 1001 - 111 = 10

    static_assert(is_same_v < Mul<ToBit<3>::value, ToBit<4>::value>::value, BitVector<1, 1, 0, 0>,
                  "mul"); // 11 * 100 = 1100

    static_assert(is_same_v < Div<ToBit<7>::value, ToBit<3>::value>::value, BitVector<1, 0>, "div"); // 111 / 11 = 10

    static_assert(is_same_v < Concat<ToBit<6>::value, ToBit<2>::value>::value, BitVector<1, 1, 0, 1, 0>,
                  "concat"); //"110" + "10" = "11010"
}