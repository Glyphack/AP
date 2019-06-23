#include <iostream>

using std::cout;
using std::cin;


class Person{
public:
    int value;
    int weight;
    Person(){
        value = -1;
        weight = -1;
    }
    Person(int person_value, int person_weight){
        value = person_value;
        weight = person_weight;
    }
};


int max(int a, int b) { return (a > b)? a : b; }

void InitializeMatrix(int **matrix, int rows, int columns){
    for(int row=0;row<rows;row++)
        matrix[row] = new int[columns];
}


void FillZero(int **array, int length){
    for (int i=0; i<length;i++){
        for(int j=0; j<length; j++)
            array[i][j] = 0;
    }
}


int GetMaximumValueCanBeCarried(Person *persons, int persons_count, int elevator_capacity){
    int i, w;
    int K[persons_count+1][elevator_capacity+1];

    for (i = 0; i <= persons_count; i++)
    {
        for (w = 0; w <= elevator_capacity; w++)
        {
            if (i==0 || w==0)
                K[i][w] = 0;
            else if (persons[i-1].weight <= elevator_capacity)
                K[i][w] = max(persons[i-1].value + K[i-1][w-persons[i-1].weight],  K[i-1][w]);
            else
                K[i][w] = K[i-1][w];
        }
    }
    return K[persons_count][elevator_capacity];
}



int main(){
    int persons_count, person_value, person_weight, elevator_capacity;
    cin>>persons_count>>elevator_capacity;
    auto *persons = new Person;
    for(int i=0; i<persons_count; i++){
        cin>>person_value>>person_weight;
        persons[i].value = person_value;
        persons[i].weight = person_weight;
    }
    cout<<GetMaximumValueCanBeCarried(persons, persons_count, elevator_capacity);
}