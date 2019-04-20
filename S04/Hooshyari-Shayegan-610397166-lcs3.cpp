#include <iostream>

using std::cin;
using std::cout;
using std::string;


int max(int t_number1, int t_number2){
    return t_number1 >= t_number2 ? t_number1 : t_number2;
}


int LcsOfThree(string t_string1, string t_string2, string t_string3){
    unsigned long int
            string1_length = t_string1.length(),
            string2_length = t_string2.length(),
            string3_length = t_string2.length();

    int lcs[string1_length+1][string2_length+1][string3_length+1];

    for (int i=0;i<=string1_length;i++)
        for(int j=0;j<=string2_length;j++)
            for(int k=0;k<=string3_length;k++){
                if (i==0 || j==0|| k==0)
                    lcs[i][j][k] = 0;
                else if (t_string1[i-1] == t_string2[j-1] == t_string3[k-1])
                    lcs[i][j][k] = lcs[i-1][j-1][k-1] + 1;
                else
                    lcs[i][j][k] = max(max(lcs[i-1][j][k], lcs[i][j-1][k]),
                                       lcs[i][j][k-1]);
            }
    return lcs[string1_length][string2_length][string3_length];
}

int main(){
    string s1, s2, s3;
    cin>>s1>>s2>>s3;
    cout<<LcsOfThree(s1, s2, s3);
}