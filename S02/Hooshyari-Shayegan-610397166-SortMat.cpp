#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int col = -1;

bool SortColumn( const vector<int>& v1,
                 const vector<int>& v2) {
    if (col == -1){
        cout << "enter column";
        cin >> col;
    }
    return v1[col] < v2[col];
}

int main()
{
    vector< vector<int> > matrix;
    int rows, columns;
    cout<<"enter row and coloumn";
    cin>>rows>>columns;
    for(int i = 0; i<rows; i++)
    {
        vector<int> row_vector;
        for(int j = 0; j<columns; j++)
        {
            int temp_value = 0;
            cout<<"Enter the number for Matrix";
            cin>>temp_value;
            row_vector.push_back(temp_value);
        }
        matrix.push_back(row_vector);
    }

    int sort_option;
    int m = matrix.size();
    int n = matrix[0].size();
    cout<<"enter the row you want to sort(starts from 0"
          "20"
          "0) or -1 to sort matrix based on a row";
    cin>>sort_option;
    cout << "The Matrix before sorting is:\n";
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n ;j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
    if (sort_option != -1)
        sort(matrix[sort_option].begin(), matrix[sort_option].end());
    else if(sort_option == -1){
        sort(matrix.begin(), matrix.end(),SortColumn);
    }


    cout << "The Matrix after sorting is:\n";
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n ;j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
    return 0;
}
