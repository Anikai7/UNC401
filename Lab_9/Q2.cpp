#include <iostream> 
#include <vector> 
#include <cmath> 
using namespace std;
double euclidean_distance(pair<int, int> &p1, pair<int, int> &p2)
{
    return sqrt((p2.first - p1.first) * (p2.first - p1.first) + (p2.second - p1.second) * (p2.second - p1.second));
}

int main()
{
    vector<pair<int, int>> points = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    double min_distance = 1e9;
    pair<int, int> closest_pair1, closest_pair2;
    for (size_t i = 0; i < points.size() - 1; i++)
    {
        for (size_t j = i + 1; j < points.size(); j++)
        {
            double dist = euclidean_distance(points[i], points[j]);
            if (dist < min_distance)
            {
                min_distance = dist;
                closest_pair1 = points[i];
                closest_pair2 = points[j];
            }
        }
    }

    cout << "Closest pair: (" << closest_pair1.first << ", " << closest_pair1.second << ") and ("
         << closest_pair2.first << ", " << closest_pair2.second << ") with distance ≈ "
         << min_distance << endl;

    return 0;
}
