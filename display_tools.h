#include <iostream>

using namespace std;

void showVector(Vector b){
    cout << "[\t";
    for(int i=0; i<b.size(); i++){
        cout << b.at(i) << "\t";
    }
    cout << "]\n";
}

void showMatrix(Matrix k){
    for(int i=0; i<k.size(); i++){
        showVector(k.at(i));
    }
}