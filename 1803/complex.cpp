#include <iostream>
#include "./complex.hpp"


int main() {
    complex_number<double> c1(1.5, -2.0);
    complex_number<double> c2(3.0, 4.0);
    
    std::cout << "c1: " << c1 << "\n";
    std::cout << "c2: " << c2 << "\n";
    
    std::cout << "Somma: " << (c1 + c2) << "\n";
    std::cout << "Prodotto: " << (c1 * c2) << "\n";
    
    std::cout << "Coniugato di c1: " << c1.conjugate() << "\n";
    
    std::cout << "c1 + 2: " << (c1 + 2.0) << "\n";
    std::cout << "2 + c1: " << (2.0 + c1) << "\n";
    
    std::cout << "c1 * 2: " << (c1 * 2.0) << "\n";
    std::cout << "2 * c1: " << (2.0 * c1) << "\n";
    
    return 0;
}
