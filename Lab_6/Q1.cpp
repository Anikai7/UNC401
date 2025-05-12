#include <iostream>
#include <algorithm> // For std::sort
using namespace std;

// Linear Search Function
int linearSearch(int arr[], int n, int target, int &comparisons) {
    comparisons = 0;
    for (int i = 0; i < n; i++) {
        comparisons++;
        if (arr[i] == target) {
            return i; // Element found
        }
    }
    return -1; // Element not found
}

// Binary Search Function
int binarySearch(int arr[], int n, int target, int &comparisons) {
    int left = 0, right = n - 1;
    comparisons = 0;
    while (left <= right) {
        comparisons++;
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid; // Element found
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // Element not found
}

int main() {
    int arr[] = {64, 25, 12, 22, 11, 90, 55, 43, 88, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 88;

    // Linear Search
    int linearComparisons;
    int linearResult = linearSearch(arr, n, target, linearComparisons);
    cout << "Linear Search: ";
    if (linearResult != -1)
        cout << "Element found at index " << linearResult << " with " << linearComparisons << " comparisons.\n";
    else
        cout << "Element not found with " << linearComparisons << " comparisons.\n";

    // Binary Search (requires sorted array)
    sort(arr, arr + n); // Sort the array for binary search
    int binaryComparisons;
    int binaryResult = binarySearch(arr, n, target, binaryComparisons);
    cout << "Binary Search: ";
    if (binaryResult != -1)
        cout << "Element found at index " << binaryResult << " with " << binaryComparisons << " comparisons.\n";
    else
        cout << "Element not found with " << binaryComparisons << " comparisons.\n";

    return 0;
}
