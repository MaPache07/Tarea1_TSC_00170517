#include <vector>
#include <math.h>
#include <stdlib.h>

using namespace std;

typedef vector<float> Vector;
typedef vector<Vector> Matrix;

void zeroes(Vector &v, int n){
    for(int i=0; i<n; i++)
        v.push_back(0.0);
}

void zeroes(Matrix &m, int n){
    for(int i=0; i<n; i++){
        Vector row(n, 0.0);
        m.push_back(row);
    }
}

void copyVector(Vector v, Vector &copy){
    zeroes(copy, v.size());
    for(int i=0; i<v.size(); i++){
        copy.at(i) = v.at(i);
    }
}

void copyMatrix(Matrix m, Matrix &copy){
    zeroes(copy, m.size());
    for(int i=0; i<m.size(); i++){
        for(int j=0; j<m.at(0).size(); j++){
            copy.at(i).at(j) = m.at(i).at(j);
        }
    }
}

void productMatrixVector(Matrix m, Vector v, Vector &R){
    for(int fila=0; fila<m.size(); fila++){
        float acum = 0.0;
        for(int col=0; col<v.size(); col++)
            acum += m.at(fila).at(col)*v.at(col);
        R.at(fila) = acum;
    }
}

void productRealMatrix(float n, Matrix m, Matrix &R){
    zeroes(R, m.size());
    for(int i=0; i<R.size(); i++){
        for(int j=0; j<R.at(0).size(); j++)
            R.at(i).at(j) = m.at(i).at(j)*n;
    }
}

Vector sumVector(Vector v1, Vector v2, int n){
    Vector R;
    zeroes(R, n);
    for(int i=0; i<n; i++){
        R.at(i) = v1.at(i)+v2.at(i);
    }
    return R;
}

Matrix sumMatrix(Matrix m1, Matrix m2, int n){
    Matrix R;
    zeroes(R, n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            R.at(i).at(j) = m1.at(i).at(j)+m2.at(i).at(j);
    }
    return R;
}

void transpose(Matrix m, Matrix &T){
    zeroes(T, m.size());
    for(int i=0; i<m.size(); i++){
        for(int j=0; j<m.size();j++){
            T.at(i).at(j) = m.at(j).at(i);
        }
    }
}

void getMinor(Matrix &m, int i, int j){
    m.erase(m.begin()+i);
    for(int k=0; k<m.size(); k++){
        m.at(k).erase(m.at(k).begin()+j);
    }
}

float determinant(Matrix m){
    if(m.size() == 1) return m.at(0).at(0);
    else{
        float det = 0.0;
        for(int i=0; i<m.at(0).size(); i++){
            Matrix aux;
            copyMatrix(m, aux);
            getMinor(aux, 0, i);
            det += pow(-1, i) * m.at(0).at(i)*determinant(aux);
        }
        return det;
    }
}

void cofactors(Matrix M, Matrix &Cof){
    zeroes(Cof,M.size());
    for(int i=0;i<M.size();i++){
        for(int j=0;j<M.at(0).size();j++){
            Matrix minor;
            copyMatrix(M,minor);
            getMinor(minor,i,j);
            Cof.at(i).at(j) = pow(-1,i+j)*determinant(minor);
        }
    }
}

void reverse(Matrix m, Matrix &rev){
    float det = determinant(m);
    if(det == 0){
        cout << "El determinante es cero, por lo que la matriz no tiene matriz inversa." << endl;
        exit(EXIT_FAILURE);
    }
    else{
        Matrix cof, adj;
        cofactors(m, cof);
        transpose(cof, adj);
        productRealMatrix(1/det, adj, rev);
    }
}
