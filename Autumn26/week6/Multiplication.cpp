#include <iostream>
#include <vector>

double scalar_product(const std::vector<double>& v1, const std::vector<double>& v2){
    double sum = 0;

    for(int i = 0; i < v1.size(); i++){
        sum = sum + v1[i] * v2[i];
    }

    return sum;
}

std::vector<double> extract_column(const std::vector<std::vector<double>>& m, int c){
    std::vector<double> column;

    for(int i = 0; i < m.size(); i++){
        column.push_back(m[i][c]);
    }

    return column;
}

std::vector<std::vector<double>> matrix_multiplication(const std::vector<std::vector<double>>& m1, const std::vector<std::vector<double>>& m2){
    std::vector<std::vector<double>> result;

    for(int i = 0; i < m1.size(); i++){
        std::vector<double> row;

        for(int j = 0; j < m2[0].size(); j++){
            std::vector<double> column = extract_column(m2, j);
            row.push_back(scalar_product(m1[i], column));
        }

        result.push_back(row);
    }

    return result;
}

void print_matrix(const std::vector<std::vector<double>>& m){
    for(int i = 0; i < m.size(); i++){
        for(int j = 0; j < m[i].size(); j++){
            std::cout << m[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main(){
    std::vector<std::vector<double>> m1 = {
        {1, 2, 3},
        {4, 5, 6}
    };

    std::vector<std::vector<double>> m2 = {
        {7, 8},
        {9, 10},
        {11, 12}
    };

    std::vector<std::vector<double>> result = matrix_multiplication(m1, m2);

    print_matrix(result);
}
