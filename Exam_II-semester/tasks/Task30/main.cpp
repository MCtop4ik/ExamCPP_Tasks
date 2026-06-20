int main() {
    static_assert(is_same_v<ToBit<8>::value, BitVector<1, 0, 0>>, "ans");

    static_assert(is_same_v < Sum<ToBit<9>::value, ToBit<7>::value>::value, BitVector<1, 0, 0, 0, 0>);

    static_assert(is_same_v < Sub<ToBit<9>::value, ToBit<7>::value>::value, BitVector<1, 0>);

    static_assert(is_same_v < Mul<ToBit<3>::value, ToBit<4>::value>::value, BitVector<1, 1, 0, 0>);

    static_assert(is_same_v < Dev<ToBit<7>::value, ToBit<3>::value>::value, BitVector<1, 0>);

    static_assert(is_same_v < Con<ToBit<6>::value, ToBit<2>::value>::value, BitVector<1, 1, 0, 1, 0>);
}