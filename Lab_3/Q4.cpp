#include <iostream>

struct Plate {
    int id;
    Plate *next;
};

class PlateStack {
public:
    Plate *top;

    PlateStack() : top(nullptr) {}

    void push(int plateId) {
        Plate *plate = new Plate{plateId, top};
        top = plate;
    }

    void pop() {
        if (top == nullptr) {
            std::cout << "Stack is empty, no plates to remove." << std::endl;
            return;
        }
        Plate *temp = top;
        top = top->next;
        delete temp;
    }

    void display() {
        Plate *temp = top;
        while (temp != nullptr) {
            std::cout << "Plate ID: " << temp->id << std::endl;
            temp = temp->next;
        }
    }
};

int main() {
    PlateStack stack;

    for (int i = 1; i <= 5; ++i) {
        stack.push(i);
    }

    std::cout << "Stack of plates:" << std::endl;
    stack.display();

    std::cout << "\nRemoving 3 plates..." << std::endl;
    for (int i = 0; i < 3; ++i) {
        stack.pop();
    }

    std::cout << "Stack of plates after removing 3 plates:" << std::endl;
    stack.display();

    return 0;
}
