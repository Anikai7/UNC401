#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item
{
    int profit, weight;
    Item(int p, int w) : profit(p), weight(w) {}
    double ratio() const
    {
        return (double)profit / weight;
    }
};

bool compare(Item a, Item b)
{
    return a.ratio() > b.ratio();
}

double fractionalKnapsack(int capacity, vector<Item> items)
{
    sort(items.begin(), items.end(), compare);
    double totalProfit = 0.0;
    for (Item &item : items)
    {
        if (capacity >= item.weight)
        {
            capacity -= item.weight;
            totalProfit += item.profit;
        }
        else
        {
            totalProfit += item.ratio() * capacity;
            break;
        }
    }

    return totalProfit;
}

int main()
{
    vector<Item> items = {Item(60, 10),
                          Item(100, 20),
                          Item(120, 30)};

    int capacity = 50;
    double maxProfit = fractionalKnapsack(capacity, items);

    cout << "Maximum profit: " << maxProfit << endl;

    return 0;
}
