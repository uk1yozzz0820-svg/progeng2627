#include <iostream>

double mypow(double base, int exp){
    double result = 1;
    bool negative = false;

    // remember whether exp was negative, then make it positive
    if(exp < 0){
        negative = true;
        exp = -exp;
    }

    for(int i = 0; i < exp; i++){
        result = result * base;
    }

    // x^-n = 1 / x^n
    if(negative){
        result = 1 / result;
    }

    return result;
}

double sum_of_powers(double x, int n){
    double acc = 0;

    for(int i = 1; i <= n; i++){
        acc = acc + mypow(x, i);
    }

    return acc;
    // we *do not print* anything in the function
}

int main(){
    double x;
    int n;

    std::cout << "Please enter the x and n for the sum of powers: " << std::endl;
    std::cin >> x >> n;

    double result = sum_of_powers(x, n);
    std::cout << "The result of the sum of powers is: " << result << std::endl;
}
