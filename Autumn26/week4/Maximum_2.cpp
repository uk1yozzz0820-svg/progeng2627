#include <iostream>

double max(double a, double b){
    if(a > b){
        return a;
    }
    else{
        return b;
    }
    }

int main(){
    double num1, num2;
    std::cout << "Please enter the two numbers: " << std::endl;
    std::cin >> num1 >> num2;

    double result = max(num1, num2);
    std::cout << "The maximum is " << result << std::endl;







}