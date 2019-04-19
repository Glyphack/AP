#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::vector;


void InitializeMatrix(int **matrix, int rows, int columns) {
    for (int row = 0; row < rows; row++) {
        matrix[row] = new int[columns];
    }
}


void FillMatrix(int **matrix, int matrix_rows, int matrix_columns) {
    for (int i = 0; i < matrix_rows; i++) {
        for (int j = 0; j < matrix_columns; j++) {
            cin >> matrix[i][j];
        }
    }
}


void TansorMultiply(int **t_matrix1,
                    int first_matrix_rows,
                    int first_matrix_columns,
                    int **t_matrix2,
                    int second_matrix_rows,
                    int second_matrix_columns,
                    int **result_matrix,
                    int result_matrix_rows,
                    int result_matrix_columns
) {
    int first_matrix_row_cursor = 0;
    int first_matrix_column_cursor = 0;
    int second_matrix_row_cursor = 0;
    int second_matrix_column_cursor = 0;
    for (int i = 0; i < result_matrix_rows; i++) {
        for (int j = 0; j < result_matrix_columns; j++) {
            if (first_matrix_column_cursor == first_matrix_columns - 1 &&
                second_matrix_column_cursor == second_matrix_columns &&
                second_matrix_row_cursor == second_matrix_rows - 1) {
                first_matrix_row_cursor++;
                first_matrix_column_cursor = 0;
                second_matrix_column_cursor = 0;
                second_matrix_row_cursor = 0;
//                cout<<"reached end of 2row \n";
            } else if (first_matrix_column_cursor == first_matrix_columns - 1 &&
                       second_matrix_column_cursor == second_matrix_columns) {
                first_matrix_column_cursor = 0;
                second_matrix_column_cursor = 0;
                second_matrix_row_cursor++;
//                cout<<"reached end of 1row \n";

            } else if (second_matrix_column_cursor == second_matrix_columns) {
                first_matrix_column_cursor++;
                second_matrix_column_cursor = 0;
//                cout<<"reached end of second_mat \n";
            }
//            cout << "setting resultmatrix[" << i << "][" << j << "] with : first matrix[" << first_matrix_row_cursor
//                 << "][" << first_matrix_column_cursor<< "] and second[" << "[" << second_matrix_row_cursor<< "]["
//                 << second_matrix_column_cursor<< "]"<<endl;
            result_matrix[i][j] =
                    t_matrix1[first_matrix_row_cursor][first_matrix_column_cursor] *
                    t_matrix2[second_matrix_row_cursor][second_matrix_column_cursor];
            second_matrix_column_cursor++;
        }
    }
}


int main() {
    int first_matrix_rows, first_matrix_columns, second_matrix_rows, second_matrix_columns;

    cin >> first_matrix_rows >> first_matrix_columns;
    int **matrix1 = new int *[first_matrix_rows];
    InitializeMatrix(matrix1, first_matrix_rows, first_matrix_columns);
    FillMatrix(matrix1, first_matrix_rows, first_matrix_columns);

    cin >> second_matrix_rows >> second_matrix_columns;
    int **matrix2 = new int *[second_matrix_rows];
    InitializeMatrix(matrix2, second_matrix_rows, second_matrix_columns);
    FillMatrix(matrix2, second_matrix_rows, second_matrix_columns);

    int result_matrix_rows = first_matrix_rows * second_matrix_rows;
    int result_matrix_columns = first_matrix_columns * second_matrix_columns;
    int **result_matrix = new int *[result_matrix_rows];
    InitializeMatrix(result_matrix, result_matrix_rows,
                     result_matrix_columns);
    TansorMultiply(
            matrix1,
            first_matrix_rows,
            first_matrix_columns,
            matrix2,
            second_matrix_rows,
            second_matrix_columns,
            result_matrix,
            result_matrix_rows,
            result_matrix_columns
    );
    for (int i = 0; i < result_matrix_rows; i++) {
        for (int j = 0; j < result_matrix_columns; j++) {
            cout << result_matrix[i][j] << " ";
        }
        if (i != result_matrix_rows - 1)
            cout << endl;
    }
    return 0;
}