#include <iostream> 
#include <vector> 
using namespace std;

bool isSubsetSum(const vector<int> &set, int n, int targetSum)
{
    for (int i = 0; i < (1 << n); ++i)
    {
        int sum = 0;
        for (int j = 0; j < n; ++j)
        {
            if (i & (1 << j))
            {
                sum += set[j];
            }
        }
        if (sum == targetSum)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    vector<int> set = {3, 34, 4, 12, 5, 2};
    int targetSum = 9;

    int n = set.size();
    if (isSubsetSum(set, n, targetSum))
    {
        cout << "Yes (there is a subset that sums to " << targetSum << ")\n";
    }
    else
    {
        cout << "No (no subset sums to " << targetSum << ")\n";
    }
    return 0;
}
