#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

// Function to return precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// Function to convert infix expression to postfix
string infixToPostfix(const string& infix) {
    stack<char> s;
    string postfix;
    
    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;
        } else if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        } else {
            while (!s.empty() && precedence(s.top()) >= precedence(c)) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }
    
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }
    
    return postfix;
}

#include <chrono>
using namespace chrono;

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;
    auto start = high_resolution_clock::now();
    string postfix = infixToPostfix(infix);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    
    cout << "Postfix expression: " << postfix << endl;
    cout << "Time taken: " << duration.count() << " nanoseconds" << endl;
    return 0;
}
