#include <iostream>

int main(){
    std::string s;
    std::cin >> s;

    for(int i = 0; i < s.size(); i++){
        std::cout << s[i] << std::endl;
    }

}
