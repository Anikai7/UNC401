#include <iostream>

using namespace std;


void longAddition(int num1[], int num2[], int result[], int len1, int len2) {
    int max_len = max(len1, len2);

    // Arrays to store digits of the numbers, initialize to 0
    int num1_array[len1] = {0};
    int num2_array[len2] = {0};

    // Copy the numbers into the arrays, in reverse order
    for (int i = 0; i < len1; ++i) {
        num1_array[max_len - len1 + i] = num1[i];
    }
    for (int i = 0; i < len2; ++i) {
        num2_array[max_len - len2 + i] = num2[i];
    }

    int carry = 0;
    // Perform addition from the last digit to the first
    for (int i = max_len - 1; i >= 0; --i) {
        int total = num1_array[i] + num2_array[i] + carry;
        carry = total / 10;
        result[i + 1] = total % 10;
    }

    // If there's a carry left after the last addition
    result[0] = carry;
}

int main() {
    int num1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int num2[] = {1,2,3,4,5,6,7,8,9};
    
    int len1 = sizeof(num1)/sizeof(num1[0]);
    int len2 = sizeof(num2)/sizeof(num2[0]);

    int result[len1+len2+1] = {0}; // +1 for possible carry
    
    longAddition(num1, num2, result, len1, len2);

    // Print the result, skipping leading zeros
    bool leading_zero = true;
    for (int i = 0; i <= max(len1, len2); ++i) {
        if (result[i] != 0) {
            leading_zero = false;
        }
        if (!leading_zero) {
            cout << result[i];
        }
    }
    cout << endl;

    return 0;
}
