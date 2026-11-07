#include <iostream>
#include <vector>

// maybe not the most efficient way:
double sum_vector(std::vector<double> vin){

    double sum = 0;

    for(int i = 0; i < vin.size(); i++){
        sum = sum + vin[i];
    }

    return sum;

}

int main(){
    std::vector<double> v;
    int size;
    double n;
    std::cout << "Please enter the amount of elements you want to enter: " << std::endl;
    std::cin >> size;

    std::cout << "Please enter the numbers: " << std::endl;

    for(int j = 0; j < size; j++){
        std::cin >> n;
        v.push_back(n);
    }

    std::cout << "the sum is: " << sum_vector(v) << std::endl;

}