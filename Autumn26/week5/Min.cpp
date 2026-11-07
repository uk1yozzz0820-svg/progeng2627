#include <iostream>
#include <vector>

int min_vector_element(const std::vector<double>& vin){
    if(vin.size() == 0){
        return -1;
    }

    int index = 0;
    // assume the first element is the smallest

    for(int i = 1; i < vin.size(); i++){
        if(vin[i] < vin[index]){
            index = i;
        }
    }

    return index;
}

int main(){
    std::vector<double> empty;
    std::cout << "empty vector: " << min_vector_element(empty) << " (expected -1)" << std::endl;

    std::vector<double> one;
    one.push_back(7);
    std::cout << "one element: " << min_vector_element(one) << " (expected 0)" << std::endl;

    std::vector<double> first;
    first.push_back(1);
    first.push_back(5);
    first.push_back(3);
    std::cout << "min at the start: " << min_vector_element(first) << " (expected 0)" << std::endl;

    std::vector<double> middle;
    middle.push_back(5);
    middle.push_back(1);
    middle.push_back(3);
    middle.push_back(2);
    std::cout << "min in the middle: " << min_vector_element(middle) << " (expected 1)" << std::endl;

    std::vector<double> last;
    last.push_back(5);
    last.push_back(3);
    last.push_back(1);
    std::cout << "min at the end: " << min_vector_element(last) << " (expected 2)" << std::endl;

    std::vector<double> negative;
    negative.push_back(2.5);
    negative.push_back(-4);
    negative.push_back(0);
    std::cout << "negative numbers: " << min_vector_element(negative) << " (expected 1)" << std::endl;

    std::vector<double> twice;
    twice.push_back(3);
    twice.push_back(1);
    twice.push_back(4);
    twice.push_back(1);
    std::cout << "min appears twice: " << min_vector_element(twice) << " (expected 1)" << std::endl;
}
