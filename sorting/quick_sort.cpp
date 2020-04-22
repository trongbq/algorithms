#include <iostream>

using namespace std;

int swap(int arr[], int x, int y) {
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

int partition(int arr[], int l, int h) {
    int x = arr[h]; // Pivot value
    int i = l - 1; // Largest index of a smaller numbers
    
    for (int j = l; j < h; j++) {
        if (arr[j] <= x) {
            i += 1;
            swap(arr, i, j);
        }
    }
    
    swap(arr, i + 1, h);
    return i + 1;    
}

int quickSort(int arr[], int l, int h) {
    if (l < h) {
        int p = partition(arr, l, h);
        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, h);
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
    int arr[] = {3, 1, 76, 34, 2, 18, 54, 33, 121, 7, 9, 21};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Input: ";
    print(arr, n);
    
    quickSort(arr, 0, n - 1);
    
    cout << "Output: ";
    print(arr, n);

    return 0;
}
