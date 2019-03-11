#include <iostream>
#include <string.h>

using std::cout;
using std::cin;
using std::to_string;
using std::string;

bool IsEqual(const string &t_first_string, const string &t_second_string);
string ReverseString(string t_string);
bool AreReverse(int t_first_number, int t_second_number);

int main() {
  int first_number(0), second_number(0);
  cin>>first_number>>second_number;
  cout<< AreReverse(first_number, second_number);
  return 0;
}

bool IsEqual(const string &t_first_string, const string &t_second_string){
  int is_equal = strcmp(t_first_string.c_str(), t_second_string.c_str());
  return is_equal == 0;
}

string ReverseString(string t_string){
  unsigned long number_length = t_string.length();
  char char_array[number_length+1];
  strcpy(char_array, t_string.c_str());
  for (unsigned int character=0; character < number_length/2;character++){
    char_array[character] ^= char_array[number_length-character-1];
    char_array[number_length-character-1] ^= char_array[character];
    char_array[character] ^= char_array[number_length-character-1];
  }
  t_string = char_array;
  return t_string;
}

bool AreReverse(int t_first_number, int t_second_number){
  string first_number_string = to_string(t_first_number);
  string second_number_string = to_string(t_second_number);
  return IsEqual(ReverseString(first_number_string), second_number_string);
}
