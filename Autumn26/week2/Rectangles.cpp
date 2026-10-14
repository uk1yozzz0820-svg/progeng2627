#include <iostream>

int main(){
    double a,b,area;
    std::cout << "Please enter the length of one side of the rectangle" << std::endl;
    std::cin >> a;

    std::cout << "Please enter the length of the othr side of the rectangle" << std::endl;
    std::cin >> b;

    area = (a + b) * 2;
    std::cout << "The area of the rectangle is " << area << std::endl;

}