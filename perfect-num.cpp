#include <iostream>
#include<bits/stdc++.h>
#include <vector>

using namespace std;

int SumDivisorsOfDivisors(int t_number)
{
  int sum_of_divisors = 0;
  vector <int>divisors;
  for (int i=1; i<=sqrt(t_number); i++)
  {
    if (t_number%i == 0)
    {
      if (t_number/i == i)
        divisors.push_back(i);

      else{
        divisors.push_back(i);
        if (i != 1) {
          divisors.push_back(t_number / i);
        }
      }
    }
  }
  for (int &divisor : divisors) {
    sum_of_divisors += divisor;
  }
  return sum_of_divisors;
}

bool IsPerfect(int t_number_to_be_checked){
  return t_number_to_be_checked == SumDivisorsOfDivisors(t_number_to_be_checked);
}

int main() {
  int number_to_be_checked(0);
  cin>>number_to_be_checked;
  cout<<IsPerfect(number_to_be_checked);
  return 0;
}
