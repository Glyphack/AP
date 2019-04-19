#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string t_string;
    getline(cin, t_string);

    for (int i = (int)t_string.length(); i > 0; i--) {
        if (isdigit(t_string[i])) {
            cout<<t_string[i];
        }
    }
    return 0;
}