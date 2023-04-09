//
// Created by Nijash Sooriya on 2023-04-08.
//
#include <iostream>
#include <vector>
#include "ComplexLib.h"

using namespace std;

vector<vector<int>> triples(){
    vector<vector<int>> result;
    for(int i = 2; i < 10; i++){
        Complex n1(1, i);
        vector<int> temp;
        Complex resultant = multiply(n1, n1);
        temp.push_back(abs(getReal(resultant)));
        temp.push_back(abs(getImag(resultant)));
        temp.push_back(getMag(resultant));
        result.push_back(temp);
    }



    return result;
}

//int main(){
/*
    vector<vector<int>> return_vect = triples();
    for(int i = 0; i < return_vect.size(); i++){
        std::cout << return_vect[i][0] << ", " << return_vect[i][1] << ", " << return_vect[i][2] << '\n';
    }

}*/
