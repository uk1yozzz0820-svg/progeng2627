#include <iostream>
#include <vector>

int main(){
    std::vector<int> Sequence;
    int size,n, i = 0;

    std::cout << "Please enter the size of the sequence" << std::endl;
    std::cin >> size;

    std::cout << "Please enter " << size << " numbers for the sequence: " << std::endl;

    while(i < size){
        std::cin >> n;
        Sequence.push_back(n);
        i++;
    }

    int t,tmp;
    std:: cout << "Please enter the number you want to compare with all the elements in the sequence" << std::endl;
    std:: cin >> t;

    for(int counter = 0; counter < size; counter++){
        tmp = Sequence[counter];
        if(tmp < t){
            std::cout << tmp << std::endl;
        }
    }









}