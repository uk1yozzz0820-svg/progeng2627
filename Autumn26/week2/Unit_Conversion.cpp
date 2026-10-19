#include <iostream>
#include <string>

int main(){
    double temp_in,temp_out;
    std::string unit_in,unit_out;

    std::cin >> temp_in >> unit_in;

    bool valid_unit = true;


    if((unit_in == "C")||(unit_in == "c")){
        temp_out = temp_in * 1.8 + 32;
        unit_out = "F";
    }
    else if((unit_in == "F")||(unit_in == "f")){
        temp_out = (temp_in - 32) / 1.8;
        unit_out = "C";
    }
    else{
        valid_unit = false;
    }

    if(valid_unit){
        std::cout << temp_out << " " << unit_out << std::endl;
    }
    else{
        std::cout << "Error, unit not recognised" << std::endl;
    }
}