#include <iostream>

using std::cin;
using std::cout;
using std::string;

bool IsPalindrome(string t_string);
string FindBiggestPalindromeSubString(const string &t_string, unsigned long n);

int main(){
    string source_string;
    cin>>source_string;
    cout<<FindBiggestPalindromeSubString(source_string, source_string.length());
    return 0;
}

string FindBiggestPalindromeSubString(const string &t_string, unsigned long n){
    string biggest_palindrome_subset, substring;
    for (unsigned long i = 0; i < n; i++)
        for (unsigned long len = 1; len <= n - i; len++){
            substring = t_string.substr(i, len);
            if (IsPalindrome(substring) && substring.length() > biggest_palindrome_subset.length()) {
                biggest_palindrome_subset = substring;
            }
        }
    return biggest_palindrome_subset;
}


bool IsPalindrome(string t_string){
    for(std::string::size_type i = 0; i < t_string.size(); ++i) {
        if (t_string[i] != t_string[t_string.size()-1-i])
            return false;
    }
    return true;
}