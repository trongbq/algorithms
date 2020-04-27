#include <iostream>

using namespace std;

void merge(int arr[], int l, int mid, int h) {
    int n1 = mid - l + 1;
    int n2 = h - mid;
    int arr1[n1];
    int arr2[n2];
    
    // Copy value from array to sub-arrays
    for (int i = 0; i < n1; i++) {
        arr1[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++) {
        arr2[i] = arr[mid + 1 + i];
    }

    // Merge two sorted subarrays into array
    int i = 0;
    int j = 0;
    for (int k = l; k <= h; k++) {
        if (i != n1 && (j == n2 || arr1[i] < arr2[j])) {
            arr[k] = arr1[i];
            i++;
        } else {
            arr[k] = arr2[j];
            j++;
        }
    }
}

void mergeSort(int arr[], int l, int h) {
    if (l < h) {
        int mid = (l + h) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, h);
        merge(arr, l, mid, h);
    }
}

void print(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {3, 1, 76, 34, 2, 18, 54, 33, 121, 7, 9, 21, 999, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Input: ";
    print(arr, n);
    
    mergeSort(arr, 0, n - 1);
    
    cout << "Output: ";
    print(arr, n);

    return 0;
}
