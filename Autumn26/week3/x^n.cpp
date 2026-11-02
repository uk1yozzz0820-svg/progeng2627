#include <iostream>

int main() {
    double x;
    int n;

    std::cout << "enter x and n:" << std::endl;
    std::cin >> x >> n;

    double result = 1;
    for (int i = 0; i < n; i++) {
        result = result * x;
    }

    std::cout << x << "^" << n << " = " << result << std::endl;

    return 0;
}