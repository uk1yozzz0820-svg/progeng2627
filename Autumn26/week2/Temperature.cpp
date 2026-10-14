#include <iostream>

int main(){
    double c,f;
    std::cout << "what is the temperature in Celsius degrees:" << std::endl;
    std::cin >> c;

    f = c * 1.8 + 32;

    std::cout << "The Temperature in Fahrenheit degrees is " << f << std::endl;

}