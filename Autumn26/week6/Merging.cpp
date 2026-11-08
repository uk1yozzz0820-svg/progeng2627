#include <iostream>
#include <vector>

void merge_vectors_int(const std::vector<int>& v1, const std::vector<int>& v2, std::vector<int>& merged){
    merged.clear();

    int i = 0, j = 0;

    while(i < v1.size() && j < v2.size()){
        if(v1[i] <= v2[j]){
            merged.push_back(v1[i]);
            i++;
        }
        else{
            merged.push_back(v2[j]);
            j++;
        }
    }

    while(i < v1.size()){
        merged.push_back(v1[i]);
        i++;
    }

    while(j < v2.size()){
        merged.push_back(v2[j]);
        j++;
    }
}

void check(const std::vector<int>& v1, const std::vector<int>& v2, const std::vector<int>& expected_output){
    std::vector<int> out;
    merge_vectors_int(v1, v2, out);

    if(out == expected_output){
        std::cout << "passed" << std::endl;
    }
    else{
        std::cout << "not passed" << std::endl;
    }
}

int main(){

    std::vector<int> v1;
    std::vector<int> v2;
    std::vector<int> out;

    std::vector<int> expected_output;

    v1 = {1, 3, 5, 6};
    v2 = {4, 6, 10};
    expected_output = {1, 3, 4, 5, 6, 6, 10};

    merge_vectors_int(v1, v2, out);

    if(out == expected_output){
        std::cout << "passed" << std::endl;
    }
    else{
        std::cout << "not passed" << std::endl;
    }

    check({}, {}, {});
    check({1, 2, 3}, {}, {1, 2, 3});
    check({}, {4, 5}, {4, 5});
    check({1, 2, 3}, {4, 5, 6}, {1, 2, 3, 4, 5, 6});
    check({4, 5, 6}, {1, 2, 3}, {1, 2, 3, 4, 5, 6});
    check({1, 4, 7}, {2, 5, 8}, {1, 2, 4, 5, 7, 8});
    check({2, 2, 2}, {2, 2}, {2, 2, 2, 2, 2});
    check({-5, 0, 3}, {-7, -1, 10, 20}, {-7, -5, -1, 0, 3, 10, 20});
}
