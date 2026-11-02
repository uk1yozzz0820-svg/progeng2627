#include <iostream>
#include <string>

int main(){
    int low, high;
    std::cout << "Enter lower and upper bound: " << std::endl;
    std::cin >> low >> high;

    std::string answer = "";

    while(answer != "="){
        int guess = (low + high) / 2;

        std::cout << "Is it " << guess << "? (< means your number is smaller, > bigger, = correct)" << std::endl;
        std::cin >> answer;

        if(answer == "<"){
            high = guess - 1;
        }
        else if(answer == ">"){
            low = guess + 1;
        }
    }

    std::cout << "Found it!" << std::endl;
}
