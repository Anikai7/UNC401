#include <iostream>
#include <queue>
#include <functional>

struct Patient {
    std::string name;
    int emergency; // Higher = more urgent
    bool operator<(const Patient& other) const {
        return emergency < other.emergency;
    }
};

void triagePatients() {
    std::priority_queue<Patient> pq;
    pq.push({"Alice", 2});
    pq.push({"Bob", 5});
    pq.push({"Carol", 3});
    pq.push({"Dave", 1});

    std::cout << "[Patient Triage]\n";
    while (!pq.empty()) {
        auto p = pq.top(); pq.pop();
        std::cout << "Treated: " << p.name << " (Emergency " << p.emergency << ")\n";
    }
    std::cout << "➡ Heap Sort via priority_queue ensures efficient O(log n) triage.\n\n";
}
