#include <iostream>
#include <cmath>

int main(){
    int i = 1;
    double x, n, acc = 0;

    std::cout << "Please enter the x and n for the sum of powers: " << std::endl;
    std::cin >> x >> n;

    while (i <= n){
        acc = acc + std::pow(x , i);
        i += 1;
    }

    std::cout << "The Result of the sum of powers are: " << acc << std::endl;

}