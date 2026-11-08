#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>

bool read_words(std::string filename, std::vector<std::string>& v){
    std::ifstream infile;
    infile.open(filename);

    if(!infile.is_open()){
        return false;
    }

    std::string tmp;
    while(infile >> tmp){
        v.push_back(tmp);
    }

    infile.close();
    return true;
}

int count_occurrences(std::string word, const std::vector<std::string>& text){
    int count = 0;

    for(int i = 0; i < text.size(); i++){
        if(text[i] == word){
            count++;
        }
    }

    return count;
}

int main(){
    std::string textfilename, wordsfilename, outputfilename;

    std::cout << "enter name of text file" << std::endl;
    std::cin >> textfilename;
    std::cout << "enter name of words file" << std::endl;
    std::cin >> wordsfilename;

    std::vector<std::string> text, words;

    if(!read_words(textfilename, text)){
        std::cout << "error opening " << textfilename << std::endl;
        return EXIT_FAILURE;
    }

    if(!read_words(wordsfilename, words)){
        std::cout << "error opening " << wordsfilename << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "enter name of output file" << std::endl;
    std::cin >> outputfilename;

    std::ofstream outfile;
    outfile.open(outputfilename);

    if(!outfile.is_open()){
        std::cout << "error opening " << outputfilename << std::endl;
        return EXIT_FAILURE;
    }

    for(int i = 0; i < words.size(); i++){
        outfile << words[i] << ": " << count_occurrences(words[i], text) << std::endl;
    }

    outfile.close();
}
