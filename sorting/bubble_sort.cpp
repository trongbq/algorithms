#include <iostream>

using namespace std;

int swap(int arr[], int x, int y) {
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

int bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Upper bound of j will be reduced on every iteration of i
        // Largest element from 0 -> (n - i - 1) will go up to the last position: (n - i - 1)
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr, j, j + 1);
            }
        }
    }
}

void print(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {99, 4, 1, 23, 51, 6, 28, 34, 8, 9, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout << "Input: ";
    print(arr, n);
    
    bubbleSort(arr, n);
    
    cout << "Output: ";
    print(arr, n);

    return 0;
}
