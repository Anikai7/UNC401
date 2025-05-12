#include <iostream>
#include <vector>
#include <string>
#include <chrono>

using namespace std;
using namespace chrono;

// Linear search function
int linearSearch(const vector<string>& phoneBook, const string& target) {
    for (size_t i = 0; i < phoneBook.size(); i++) {
        if (phoneBook[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    vector<string> phoneBook = {"person_A", "person_B", "person_C", "person_D", "person_E", 
        "person_F", "person_G", "person_H", "person_I", "person_J"};
    string target;
    
    cout << "Enter contact name to search: ";
    cin >> target;
    
    auto start = high_resolution_clock::now();
    int index = linearSearch(phoneBook, target);
    auto stop = high_resolution_clock::now();
    
    auto duration = duration_cast<nanoseconds>(stop - start);
    
    if (index != -1) {
        cout << "Contact found at index " << index << "\n";
    } else {
        cout << "Contact not found\n";
    }
    
    cout << "Time taken: " << duration.count() << " nanoseconds\n";
    
    return 0;
}