#include <iostream>

struct Node {
    Node *prev;
    std::string student_name;
    int student_id;
    Node *next;
};

class Class {
public:
    Node *head;
    int student_cnt;

    Class() {
        head = nullptr;
        student_cnt = 0;
    }

    void insert(std::string name, int id) {
        Node *node = new Node{nullptr, name, id, nullptr};
        if (head == nullptr) {
            head = node;
        } else {
            Node *tem = head;
            while (tem->next != nullptr) {
                tem = tem->next;
            }
            tem->next = node;
            node->prev = tem;
        }
        student_cnt++;
    }

    void display() {
        Node *tem = head;
        while (tem != nullptr) {
            std::cout << "Student Name: " << tem->student_name << " ID: " << tem->student_id << std::endl;
            tem = tem->next;
        }
    }

    void cnt() {
        std::cout << "Total number of students: " << student_cnt << std::endl;
    }

    void searchStudent(int studentId) {
        Node *tem = head;
        int cnt = 0;
        while (tem != nullptr) {
            if (tem->student_id == studentId) {
                std::cout << "Student found at: " << cnt << "th Node" << std::endl;
                return;
            }
            tem = tem->next;
            cnt++;
        }
        std::cout << "Student not found" << std::endl;
    }

    void deleteStudent(int studentId) {
        Node *tem = head;
        while (tem != nullptr) {
            if (tem->student_id == studentId) {
                if (tem->prev != nullptr) {
                    tem->prev->next = tem->next;
                } else {
                    head = tem->next;
                }
                if (tem->next != nullptr) {
                    tem->next->prev = tem->prev;
                }
                delete tem;
                student_cnt--;
                return;
            }
            tem = tem->next;
        }
        std::cout << "Student not found" << std::endl;
    }
};

int main() {
    Class c;
    c.insert("some", 1);
    c.insert("person", 2);
    c.insert("name", 3);
    c.display();
    c.searchStudent(2);
    c.deleteStudent(2);
    c.display();
    c.cnt();
    return 0;
}
