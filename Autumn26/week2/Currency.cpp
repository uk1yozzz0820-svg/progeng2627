#include <iostream>

int main(){
    double Pounds,Euros,Rates;
    
    std::cout << "Please enter the amount of money in British Pounds" << std::endl;
    std::cin >> Pounds;

    std::cout << "Please enter the current exchange rate from British Pounds to Euros" << std::endl;
    std::cin >> Rates;

    Euros = Pounds * Rates;
    std::cout << "The amount of money in Euros: " << Euros << std::endl;

}