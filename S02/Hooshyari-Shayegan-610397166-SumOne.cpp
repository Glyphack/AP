#include <iostream>
#include <math.h>
using namespace std;


int get_length(long long int number){
    unsigned int number_of_digits = 0;
    do {
        ++number_of_digits;
        number /= 10;
    } while (number);
    return number_of_digits;
}


long long int_power(long long int x, long long int p) {
    if (p == 0) return 1;
    if (p == 1) return x;
    return x * int_power(x, p-1);
}

long long int get_digit(long long int number, long long int digit){
    return number / int_power(10, digit - 1) % 10;
}

long long int calculate_value(long long int t_number, int digit){
    if (t_number ==0)
        return 0;
    cout<<"value of "<<t_number<<" "<<digit<<"is"<<get_digit(t_number, digit) * int_power(10, digit-1)<<endl;
    return get_digit(t_number, digit) * int_power(10, digit-1);
}


long long int add_with_sum_one_method(long long int t_number1, long long int t_number2, int step) {
    if (step > get_length(t_number1))
        t_number1 = 0;
    if (step > get_length(t_number2))
        t_number1 = 0;
    if (step > get_length(t_number1) && step > get_length(t_number2))
        return 0;
    return calculate_value(t_number1, step) + calculate_value(t_number2, step) + add_with_sum_one_method(t_number1, t_number2, step+1);
}

int main(){
    long long int first_number, second_number;
    cin>>first_number>>second_number;
    cout<<add_with_sum_one_method(first_number, second_number, 1);
    return 0;
}