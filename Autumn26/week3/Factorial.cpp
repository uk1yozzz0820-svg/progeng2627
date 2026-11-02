#include <iostream>

int main(){
    int n;
    std::cin >> n;

    double result = 1;
    for(int i = 0; i < n; i++){
        result = result * (n - i);
    }

    std::cout << "The factorial of " << n << " is " << result << std::endl;






}