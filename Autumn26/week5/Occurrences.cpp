#include <iostream>
#include <vector>

int main(){
    std::vector<int> Sequence;
    int size,n, i = 0;

    std::cout << "please enter n:" << std::endl;
    std::cin >> size;

    while(i < size){
        std::cout << "please enter a number:" << std::endl;
        std::cin >> n;
        Sequence.push_back(n);
        i++;
    }

    int s,tmp,occ = 0;
    std::vector<int> indices;
    std::cout << "please enter s:" << std::endl;
    std::cin >> s;

    for(int counter = 0; counter < size; counter++){
        tmp = Sequence[counter];
        if(tmp == s){
            occ++;
            indices.push_back(counter);
        }
    }

    if(occ == 0){
        std::cout << "there are no occurrences of " << s << std::endl;
    }
    else{
        std::cout << "there are " << occ << " occurrences of " << s << " at indices:" << std::endl;
        for(int j = 0; j < occ; j++){
            std::cout << indices[j] << std::endl;
        }
    }
}
