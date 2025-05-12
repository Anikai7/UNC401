#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void preorder(Node* root) {
    if (root) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

Node* minValueNode(Node* root) {
    Node* current = root;
    while (current && current->left)
        current = current->left;
    return current;
}

Node* deleteNode(Node* root, int key) {
    if (!root) return nullptr;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    Node* root = nullptr;
    int n, val;

    cout << "Enter number of nodes in BST: ";
    cin >> n;

    cout << "Enter values (space-separated): ";
    for (int i = 0; i < n; ++i) {
        cin >> val;
        root = insert(root, val);
    }

    cout << "\nBST Traversals:\n";
    cout << "Inorder:   "; inorder(root); cout << endl;
    cout << "Preorder:  "; preorder(root); cout << endl;
    cout << "Postorder: "; postorder(root); cout << endl;

    int key;
    cout << "\nEnter key to delete: ";
    cin >> key;
    root = deleteNode(root, key);

    cout << "\nInorder Traversal After Deletion:\n";
    cout << "Inorder:   "; inorder(root); cout << endl;

    return 0;
}
