#include <iostream> 
#include <vector> 

using namespace std;
void knapsack(const vector<int> &weights, const vector<int> &values, int capacity)
{
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    for (int i = 1; i <= n; ++i)
    {
        for (int w = 0; w <= capacity; ++w)
        {
            if (weights[i - 1] <= w)
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);

            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    cout << "Max Value: " << dp[n][capacity] << endl;
    int w = capacity;
    cout << "Selected Items: ";
    for (int i = n; i > 0 && w > 0; --i)
    {
        if (dp[i][w] != dp[i - 1][w])
        {
            cout << "Item " << i << " ";
            w -= weights[i - 1]; // Reduce the remaining capacity
        }
    }
    cout << endl;
}

int main()
{
    vector<int> weights = {10, 20, 30};
    vector<int> values = {60, 100, 120};
    int capacity = 50;

    knapsack(weights, values, capacity);
    return 0;
}
