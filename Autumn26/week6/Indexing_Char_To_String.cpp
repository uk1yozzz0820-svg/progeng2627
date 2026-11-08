#include <iostream>
#include <string>

std::string char_to_string(char c){
    std::string s;
    s.push_back(c);
    return s;
}

int count_occurrences(std::string s, std::string letter){
    int out = 0;
    for(int i = 0; i < s.size(); i++){
        if(char_to_string(s[i]) == letter){
            out++;
        }
    }
    return out;
}

int main(){

    std::string s = "hello";
    std::string letter = "l";
    std::cout << "there are " << count_occurrences(s, letter) << " occurrences of " << letter << " in " << s << std::endl;

}
