struct IsEven {
    bool operator()(int value) const {
        return value % 2;
    }
};





//  Реализоовать функцию not_functor, лямбды и стандартная библиотека запрешены 

int main () {
    IsEven is_even;



    auto is_odd = not_functor(is_even);

    std::cout << is_even(2) << is_odd(2); // 0 1
    std::cout << is_even(3) << is_odd(3); // 1 0 
    
}
