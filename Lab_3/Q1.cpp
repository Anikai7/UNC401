#include <iostream>

struct Node {
    int table_id;
    int num_items;
    std::string food_item[10];
    float item_value[10];
    Node *next;
};

class Restaurant {
public:
    Node *head = nullptr;

    void display() {
        Node *tem = head;
        while (tem != nullptr) {
            std::cout << "Order Id: " << tem->table_id << std::endl;
            std::cout << "Number of items: " << tem->num_items << std::endl;
            for (int i = 0; i < tem->num_items; i++) {
                std::cout << i << "th food item: " << tem->food_item[i] << std::endl;
                std::cout << i << "th cost: " << tem->item_value[i] << std::endl;
            }
            tem = tem->next;
        }
    }

    int orderValueNumb() {
        int cnt = 0, val = 0;
        Node *tem = head;
        while (tem != nullptr) {
            cnt++;
            for (int i = 0; i < tem->num_items; i++) {
                val += tem->item_value[i];
            }
            tem = tem->next;
        }
        std::cout << "Total Order Value " << val << std::endl;
        return cnt;
    }

    void searchOrder(int orderId) {
        Node *tem = head;
        while (tem != nullptr) {
            if (tem->table_id == orderId) {
                std::cout << tem->table_id << std::endl;
                std::cout << tem->num_items << std::endl;
                for (int i = 0; i < tem->num_items; i++) {
                    std::cout << tem->food_item[i] << std::endl;
                    std::cout << tem->item_value[i] << std::endl;
                }
                return;
            }
            tem = tem->next;
        }
        std::cout << "Order not found" << std::endl;
    }

    void deleteOrder(int orderId) {
        Node *currPtr = head;
        Node *prevPtr = nullptr;
        while (currPtr != nullptr) {
            if (currPtr->table_id == orderId) {
                if (prevPtr == nullptr) {
                    head = currPtr->next;
                } else {
                    prevPtr->next = currPtr->next;
                }
                delete currPtr;
                return;
            }
            prevPtr = currPtr;
            currPtr = currPtr->next;
        }
    }

    void insert(Node *newNode) {
        Node *tem = head;
        if (tem == nullptr) {
            head = newNode;
            return;
        }
        while (tem->next != nullptr) {
            tem = tem->next;
        }
        tem->next = newNode;
        return;
    }
};

int main() {
    Restaurant order;

    while (true) {
        std::cout << "Welcome how may I help you?" << std::endl
                  << "1. New Order" << std::endl
                  << "2. Display Orders" << std::endl
                  << "3. Total Order and Value" << std::endl
                  << "4. Search for Order" << std::endl
                  << "5. Delete Order" << std::endl
                  << "6. Exit" << std::endl;

        int menu_no;
        std::cin >> menu_no;

        if (menu_no == 1) {
            int order_id = order.orderValueNumb();
            order_id++;

            int num_order;
            std::cout << "Enter number of order(<10): " << std::endl;
            std::cin >> num_order;

            if (num_order > 10) {
                std::cout << "Error !!" << std::endl;
                continue;
            }

            std::string items[10];
            float cost[10];
            
            for (int i = 0; i < num_order; i++) {
                std::cout << "Enter " << i << "th Order: ";
                std::cin >> items[i];
                std::cout << "Enter cost of dish: ";
                std::cin >> cost[i];
            }
            Node *node = new Node{order_id,num_order,{},{},nullptr};
            for (int i = 0; i < num_order; i++) {
                node->food_item[i] = items[i];
                node->item_value[i] = cost[i];
            }
            order.insert(node);
        } else if (menu_no == 2) {
            order.display();
        } else if (menu_no == 3) {
            std::cout << "Total Orders: " << order.orderValueNumb() << std::endl;
        } else if (menu_no == 4) {
            int order_id;
            std::cout << "Enter Order ID to search: ";
            std::cin >> order_id;
            order.searchOrder(order_id);
        } else if (menu_no == 5) {
            int order_id;
            std::cout << "Enter Order ID to delete: ";
            std::cin >> order_id;
            order.deleteOrder(order_id);
        } else if (menu_no == 6) {
            break;
        } else {
            std::cout << "Invalid option, try again." << std::endl;
        }
    }
    return 0;
}