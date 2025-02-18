#include <iostream>

struct Node {
    int player_id;
    Node *next;
};

class game {
public:
    Node *head;
    int player_cnt;

    game() {
        head = nullptr;
        player_cnt = 0;
    }

    void insert(int playerId) {
        Node *node = new Node{playerId, nullptr};
        if (head == nullptr) {
            head = node;
            node->next = head;
        } else {
            Node *tem = head;
            while (tem->next != head) {
                tem = tem->next;
            }
            tem->next = node;
            node->next = head;
        }
        player_cnt++;
    }

    void display() {
        if (head == nullptr) return;
        Node *tem = head;
        int cnt = 0;
        do {
            std::cout << "Player id: " << tem->player_id << std::endl;
            tem = tem->next;
            cnt++;
        } while (tem != head && cnt < player_cnt);
    }

    void cnt() {
        std::cout << "Total number of players: " << player_cnt << std::endl;
    }

    void searchPlayer(int playerId) {
        Node *tem = head;
        int cnt = 0;
        do {
            if (tem->player_id == playerId) {
                std::cout << "Player Found at: " << cnt << "th Node" << std::endl;
                return;
            }
            tem = tem->next;
            cnt++;
        } while (tem != head && cnt < player_cnt);
        std::cout << "Player not found" << std::endl;
    }

    void deletePlayer(int playerId) {
        if (head == nullptr) return;
        Node *tem = head, *prev = nullptr;
        do {
            if (tem->player_id == playerId) {
                if (prev == nullptr) {
                    Node *last = head;
                    while (last->next != head) {
                        last = last->next;
                    }
                    head = head->next;
                    last->next = head;
                } else {
                    prev->next = tem->next;
                }
                delete tem;
                player_cnt--;
                return;
            }
            prev = tem;
            tem = tem->next;
        } while (tem != head);
        std::cout << "Player not found" << std::endl;
    }
};

int main() {
    game g;
    g.insert(1);
    g.insert(2);
    g.insert(3);
    g.display();
    g.searchPlayer(2);
    g.deletePlayer(2);
    g.display();
    g.cnt();
    return 0;
}
