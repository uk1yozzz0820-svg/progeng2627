#include <iostream>
#include <string>

int count_occurrences(std::string s, std::string letter){
    int out = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == letter){
            out++;
        }
    }
    return out;
}

int main(){

    std::string s = "hello";
    std::string letter = "l";
    std::cout << "there are " << count_occurrences(s, letter) << " of " << letter << " in " << s << std::endl;

}
