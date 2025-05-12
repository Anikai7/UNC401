#include <iostream> 
#include <vector> 

using namespace std;

bool isSafe(int row, int col, vector<int> &positions, int n)
{
    for (int prevCol = 0; prevCol < col; ++prevCol)
    {
        int prevRow = positions[prevCol];
        if (prevRow == row ||
            abs(prevRow - row) == abs(prevCol - col))
        {
            return false; // Row or diagonal conflict
        }
    }
    return true;
}

bool solveNQueens(int col, vector<int> &positions, int n)
{
    if (col == n)
        return true; // All queens placed
    for (int row = 0; row < n; ++row)
    {
        if (isSafe(row, col, positions, n))
        {
            positions[col] = row;
            if (solveNQueens(col + 1, positions, n))
                return true;
        }
    }
    return false; // Backtrack
}

int main()
{
    int n = 8;                    // Change N here for other board sizes
    vector<int> positions(n, -1); // positions[i] = row of queen in column i

    if (solveNQueens(0, positions, n))
    {
        cout << "One possible solution: [";
        for (int i = 0; i < n; ++i)
        {
            cout << positions[i];
            if (i != n - 1)
                cout << ", ";
        }
        cout << "]" << endl;
    }
    else
    {
        cout << "No solution found for N = " << n << endl;
    }

    return 0;
}
