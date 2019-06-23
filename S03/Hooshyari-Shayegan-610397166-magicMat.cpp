#include <iostream>

using namespace std;

void InitializeMatrix(int **matrix, int rows, int columns){
    for(int row=0;row<rows;row++)
        matrix[row] = new int[columns];
}

void GenerateMagicMatrix(int** magic_matrix, int size){

    int i = size/2;
    int j = size-1;

    for (int num=1; num <= size*size; )
    {
        if (i==-1 && j==size)
        {
            j = size-2;
            i = 0;
        }
        else
        {
            if (j == size)
                j = 0;

            if (i < 0)
                i=size-1;
        }
        if (magic_matrix[i][j])
        {
            j -= 2;
            i++;
            continue;
        }
        else
            magic_matrix[i][j] = num++;

        j++; i--;
    }
}

void PrintMatrix(int** matrix, int size){
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout<<matrix[i][j]<<" ";
        }
        if (i != size-1)
            cout<<"\n";
    }
}

int main(){
    int size;
    cin>>size;
    int **magic_matrix(new int* [size]);
    InitializeMatrix(magic_matrix, size, size);
    GenerateMagicMatrix(magic_matrix, size);
    PrintMatrix(magic_matrix, size);
}