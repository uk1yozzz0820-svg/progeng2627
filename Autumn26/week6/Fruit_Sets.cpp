#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>

int search_vector(std::string s, const std::vector<std::string>& vin){
    for(int i = 0; i < vin.size(); i++){
        if(vin[i] == s){
            return i;
        }
    }

    return -1;
}

void union_vector(const std::vector<std::string>& vin1, const std::vector<std::string>& vin2, std::vector<std::string>& vout){
    vout.clear();

    for(int i = 0; i < vin1.size(); i++){
        if(search_vector(vin1[i], vout) == -1){
            vout.push_back(vin1[i]);
        }
    }

    for(int i = 0; i < vin2.size(); i++){
        if(search_vector(vin2[i], vout) == -1){
            vout.push_back(vin2[i]);
        }
    }
}

void intersection_vector(const std::vector<std::string>& vin1, const std::vector<std::string>& vin2, std::vector<std::string>& vout){
    vout.clear();

    for(int i = 0; i < vin1.size(); i++){
        if(search_vector(vin1[i], vin2) != -1 && search_vector(vin1[i], vout) == -1){
            vout.push_back(vin1[i]);
        }
    }
}

bool read_file(std::string filename, std::vector<std::string>& v){
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

bool write_file(std::string filename, const std::vector<std::string>& v){
    std::ofstream outfile;
    outfile.open(filename);

    if(!outfile.is_open()){
        return false;
    }

    for(int i = 0; i < v.size(); i++){
        outfile << v[i] << std::endl;
    }

    outfile.close();
    return true;
}

int main(){
    std::string filename1, filename2;

    std::cout << "enter name of first input file" << std::endl;
    std::cin >> filename1;
    std::cout << "enter name of second input file" << std::endl;
    std::cin >> filename2;

    std::vector<std::string> warehouse1, warehouse2;

    if(!read_file(filename1, warehouse1)){
        std::cout << "error opening " << filename1 << std::endl;
        return EXIT_FAILURE;
    }

    if(!read_file(filename2, warehouse2)){
        std::cout << "error opening " << filename2 << std::endl;
        return EXIT_FAILURE;
    }

    std::vector<std::string> u, in;
    union_vector(warehouse1, warehouse2, u);
    intersection_vector(warehouse1, warehouse2, in);

    if(!write_file("union.txt", u) || !write_file("intersection.txt", in)){
        std::cout << "error opening output file" << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "union written to union.txt" << std::endl;
    std::cout << "intersection written to intersection.txt" << std::endl;
}
