#include <iostream>
#include <stdexcept>

struct Foo {};

int main() {
    NoMoreThenNCopy<2, Foo> p{new Foo{}}; 
    auto p2 = p;    
    try {
        auto p3 = p; // some exception
    }
    catch (const std::exception& ex) {
        std::cout << "exception: " << ex.what() << "\n";
    }
}