#include <iostream>
#include <vector>

int main(){
    int num1, num2, num3, result;
    std::cout << "Please enter the 3 integers in order: " << std::endl;
    std::cin >> num1 >> num2 >> num3;

    std::vector<int> v;
    v.push_back(num1);
    v.push_back(num2);
    v.push_back(num3);

    result = v[0] * (v[1] + v[2]);

    std::cout << "The result is: " << result << std::endl;

}