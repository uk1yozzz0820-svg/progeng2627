#include <iostream>
#include <vector>

int search_vector(int n, const std::vector<int>& vin){
    for(int i = 0; i < vin.size(); i++){
        if(vin[i] == n){
            return i;
        }
    }

    return -1;
}

int main(){
    std::vector<int> empty;
    std::cout << "empty vector: " << search_vector(3, empty) << " (expected -1)" << std::endl;

    std::vector<int> v;
    v.push_back(4);
    v.push_back(7);
    v.push_back(2);
    v.push_back(7);
    v.push_back(9);
    // v is: 4 7 2 7 9

    std::cout << "found at the start: " << search_vector(4, v) << " (expected 0)" << std::endl;
    std::cout << "found in the middle: " << search_vector(2, v) << " (expected 2)" << std::endl;
    std::cout << "found at the end: " << search_vector(9, v) << " (expected 4)" << std::endl;
    std::cout << "appears twice: " << search_vector(7, v) << " (expected 1)" << std::endl;
    std::cout << "not in the vector: " << search_vector(5, v) << " (expected -1)" << std::endl;

    std::vector<int> negative;
    negative.push_back(-3);
    negative.push_back(0);
    negative.push_back(-8);
    std::cout << "negative number: " << search_vector(-8, negative) << " (expected 2)" << std::endl;
}
