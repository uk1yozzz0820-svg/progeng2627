#include <iostream>

void myswap(double& n1, double& n2) {
    double tmp = n1;
    n1 = n2;
    n2 = tmp;
}
// function myswap to be used
// in sort_three_numbers below
// must be included here (beforehand)

void sort_three_numbers(double& s1, double& s2, double& s3){
    // step 1: put the smaller of s1, s2 first
    if(s1 > s2){
        myswap(s1, s2);
    }

    // step 2: push the largest number to s3
    if(s2 > s3){
        myswap(s2, s3);
    }

    // step 3: s3 is now the largest, so fix the order of s1, s2 again
    if(s1 > s2){
        myswap(s1, s2);
    }
}

int main(){
    double n1, n2, n3;
    std::cout << "please enter three numbers:" << std::endl;
    std::cin >> n1 >> n2 >> n3;
    sort_three_numbers(n1, n2, n3);
    std::cout << n1 << " " << n2 << " " << n3 << std::endl;
}
