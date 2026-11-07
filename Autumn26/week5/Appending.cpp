#include <iostream>
#include <vector>

void append_vectors(const std::vector<int>& vin1, const std::vector<int>& vin2, std::vector<int>& vout){
    vout.clear();

    for(int i = 0; i < vin1.size(); i++){
        vout.push_back(vin1[i]);
    }

    for(int i = 0; i < vin2.size(); i++){
        vout.push_back(vin2[i]);
    }
}

void print_vector(const std::vector<int>& v){
    for(int i = 0; i < v.size(); i++){
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

int main(){
    std::vector<int> v1;
    v1.push_back(1);
    v1.push_back(7);
    v1.push_back(3);
    v1.push_back(4);

    std::vector<int> v2;
    v2.push_back(2);
    v2.push_back(-2);
    v2.push_back(19);

    std::vector<int> empty;
    std::vector<int> result;

    append_vectors(v1, v2, result);
    std::cout << "v1 then v2 (expected 1 7 3 4 2 -2 19): ";
    print_vector(result);

    append_vectors(v2, v1, result);
    std::cout << "v2 then v1 (expected 2 -2 19 1 7 3 4): ";
    print_vector(result);

    append_vectors(v1, empty, result);
    std::cout << "v1 then empty (expected 1 7 3 4): ";
    print_vector(result);

    append_vectors(empty, v2, result);
    std::cout << "empty then v2 (expected 2 -2 19): ";
    print_vector(result);

    append_vectors(empty, empty, result);
    std::cout << "empty then empty (expected nothing): ";
    print_vector(result);
}
