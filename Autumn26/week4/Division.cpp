#include <iostream>

void div(int a, int b, int& q, int& r){
    q = a / b;
    r = a % b;
}

int main(){
    int a, b, q, r;

    std::cout << "please enter a and b:" << std::endl;
    std::cin >> a >> b;

    div(a, b, q, r);

    std::cout << a << " / " << b << " = " << q << " remainder " << r << std::endl;








}