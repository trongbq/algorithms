#include <iostream>

using namespace std;

int swap(int arr[], int x, int y) {
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

int selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int k = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[k] > arr[j]) {
                k = j;
            }
        }
        // k holds the position of the smallest elements from i -> n-1
        swap(arr, i, k);
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
    
    selectionSort(arr, n);
    
    cout << "Output: ";
    print(arr, n);

    return 0;
}
