// complete the function definitions
#include "../include/matrix.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

void fileIO(std::string filename, int A[][AR_CAP], int& n1, int& m1, int B[][AR_CAP], int& n2, int& m2) {

    std::ifstream inFile;
    inFile.open(filename);

    inFile >> n1 >> m1;

    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < m1; ++j) {
            inFile >> A[i][j];
        }
    }
    
    inFile >> n2 >> m2;

    for (int i = 0; i < n2; ++i) {
        for (int j = 0; j < m2; ++j) {
            inFile >> B[i][j];
        }
    }
    inFile.close();
}


void matrixAddition(const int A[][AR_CAP], int n1, int m1, const int B[][AR_CAP], int n2, int m2, int res[][AR_CAP]){
    if(n1 != n2 || m1 != m2){
        std::cout << "Not the same size";
    }

    for (int i = 0; i < n1; ++i)
        for (int j = 0; j < m1; ++j)
            res[i][j] = A[i][j] + B[i][j];
}

void matrixSubtraction(int A[][AR_CAP], int n1, int m1, int B[][AR_CAP], int n2, int m2, int res[][AR_CAP]){
    if(n1 != n2 || m1 != m2){
        std::cout << "Not the same size!";
    }
    
    for (int i = 0; i < n1; ++i)
        for (int j = 0; j < m1; ++j)
            res[i][j] = A[i][j] - B[i][j];
}

void matrixMultiplication(int A[][AR_CAP], int n1, int m1, int B[][AR_CAP], int n2, int m2, int res[][AR_CAP]){
    if(n1 != m2){
        std::cout << "Matrix multiplication doesn't work!";
    }

    for (int i = 0; i < n1; ++i)
        for (int j = 0; j < m2; ++j)
            res[i][j] = 0;

    for (int i = 0; i < n1; ++i)
        for (int j = 0; j < m2; ++j)
            for (int k = 0; k < m1; ++k)
                res[i][k] += A[i][j] * B[j][k];


}

void matrixTranspose(int M[][AR_CAP], int n, int m, int res[][AR_CAP]){
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            res[j][i] = M[i][j];  
}

double matrixDeterminant3D(int M[3][3]){
    double determinant = 0.0;
    determinant = M[0][0] * (M[1][1]*M[2][2]- M[1][2] * M[2][1]) - M[0][1] * (M[1][0]*M[2][2] - M[1][2]*M[2][0]) + M[0][2] * (M[1][0]*M[2][1] - M[1][1]*M[2][0]);
    return determinant;
}

void print2DMatrix(const int M[][AR_CAP], int n1, int m1){
    for (int i = 0; i < n1; ++i){
        for (int j = 0; j < m1; ++j){
            cout << M[i][j] << " ";
        }   
        cout << endl;
    }        
}


