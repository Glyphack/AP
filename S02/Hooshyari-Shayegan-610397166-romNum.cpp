#include <iostream>
#include <vector>

using namespace std;

vector<string> ConvertToRomeNumber(int t_number) {
    vector<string> rome_number;
    int m, d, c, l, x, v, i, n;
    if (t_number >= 1000) {
        m = t_number / 1000;
        n = 0;
        {
            for (n; n < m; n++)
                rome_number.emplace_back("M");
        }
        t_number = t_number % 1000;
    }

    if (t_number >= 900) {
        rome_number.emplace_back("CM");
        t_number = t_number % 900;
    } else if (t_number >= 500) {
        {
            d = t_number / 500;
            n = 0;
            for (n; n < d; n++)
                rome_number.emplace_back("D");
        }
        t_number = t_number % 500;
    }

    if (t_number >= 400) {
        rome_number.emplace_back("CD");
        t_number = t_number % 400;
    } else if (t_number >= 100) {
        {
            c = t_number / 100;
            n = 0;
            for (n; n < c; n++)
                rome_number.emplace_back("C");
        }
        t_number = t_number % 100;
    }

    if (t_number >= 90) {
        rome_number.emplace_back("XC");
        t_number = t_number % 90;
    } else if (t_number >= 50) {
        {
            l = t_number / 50;
            n = 0;
            for (n; n < l; n++)
                rome_number.emplace_back("L");
        }
        t_number = t_number % 50;
    }
    if (t_number >= 40) {
//        cout << "XL";
        rome_number.emplace_back("XL");
        t_number = t_number % 40;
    } else if (t_number >= 10) {
        {
            x = t_number / 10;
            n = 0;
            for (n; n < x; n++)
//                cout << "X";
                rome_number.emplace_back("X");
        }
        t_number = t_number % 10;
    }

    if (t_number >= 9) {
//        cout << "IX";
        rome_number.emplace_back("IX");
        t_number = t_number % 9;
    } else if (t_number >= 5) {
        {
            v = t_number / 5;
            n = 0;
            for (n; n < v; n++)
//                cout << "V";
                rome_number.emplace_back("V");
        }
        t_number = t_number % 5;
    }
    if (t_number >= 4) {
//        cout << "IV";
        rome_number.emplace_back("IV");

        t_number = t_number % 4;
    } else if (t_number >= 1) {
        i = t_number;
        n = 0;
        for (n; n < i; n++)
//            cout << "I";
            rome_number.emplace_back("I");

    }
    return rome_number;
}

int ValueOfRomanNumber(vector<string> roman_number) {
    int value = 0;
    for (int i = 0; i < roman_number.size(); i++) {
//        cout << "checking index " << i << "with value" << roman_number[i] << endl;
        if (roman_number[i] == "I")
            value += 1;
        if (roman_number[i] == "IV")
            value += 4;
        if (roman_number[i] == "V")
            value += 5;
        if (roman_number[i] == "IX")
            value += 9;
        if (roman_number[i] == "X")
            value += 10;
        if (roman_number[i] == "XL")
            value += 40;
        if (roman_number[i] == "L")
            value += 50;
        if (roman_number[i] == "XC")
            value += 90;
        if (roman_number[i] == "C")
            value += 100;
        if (roman_number[i] == "CD")
            value += 400;
        if (roman_number[i] == "D")
            value += 500;
        if (roman_number[i] == "CM")
            value += 900;
        if (roman_number[i] == "M")
            value += 1000;

    }
    return value;
}

vector<string> SumTwoRomanNumbers(vector<string> t_first_number, vector<string> t_second_number) {
    vector<string> sum_result_roman;
    return ConvertToRomeNumber(ValueOfRomanNumber(t_first_number) + ValueOfRomanNumber(t_second_number));
}

int main() {

    int first_number, second_number;
    vector<string> first_number_roman, second_number_roman;
    cin >> first_number >> second_number;
    first_number_roman = ConvertToRomeNumber(first_number);
    second_number_roman = ConvertToRomeNumber(second_number);
    for (const string &i:first_number_roman)
        cout << i;
    cout << " ";
    for (const string &i:second_number_roman)
        cout << i;
    cout << endl;
    vector<string> sum_result = SumTwoRomanNumbers(first_number_roman, second_number_roman);
    for (const string &i:sum_result)
        cout << i;

    return 0;
}