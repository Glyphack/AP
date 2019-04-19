#include <iostream>

using namespace std;

void InitializeMatrix(int **matrix, int rows, int columns){
    for(int row=0;row<rows;row++)
        matrix[row] = new int[columns];
}

void GenerateMagicMatrix(int** matrix, int** magic_matrix, int size){

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            magic_matrix[i][j] = matrix[j][(i + j) % size];
        }
    }
}

void PrintMatrix(int** matrix, int size){
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void FillMatrix(int **matrix, int size){
    int c = 1;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = c;
            c++;
        }
    }
}

int main(){
    int size;
    cin>>size;
    int **matrix(new int* [size]), **magic_matrix(new int* [size]);
    InitializeMatrix(magic_matrix, size, size);
    InitializeMatrix(matrix, size, size);
    FillMatrix(matrix, size);
    GenerateMagicMatrix(matrix, magic_matrix, size);
    PrintMatrix(magic_matrix, size);
}