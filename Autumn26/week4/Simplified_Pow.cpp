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
    // we declare a variable for the result
    // (should it be initialised? to what value?)

    // TODO: use a for loop to implement the repeated multiplication algorithm 
    // so that at the end of the loop variable result contains base^exp

    return result;
    // at the end we return the value we computed
    // we *do not print* anything in the function
}

int main(){
    // we test examples with integer (and non-negative) exponent

    std::cout << "2^3: " << mypow(2, 3) << std::endl;
    std::cout << "0.5^2: " << mypow(0.5, 2) << std::endl;
    std::cout << "1^0: " << mypow(1, 0) << std::endl;

    // negative exponents
    std::cout << "2^-3: " << mypow(2, -3) << std::endl;
    std::cout << "0.5^-2: " << mypow(0.5, -2) << std::endl;
}