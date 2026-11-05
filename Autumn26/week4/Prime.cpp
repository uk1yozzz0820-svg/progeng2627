#include <iostream>

int smallest_factor(int n) {
    for (int cf = 2; cf < n; cf++) {
        if (n % cf == 0) {
            return cf;
        }
    }
    return 0;
}

int main() {
    int low, high;
    std::cin >> low >> high;

    for (int n = low; n <= high; n++) {
        if (smallest_factor(n) == 0) {
            std::cout << n << std::endl;
        }
    }
}
