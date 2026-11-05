#include <iostream>
#include <string>

void myswap(std::string& text1, std::string& text2){
    std::string tmp = text1;
    text1 = text2;
    text2 = tmp;
}

int main(){
    std::string text1, text2;
    std::cout << "Please enter the two text separately: " << std::endl;
    std::cin >> text1 >> text2;


    myswap(text1, text2);

    std::cout << "after swapping the values:" << std::endl;
    std::cout << "text1: " << text1 << std::endl;
    std::cout << "text2: " << text2 << std::endl;




}