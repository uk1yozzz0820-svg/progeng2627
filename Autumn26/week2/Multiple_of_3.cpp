#include <iostream>

int main(){
    int n,rem;

    std::cout << "Please enter the number to check whether it's a multiple of 3" << std::endl;
    std::cin >> n;

    rem = n % 3;

    if(rem == 0){
        std::cout << "The number you entered is a multiple of 3" << std::endl;
    }
    else{
        std::cout << "The number you entered isn't a multiple of 3" << std::endl;
    }
}