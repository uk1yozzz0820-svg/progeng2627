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

bool read_meanings(std::string filename, std::vector<std::string>& words, std::vector<std::string>& meanings){
    std::ifstream infile;
    infile.open(filename);

    if(!infile.is_open()){
        return false;
    }

    std::string w, m;
    while(infile >> w >> m){
        words.push_back(w);
        meanings.push_back(m);
    }

    infile.close();
    return true;
}

int search_vector(std::string s, const std::vector<std::string>& vin){
    for(int i = 0; i < vin.size(); i++){
        if(vin[i] == s){
            return i;
        }
    }

    return -1;
}

void translate(const std::vector<std::string>& ad, const std::vector<std::string>& words, const std::vector<std::string>& meanings, std::vector<std::string>& translated){
    translated.clear();

    for(int i = 0; i < ad.size(); i++){
        int index = search_vector(ad[i], words);

        if(index == -1){
            translated.push_back(ad[i]);
        }
        else{
            translated.push_back(meanings[index]);
        }
    }
}

int main(){
    std::string adfilename, meaningsfilename, outputfilename;

    std::cout << "enter name of advertisement file" << std::endl;
    std::cin >> adfilename;
    std::cout << "enter name of meanings file" << std::endl;
    std::cin >> meaningsfilename;

    std::vector<std::string> ad, words, meanings;

    if(!read_words(adfilename, ad)){
        std::cout << "error opening " << adfilename << std::endl;
        return EXIT_FAILURE;
    }

    if(!read_meanings(meaningsfilename, words, meanings)){
        std::cout << "error opening " << meaningsfilename << std::endl;
        return EXIT_FAILURE;
    }

    std::vector<std::string> translated;
    translate(ad, words, meanings, translated);

    std::cout << "enter name of output file" << std::endl;
    std::cin >> outputfilename;

    std::ofstream outfile;
    outfile.open(outputfilename);

    if(!outfile.is_open()){
        std::cout << "error opening " << outputfilename << std::endl;
        return EXIT_FAILURE;
    }

    for(int i = 0; i < translated.size(); i++){
        if(i > 0){
            outfile << " ";
        }
        outfile << translated[i];
    }
    outfile << std::endl;

    outfile.close();
}
