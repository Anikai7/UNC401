#include <iostream>
#include <vector>
using namespace std;

pair<vector<int>, int> nearestNeighborHeuristic(const vector<vector<int>> &dist)
{
    int n = dist.size();
    vector<bool> visited(n, false); 
    vector<int> cycle;	
    int totalCost = 0;

    int currentCity = 0;
    visited[currentCity] = true;
    cycle.push_back(currentCity);

    for (int i = 1; i < n; ++i)
    {
        int nearestCity = -1;
        int minDistance = 10000;

        for (int j = 0; j < n; ++j)
        {
            if (!visited[j] && dist[currentCity][j] < minDistance)
            {
                minDistance = dist[currentCity][j];
                nearestCity = j;
            }
        }

        visited[nearestCity] = true;
        cycle.push_back(nearestCity);
        totalCost += minDistance;
        currentCity = nearestCity;
    }

    totalCost += dist[currentCity][0];
    cycle.push_back(0); 

    return {cycle, totalCost};
}

int main()
{
    vector<vector<int>> dist = {
        {0, 1, 3, 4},
        {1, 0, 2, 6},
        {3, 2, 0, 5},
        {4, 6, 5, 0}};

    auto result = nearestNeighborHeuristic(dist);
    vector<int> cycle = result.first;
    int totalCost = result.second;

    cout << "Hamiltonian Cycle: ";

    for (int city : cycle)
    {
        cout << char('A' + city) << " ";
    }
    cout << endl;
    cout << "Total Cost: " << totalCost << endl;

    return 0;
}
