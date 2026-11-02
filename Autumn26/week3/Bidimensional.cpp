#include <iostream>

int main(){
    int n;
    std::cin >> n;
    int c2 = 0;

    while(c2 < n){
        c2 = c2 + 1;

        int c = 0;
        while(c < n){
            c = c + 1;
            std::cout << "*";
        }

        std::cout << std::endl;
    }
}

 