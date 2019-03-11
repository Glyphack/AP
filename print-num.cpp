#include <iostream>
#include <string>
#include <vector>

using namespace std;


vector<string> ones{"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
vector<string> teens{"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen",
                     "nineteen"};
vector<string> tens{"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

string NameForNumber(int t_number) {
  if (t_number < 10) {
    return ones[t_number];
  } else if (t_number < 20) {
    return teens[t_number - 10];
  } else if (t_number < 100) {
    return tens[t_number / 10] + ((t_number % 10 != 0) ? " " + NameForNumber(t_number % 10) : "");
  } else if (t_number < 1000) {
    return NameForNumber(t_number / 100) + " hundred" +
           ((t_number % 100 != 0) ? " " + NameForNumber(t_number % 100) : "");
  } else if (t_number < 1000000) {
    return NameForNumber(t_number / 1000) + " thousand" +
           ((t_number % 1000 != 0) ? " " + NameForNumber(t_number % 1000) : "");
  } else if (t_number < 1000000000) {
    return NameForNumber(t_number / 1000000) + " million" +
           ((t_number % 1000000 != 0) ? " " + NameForNumber(t_number % 1000000) : "");
  } else if (t_number < 1000000000000) {
    return NameForNumber(t_number / 1000000000) + " billion" +
           ((t_number % 1000000000 != 0) ? " " + NameForNumber(t_number % 1000000000) : "");
  } else if (t_number < 1000000000000000) {
    return NameForNumber(t_number / 1000000000000) + " trillion" +
           ((t_number % 1000000000000 != 0) ? " " + NameForNumber(t_number % 1000000000000) : "");
  } else if (t_number < 1000000000000000) {
    return NameForNumber(t_number / 1000000000000000) + " quadrillion" +
           ((t_number % 1000000000000000 != 0) ? " " + NameForNumber(t_number % 1000000000000000) : "");
  } else if (t_number < 1000000000000000000) {
    return NameForNumber(t_number / 1000000000000000000) + " quintillion" +
           ((t_number % 1000000000000000000 != 0) ? " " + NameForNumber(t_number % 1000000000000000000) : "");
  }
  return "error";
}

int main() {
  int number;
  cin >> number;
  cout << "\n" << NameForNumber(number) << endl;
  return 0;
}