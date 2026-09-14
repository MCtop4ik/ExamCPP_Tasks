int main() {
    BitMatrix_5 bm_1;
    // sizeof(BitMatrix_T) == 4
    bm_1[0][1] = true;
    bm_1[3][1] = false;

    BitMatrix_5 bm_2;
    bm_2[1][0] = true;
    bm_2[3][1] = true;

    BitMatrix_5 bm_and = bm_1 & bm_2; // перемножение матриц битовое И
    std::cout << bm_1 << std::endl;
    
    std::cout << bm_2 << std::endl;

    std::cout << bm_and << std::endl;

}