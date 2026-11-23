#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

int main(int argc, char* argv[]){
    if(argc != 2){
        std::cout << "usage: " << argv[0] << " <filename>" << std::endl;
        return EXIT_FAILURE;
    }

    std::ifstream infile;
    infile.open(argv[1]);

    if(!infile.is_open()){
        std::cout << "error opening " << argv[1] << std::endl;
        return EXIT_FAILURE;
    }

    std::string line;
    while(std::getline(infile, line)){
        std::cout << line << std::endl;
    }

    infile.close();
}
