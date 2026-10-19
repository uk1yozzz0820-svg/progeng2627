#include <iostream>

int main(){
    int year;

    std::cout << "please enter a year" << std::endl;
    std::cin >> year;

    if( (year % 4) == 0){ 
        // if multiple of 4

        if( (year % 100) == 0){
            if((year % 400) == 0){
                std::cout << "It's a leap year." << std::endl;
            }    

            else{
                std::cout << "It's not leap year" << std::endl;
            }
            // if (also) multiple of 100
            // ...
        }
        else{
            std::cout << "it's a leap year" << std::endl;
            // if not multiple of 100
            // (but still multiple of 4)
            // ...

        }
    }
    else{
        // if not multiple of 4
        std::cout << "not a leap year" << std::endl;
    }
}