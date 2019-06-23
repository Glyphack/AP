#include<bits/stdc++.h>
#define Row 6
#define Col 6
using namespace std;

int LargestKSubmatrix(int a[][Col])
{
    int dp[Row][Col];
    memset(dp, sizeof(dp), 0);

    int result = 0;
    for (int i = 0 ; i < Row ; i++)
    {
        for (int j = 0 ; j < Col ; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 1;

            else
            {
                if (a[i][j] == a[i-1][j] &&
                    a[i][j] == a[i][j-1] &&
                    a[i][j] == a[i-1][j-1] )
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]),
                                   dp[i-1][j-1] ) + 1;

                else dp[i][j] = 1;
            }

            result = max(result, dp[i][j]);
        }
    }

    return result;
}

int main() {
    int a[Row][Col];
    for (auto &i : a)
        for (int &j : i) {
            int random_number = rand() % 101;
            j = random_number;
        }
    for(auto & i : a){
        for (int &j : i) {
            cout << j << " ";
        }
        cout<<"\n";
    }
    cout << LargestKSubmatrix(a) << endl;

    return 0;
}