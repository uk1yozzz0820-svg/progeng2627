#include <iostream>

int main(){
    int n, sum = 0, count = 0;
    double avg = 0;

    std::cout << "enter a number:" << std::endl;
    std::cin >> n;

    while(n != 0){
        count += 1;
        sum = sum + n;
        avg = static_cast<double>(sum) / count;
        std::cout << "the average so far is:" << std::endl;
        std::cout << avg << std::endl;

        std::cout << "enter a number:" << std::endl;
        std::cin >> n;
    }
}