#include <iostream>

int main() {
    int a, b;

    std::cout << "please enter the dividend and the divisor:" << std::endl;
    std::cin >> a >> b;

    std::cout << "we want to perform the integer division of " << a << " by " << b << std::endl;

    int q = 0;
    int r = a;

    while (r >= b) {
        r = r - b;
        q = q + 1;
    }

    std::cout << "the quotient is " << q << std::endl;
    std::cout << "the remainder is " << r << std::endl;

    return 0;
}