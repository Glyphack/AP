#include <iostream>
using namespace std;

int size, knights;
int count = 0;

void MakeBoard(int **board)
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            board[i][j] = 0;
        }
    }
}

void InitializeMatrix(int **matrix, int rows, int columns){
    for(int row=0;row<rows;row++)
        matrix[row] = new int[columns];
}

void DisplayBoard(int **board)
{
    cout << endl
         << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << " " << board[i][j] << " ";
        }
        cout << endl;
    }
}

void Attack(int i, int j, int a,
            int **board)
{
    if ((i + 2) < size && (j - 1) >= 0) {
        board[i + 2][j - 1] = a;
    }
    if ((i - 2) >= 0 && (j - 1) >= 0) {
        board[i - 2][j - 1] = a;
    }
    if ((i + 2) < size && (j + 1) < size) {
        board[i + 2][j + 1] = a;
    }
    if ((i - 2) >= 0 && (j + 1) < size) {
        board[i - 2][j + 1] = a;
    }
    if ((i + 1) < size && (j + 2) < size) {
        board[i + 1][j + 2] = a;
    }
    if ((i - 1) >= 0 && (j + 2) < size) {
        board[i - 1][j + 2] = a;
    }
    if ((i + 1) < size && (j - 2) >= 0) {
        board[i + 1][j - 2] = a;
    }
    if ((i - 1) >= 0 && (j - 2) >= 0) {
        board[i - 1][j - 2] = a;
    }
}

bool CanPlace(int i, int j, int **board)
{
    return board[i][j] == 0;
}

void Place(int i, int j, int knights, int a,
           int **board, int **new_board)
{

    for (int y = 0; y < size; y++) {
        for (int z = 0; z < size; z++) {
            new_board[y][z] = board[y][z];
        }
    }
    new_board[i][j] = knights;
    Attack(i, j, a, new_board);
}


void SolveNKnights(int knights, int sti, int stj, int **board)
{

    if (knights == 0) {
        DisplayBoard(board);
        count++;
    }
    else {
        for (int i = sti; i < size; i++) {
            for (int j = stj; j < size; j++) {
                if (CanPlace(i, j, board)) {
                    int** new_board = new int*[size];
                    InitializeMatrix(new_board, size, size);
                    Place(i, j, 1, 2, board, new_board);
                    SolveNKnights(knights - 1, i, j, new_board);
                    for (int x = 0; x < size; x++) {
                        delete[] new_board[x];
                    }
                    delete[] new_board;
                }
            }
            stj = 0;
        }
    }
}


int main()
{
    cin>>knights;
    size = knights;
    int** board = new int*[size];
    InitializeMatrix(board, size, size);
    MakeBoard(board);
    SolveNKnights(knights, 0, 0, board);
    cout << endl
         << "Total number of solutions : "
         << count;
    return 0;
}
