#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to insert nodes in level order
Node* insertLevelOrder(const vector<int>& arr) {
    if (arr.empty()) return nullptr;

    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;
    while (i < arr.size()) {
        Node* current = q.front();
        q.pop();

        if (i < arr.size()) {
            current->left = new Node(arr[i++]);
            q.push(current->left);
        }

        if (i < arr.size()) {
            current->right = new Node(arr[i++]);
            q.push(current->right);
        }
    }
    return root;
}

// Function to check if a binary tree is balanced
int checkHeight(Node* root) {
    if (!root) return 0;
    int lh = checkHeight(root->left);
    int rh = checkHeight(root->right);
    if (lh == -1 || rh == -1 || abs(lh - rh) > 1) return -1;
    return max(lh, rh) + 1;
}
bool isBalanced(Node* root) {
    return checkHeight(root) != -1;
}

// Function to check if a binary tree is complete
bool isComplete(Node* root) {
    if (!root) return true;
    queue<Node*> q;
    q.push(root);
    bool end = false;

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        if (current->left) {
            if (end) return false;
            q.push(current->left);
        } else {
            end = true;
        }

        if (current->right) {
            if (end) return false;
            q.push(current->right);
        } else {
            end = true;
        }
    }
    return true;
}

bool isFull(Node* root) {
    if (!root) return true;
    if (!root->left && !root->right) return true;
    if (root->left && root->right)
        return isFull(root->left) && isFull(root->right);
    return false;
}

int depth(Node* node) {
    int d = 0;
    while (node) {
        d++;
        node = node->left;
    }
    return d;
}

bool isPerfect(Node* root, int d, int level = 0) {
    if (!root) return true;
    if (!root->left && !root->right)
        return d == level + 1;
    if (!root->left || !root->right)
        return false;
    return isPerfect(root->left, d, level + 1) &&
           isPerfect(root->right, d, level + 1);
}

int main() {
    vector<int> arr;
    int n, val;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter values (level-order): ";
    for (int i = 0; i < n; ++i) {
        cin >> val;
        arr.push_back(val);
    }

    Node* root = insertLevelOrder(arr);

    cout << "\nTree Type Checks:\n";
    cout << "Balanced: " << (isBalanced(root) ? "Yes" : "No") << endl;
    cout << "Complete: " << (isComplete(root) ? "Yes" : "No") << endl;
    cout << "Full:     " << (isFull(root) ? "Yes" : "No") << endl;
    cout << "Perfect:  " << (isPerfect(root, depth(root)) ? "Yes" : "No") << endl;

    return 0;
}
