#include <iostream>

using namespace std;

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j  = i - 1;
        // Try to insert arr[i] into sorted array from 0 -> i-1
        while (j >=0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void print(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {3, 1, 76, 34, 2, 18, 54, 33, 121, 7, 9, 21};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Input: ";
    print(arr, n);
    
    insertionSort(arr, n);
    
    cout << "Output: ";
    print(arr, n);

    return 0;
}