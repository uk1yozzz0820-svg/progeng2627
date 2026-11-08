#include <iostream>
#include <string>
#include <vector>

#include <utility>

std::string char_to_string(char c){
    std::string s;
    s.push_back(c);
    return s;
}

bool is_palindrome(std::string s){
    std::string letters;
    for(int i = 0; i < s.size(); i++){
        if(char_to_string(s[i]) != " "){
            letters.push_back(s[i]);
        }
    }

    int n = letters.size();
    for(int i = 0; i < n / 2; i++){
        if(letters[i] != letters[n - 1 - i]){
            return false;
        }
    }

    return true;
}

int main(){

    std::vector<std::pair<std::string, bool>> test_cases =
    {
        {"a man a plan a canal panama", true},
        {"a man plan a canal panama", false},
        {"a toyota", true},
        {"never odd or even", true},
        {"never even or odd", false}
    };

    for(int i = 0; i < test_cases.size(); i++){
        bool test = is_palindrome(test_cases[i].first);

        if(test == test_cases[i].second){
            std::cout << "passed" << std::endl;
        }
        else{
            std::cout << "FAILED" << std::endl;
            std::cout << test_cases[i].first << std::endl;
            std::cout << "expected: " << test_cases[i].second << std::endl;
            std::cout << "got: " << test << std::endl;
        }
    }
}
