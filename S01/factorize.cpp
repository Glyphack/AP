#include <iostream>

using std::cout;
using std::cin;

void SieveOfEratosthenes(unsigned int count, bool is_prime[]){
  is_prime[0] = is_prime[1] = false;
  for (int i=0; i <count;i++){
    is_prime[i] = true;
  }

  for (int p=2;p*p <=count;p++){
    if (is_prime[p]){
      for (int i=p*2;i<=count;i+=p){
        is_prime[i] = false;
      }
    }

  }
}

bool CanBeWrittenAsSumOfTwoPrimes(unsigned int number){
  bool is_prime[number+1];
  SieveOfEratosthenes(number, is_prime);
  for (unsigned int i=0;i<number;i++){
    if (is_prime[i] && is_prime[number-i]){
      return true;
    }
  }
  return false;
}

void NumbersThatCanBeWrittenAsSumOfTwoPrimes(unsigned int begin, unsigned int end){
  for (unsigned int i=begin; i<end; i++){
    if (CanBeWrittenAsSumOfTwoPrimes(i)){
      cout<<i;
    }
  }
}

int main(){
  unsigned int begin,end;
  cin>>begin>>end;
  NumbersThatCanBeWrittenAsSumOfTwoPrimes(begin, end);
}
