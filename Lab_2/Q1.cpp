#include <iostream>
#include <climits>

using namespace std;

void display(int arr[], int size) {
    cout << "Displying elements: ";
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int append(int*& arr, int size) {
    cout<< "#Appending elements"<<endl;
    int n;
    cout << "Enter number of elements to be appended: ";
    cin >> n;
    
    int* arr_new = new int[n + size]; // Allocate new array

    for(int i = 0; i < size; i++) {
        arr_new[i] = arr[i];
    }

    for(int j = size; j < n + size; j++) {
        cout << "Enter the element: ";
        cin >> arr_new[j];
    }

    delete[] arr;  // Free old array
    arr = arr_new; // Update pointer to new array

    return n + size;
}

int insert(int*& arr, int size, int index, int x) {
    cout<<"#Inserting elements"<<endl;
    if(index < 0 || index > size) {
        cerr << "Not a valid index" << endl;
        return size;
    }

    int* arr_new = new int[size + 1];

    for(int i = 0; i < index; i++) {
        arr_new[i] = arr[i];
    }

    arr_new[index] = x;

    for(int i = index; i < size; i++) {
        arr_new[i + 1] = arr[i];
    }

    delete[] arr;
    arr = arr_new;

    return size + 1;
}

int deleteElement(int*& arr, int size, int x) {
    cout<<"#Deleting elements"<<endl;
    int count = 0;
    for(int i = 0; i < size; i++) {
        if(arr[i] == x) {
            count++;
        }
    }
    
    if (count == 0) {
        cout << "Element not found!" << endl;
        return size;
    }

    int* arr_new = new int[size - count];
    int j = 0;

    for(int i = 0; i < size; i++) {
        if(arr[i] != x) {
            arr_new[j++] = arr[i];
        }
    }

    delete[] arr;
    arr = arr_new;

    return size - count;
}

void get(int arr[], int size, int index) {
    cout<<"#Get element at index: "<<index<<endl;
    if (index < 0 || index >= size) {
        cout << "Invalid index!" << endl;
        return;
    }
    cout << arr[index] << endl;
}

void set(int arr[], int size, int index, int x) {
    cout << "#Set element at index: "<<index<<endl;
    if (index < 0 || index >= size) {
        cout << "Invalid index!" << endl;
        return;
    }
    arr[index] = x;
}

void maxElement(int arr[], int size) {
    cout<<"#finding max element in array"<<endl;
    int max_elem = INT_MIN;
    for(int i = 0; i < size; i++) {
        max_elem = std::max(arr[i], max_elem);
    }
    cout << "Maximum element: " << max_elem << endl;
}

void minElement(int arr[], int size) {
    cout<<"#finding min element in array"<<endl;
    int min_elem = INT_MAX;
    for(int i = 0; i < size; i++) {
        min_elem = std::min(arr[i], min_elem);
    }
    cout << "Minimum element: " << min_elem << endl;
}

void reverse(int arr[], int size) {
    cout<<"#Reversing element in array"<<endl;
    for(int i = 0; i < size / 2; i++) {
        swap(arr[i], arr[size - 1 - i]);
    }
}

void shift(int arr[], int size) {
    cout<<"#Shifting element in array"<<endl;
    if (size <= 1) return;
    
    int first = arr[0];
    for (int i = 0; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    arr[size - 1] = first;
}

void rotate(int arr[], int size, int k) {
    cout<<"Rotating element in array"<<endl;
    k %= size;
    if (k == 0) return;

    int* temp = new int[k];
    
    for (int i = 0; i < k; i++) {
        temp[i] = arr[i];
    }

    for (int i = 0; i < size - k; i++) {
        arr[i] = arr[i + k];
    }

    for (int i = 0; i < k; i++) {
        arr[size - k + i] = temp[i];
    }

    delete[] temp;
}

int main() {
    int* arr = new int[5]{1, 2, 3, 4, 5};
    int size = 5;

    display(arr, size);

    size = append(arr, size);
    display(arr, size);

    reverse(arr, size);
    display(arr, size);

    size = deleteElement(arr, size, 5);
    display(arr, size);
    
    shift(arr,size);
    display(arr,size);

    rotate(arr,size,2);
    display(arr,size);

    delete[] arr; // Free dynamically allocated memory

    return 0;
}
