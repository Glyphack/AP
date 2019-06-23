#include <iostream>
#include <bits/stdc++.h>


using std::cout;
using std::cin;
using std::string;
using std::endl;


bool CheckEquality(const string &t_string1, const string &t_string2);

int FindSubStrings(const string &t_string, const string &t_substring);


int main() {
    string s_string, substring;
    cin >> s_string >> substring;
    cout << FindSubStrings(s_string, substring);
    return 0;
}


int FindSubStrings(const string &t_string, const string &t_substring) {
    int streak = 0, finds_in_a_row = 0;
    for (unsigned long cursor = 0; cursor < t_string.length();) {
//        cout << "finding " << t_substring << " in " << t_string.substr(cursor, t_string.length()) << endl;
        if (CheckEquality(t_string.substr(cursor, t_substring.length()), t_substring)) {
            finds_in_a_row++;
//            cout << "found now finds_in_a_row: " << finds_in_a_row << endl;
            cursor = cursor + t_substring.length();

        } else {
            finds_in_a_row = 0;
            cursor++;
//            cout << "breaking.. " << "in a row: " << finds_in_a_row << " and streak:" << streak << endl;
        }
        if (finds_in_a_row > streak)
            streak = finds_in_a_row;
    }
    return streak;
}


bool CheckEquality(const string &t_string1, const string &t_string2) {
    return t_string1 == t_string2;
}