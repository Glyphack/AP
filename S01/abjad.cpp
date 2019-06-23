#include <iostream>
#include <map>

using std::map;
using std::string;
using std::cin;
using std::cout;

map<string, int> abjad_list = {
        {"aa", 1},
        {"bb", 2},
        {"gg", 3},
        {"dd", 4},
        {"hh", 5},
        {"vv", 6},
        {"zz", 7},
        {"ha", 8},
        {"tt", 9},
        {"yy", 10},
        {"kk", 20},
        {"ll", 30},
        {"mm", 40},
        {"nn", 50},
        {"ss", 60},
        {"ae", 70},
        {"ff", 80},
        {"sa", 90},
        {"gh", 100},
        {"rr", 200},
        {"sh", 300},
        {"ta", 400},
        {"sb", 500},
        {"kh", 600},
        {"za", 700},
        {"zb", 800},
        {"zc", 900},
        {"gh", 1000},
};

int return_abjad_value(string t_source_string){
    std::map<string,int>::iterator abjad_value;
    abjad_value = abjad_list.find(t_source_string);
    return abjad_value->second;
}

string generate_real_character_in_arabic(char first_char, char second_char){
    string arabic_character = "";
    arabic_character += first_char;
    arabic_character += second_char;
    return arabic_character;
}

int convert_to_abjad(string t_source_string){
    int value = 0;
    for(string::size_type i = 0; i < t_source_string.size()-1; ++i) {
        value += return_abjad_value(generate_real_character_in_arabic(t_source_string[i], t_source_string[i+1]));
        ++i;
    }
    return value;
}

int main(){
    string source_string;
    cin>>source_string;
    cout<<convert_to_abjad(source_string);
    return 0;
}