#include <iostream>

using std::cout;
using std::cin;
using std::string;


void InitializeMatrix(int **matrix, int rows, int columns){
    for(int row=0;row<rows;row++)
        matrix[row] = new int[columns];
}


void FillMatrix(int **matrix, int rows, int columns){
    for(int row=0; row<rows; row++)
        for(int column=0; column<columns; column++){
            cin>>matrix[row][column];
        }
}

void DestroyMatrix(int** matrix, int rows){
    for(int i = 0; i < rows; i++)
        delete [] matrix[i];
    delete [] matrix;
}


void PrintMatrix(int ** matrix, int rows, int columns){
    for(int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++)
            std::cout << matrix[i][j]<< " ";
        cout << "\n";
    }
}


bool MatrixEquals(int ** first_matrix, int** second_matrix, int rows, int columns) {
    for (int row = 0; row < rows; row++)
        for (int column = 0; column < columns; column++) {
            if (first_matrix[row][column] == second_matrix[row][column])
                continue;
            else {
                return false;
            }
        }
    return true;
}


void SliceMatrix(int** sliced_matrix, int** matrix, int start_row, int row_length, int start_column, int column_length){
    for(int row=start_row; row<start_row+row_length;row++)
        for(int column=start_column;column<start_column+column_length;column++)
            sliced_matrix[row - start_row][column - start_column] = matrix[row][column];
}


bool MatrixContains(int ** matrix, int** sub_matrix,int matrix_rows,int matrix_columns, int sub_matrix_rows, int sub_matrix_columns ){
    int row=0, column=0;
    int** sliced_matrix = new int* [sub_matrix_rows];
    InitializeMatrix(sliced_matrix, sub_matrix_rows, sub_matrix_columns);
    while(row<matrix_rows){
        column = 0;
        while (column<matrix_columns){
            SliceMatrix(sliced_matrix, matrix, row, sub_matrix_rows, column, sub_matrix_columns);
            cout<<"checking matrix \n";
            PrintMatrix(sliced_matrix, sub_matrix_rows, sub_matrix_columns);
            if(MatrixEquals(sliced_matrix, sub_matrix, sub_matrix_rows, sub_matrix_columns))
                return true;
            if(column+1+sub_matrix_columns<=matrix_columns)
                column++;
            else
                break;
        }
        if(row+1+sub_matrix_rows<=matrix_rows)
            row++;
        else
            break;
    }
    return false;
}


int main() {
    int matrix_rows, matrix_columns, sub_matrix_rows, sub_matrix_columns;
    cin>>matrix_rows>>matrix_columns>>sub_matrix_rows>>sub_matrix_columns;
    int** matrix = new int* [matrix_rows];
    int ** sub_matrix = new int*[sub_matrix_rows];
    InitializeMatrix(matrix, matrix_rows, matrix_columns);
    FillMatrix(matrix, matrix_rows, matrix_columns);
    InitializeMatrix(sub_matrix, sub_matrix_rows, sub_matrix_columns);
    FillMatrix(sub_matrix, sub_matrix_rows, sub_matrix_columns);
    PrintMatrix(matrix, matrix_rows, matrix_columns);
    PrintMatrix(sub_matrix, sub_matrix_rows, sub_matrix_columns);
    cout<<MatrixContains(matrix, sub_matrix, matrix_rows, matrix_columns, sub_matrix_rows, sub_matrix_columns);
    DestroyMatrix(matrix, matrix_rows);
    DestroyMatrix(sub_matrix, sub_matrix_rows);
    return 0;
}