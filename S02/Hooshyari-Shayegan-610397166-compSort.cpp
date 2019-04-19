#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void SelectionSort(int arr[], int n)
{
    int i, j, min_idx;

    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        swap(&arr[min_idx], &arr[i]);
    }
}

void BubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)

        // Last i elements are already in place
        for (j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
}

int main()
{
    int arr[1000];
    for (int &j : arr) {
        int random_number = rand() % 101;
        j =random_number;
    }
    int n = sizeof(arr)/sizeof(arr[0]);
    auto start = high_resolution_clock::now();
    SelectionSort(arr, n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout <<"Selection Sort:"<<duration.count() << endl;
    int arr2[1000];
    for (int &j : arr2) {
        int random_number = rand() % 101;
        j =random_number;
    }
    start = high_resolution_clock::now();
    BubbleSort(arr2, n);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout <<"Bubble Sort:"<<duration.count() << endl;
    return 0;
}