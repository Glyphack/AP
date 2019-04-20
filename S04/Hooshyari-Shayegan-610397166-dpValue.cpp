#include <iostream>

using std::cin;
using std::cout;


void InputArray(int *array, int length){
    for(int index=0;index<length;index++)
        cin>>array[index];
}

void FillInfinity(int *array, int length){
    for (int i=0; i<length;i++){
        array[i] = 1000;
    }
}

int CalculateCoins(int value, const int* coins){
    int* number_of_coins = new int[value+1];
    FillInfinity(number_of_coins, value+1);
    number_of_coins[0] = 0;
    for (int i=1; i<=value; i++){
        for (int j=0; j<i-1;j++){
            if(coins[j]<=i && number_of_coins[i-coins[j]]+1<number_of_coins[i]){
                number_of_coins[i] = number_of_coins[i-coins[j]]+1;
            }
        }
    }
    int minimum_coins = number_of_coins[value];
    delete [] number_of_coins;
    return minimum_coins;
}


int main(){
    int number_of_coins, *coins, value;
    cin>>value>>number_of_coins;
    coins = new int[number_of_coins];
    InputArray(coins, number_of_coins);
    cout<<CalculateCoins(value, coins);
    delete [] coins;
    return 0;
}