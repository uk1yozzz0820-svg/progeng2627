#include <iostream>

int main(){
    int n, curmax, counter = 0;
    std::cout << "Please enter a number: " << std::endl;
    std::cin >> n;
    curmax = n;

    while(n != 1){

        if(n % 2 == 0){
            n = n / 2;
        }
        else{
            n = 3 * n + 1;
        }

        if(n > curmax){
            curmax = n;
        }

        counter += 1;
        std::cout << n << " ";
    }

    std::cout << std::endl;
    std::cout << "The number of steps is " << counter << std::endl;
    std::cout << "The maximum generated in the process is " << curmax << std::endl;





}