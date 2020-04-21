// O(log n)
int binarySearch(int arr[], int l, int h, int x) {
    if (h >= l) {
        int m = (l + h) / 2;
        
        // Return m index if value at this index equals to x
        if (arr[m] == x) {
            return m;   
        }
        
        // If value at m index is larger than x, x can conly be found in left subarray
        if (arr[m] > x) {
            return binarySearch(arr, l, m - 1, x);
        }
        
        // x will be in right subarray
        return binarySearch(arr, m + 1, h, x);
    }
    
    // Return -1 to indicate not found
    return -1;
}

int main()
{
    int arr[] = {1, 4, 7, 14, 18, 25, 94, 154};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 18;
    
    int found = binarySearch(arr, 0, n - 1, x);
    cout << "Found value " << x << " at index " << found;

    return 0;
}
