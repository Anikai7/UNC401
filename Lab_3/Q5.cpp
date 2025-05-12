#include <iostream>

struct Node {
    int vehicle_id;
    Node *next;
};

class TrafficSignalQueue {
public:
    Node *front;
    Node *rear;

    TrafficSignalQueue() {
        front = rear = nullptr;
    }

    void insertVehicle(int vehicleId) {
        Node *node = new Node{vehicleId, nullptr};
        if (rear == nullptr) {
            front = rear = node;
        } else {
            rear->next = node;
            rear = node;
        }
    }

    void displayVehicles() {
        Node *temp = front;
        while (temp != nullptr) {
            std::cout << "Vehicle ID: " << temp->vehicle_id << std::endl;
            temp = temp->next;
        }
    }

    void serveVehicles(int count) {
        for (int i = 0; i < count; ++i) {
            if (front != nullptr) {
                Node *temp = front;
                front = front->next;
                delete temp;
                if (front == nullptr) {
                    rear = nullptr;
                }
            } else {
                std::cout << "No more vehicles to serve." << std::endl;
                break;
            }
        }
    }
};

int main() {
    TrafficSignalQueue queue;
    for (int i = 1; i <= 5; ++i) {
        queue.insertVehicle(i);
    }
    std::cout << "Vehicles in queue:" << std::endl;
    queue.displayVehicles();
    std::cout << "\nServing 3 vehicles..." << std::endl;
    queue.serveVehicles(3);
    std::cout << "Vehicles in queue after serving 3 vehicles:" << std::endl;
    queue.displayVehicles();
    return 0;
}
