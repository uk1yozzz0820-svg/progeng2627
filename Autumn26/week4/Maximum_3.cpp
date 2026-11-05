#include <iostream>

double max3(double a, double b, double c){
    double result = a;
    // start by assuming the first number is the largest

    if(b > result){
        result = b;
    }

    if(c > result){
        result = c;
    }

    return result;
    // we *do not print* anything in the function
}

int main(){
    double num1, num2, num3;
    std::cout << "Please enter the three numbers: " << std::endl;
    std::cin >> num1 >> num2 >> num3;

    double result = max3(num1, num2, num3);
    std::cout << "The maximum is " << result << std::endl;
}
