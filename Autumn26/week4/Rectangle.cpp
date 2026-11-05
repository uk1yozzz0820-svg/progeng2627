#include <iostream>

void rect(double side1, double side2, double& perimeter, double& area){
    perimeter = (side1 + side2) * 2;
    area = side1 * side2;
}

int main(){
    double side1, side2, perimeter, area;

    std::cout << "please enter the two sides:" << std::endl;
    std::cin >> side1 >> side2;

    rect(side1, side2, perimeter, area);

    std::cout << "perimeter: " << perimeter << std::endl;
    std::cout << "area: " << area << std::endl;
}