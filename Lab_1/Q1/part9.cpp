#include <iostream>
using namespace std;

void removeDuplicates(int arr[], int &n) {
    int index = 0;
    for (int i = 0; i < n; i++) {
        bool isDuplicate = false;
        for (int j = 0; j < index; j++) {
            if (arr[i] == arr[j]) {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate) {
            arr[index++] = arr[i];
        }
    }
    for (int i = index; i < n; i++) {
        arr[i] = 0;
    }
    n = index;
}

int main() {
    int arr[] = {4, 5, 9, 4, 7, 5, 9, 10, 10, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    removeDuplicates(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
