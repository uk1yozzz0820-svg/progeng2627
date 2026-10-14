#include <iostream>

int main(){
    double weight,height,BMI;

    std::cout << "What is your height in metres?" << std::endl;
    std::cin >> height;

    std::cout << "What is your weight in kilograms?" << std::endl;
    std::cin >> weight;

    BMI = weight/(height * height);
    std:: cout << "Your BMI is " << BMI << std::endl;








}