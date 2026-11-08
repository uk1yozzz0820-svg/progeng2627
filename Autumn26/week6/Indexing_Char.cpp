#include <iostream>
#include <string>

int count_occurrences(std::string s, char letter){
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
    char letter = 'l';
    std::cout << "there are " << count_occurrences(s, letter) << " occurrences of " << letter << " in " << s << std::endl;

}
