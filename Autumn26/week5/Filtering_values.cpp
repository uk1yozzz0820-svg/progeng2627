#include <iostream>
#include <vector>

void filter_v(const std::vector<double>& vin, double t, std::vector<double>& vout){
    vout.clear();

    for(int i = 0; i < vin.size(); i++){
        if(vin[i] < t){
            vout.push_back(vin[i]);
        }
    }
}

void print_vector(const std::vector<double>& v){
    for(int i = 0; i < v.size(); i++){
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

int main(){
    std::vector<double> v;
    v.push_back(3);
    v.push_back(8);
    v.push_back(1.5);
    v.push_back(9);
    v.push_back(-4);
    v.push_back(5);
    // v is: 3 8 1.5 9 -4 5

    std::vector<double> filtered;
    // filtered receives the result: inside filter_v it is called vout

    filter_v(v, 5, filtered);
    std::cout << "less than 5 (expected 3 1.5 -4): ";
    print_vector(filtered);

    filter_v(v, 100, filtered);
    std::cout << "less than 100 (expected 3 8 1.5 9 -4 5): ";
    print_vector(filtered);

    filter_v(v, -10, filtered);
    std::cout << "less than -10 (expected nothing): ";
    print_vector(filtered);

    std::vector<double> empty;
    filter_v(empty, 5, filtered);
    std::cout << "empty vector (expected nothing): ";
    print_vector(filtered);
}
