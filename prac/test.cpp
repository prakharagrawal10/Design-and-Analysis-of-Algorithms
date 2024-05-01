#include <iostream>
#include <algorithm> // for max function
using namespace std;

int knapsack(int W, int wt[], int val[], int n)
{
    int dp[n + 1][W + 1];

    // Initialize the dp array
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
            {
                dp[i][w] = 0;
            }
            else if (wt[i - 1] <= w)
            {
                dp[i][w] = max(val[i - 1] + dp[i][w - wt[i - 1]], dp[i - 1][w]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Backtrack to find counts of each object type included
    int remainingWeight = W;
    int counts[n] = {0};
    for (int i = n; i > 0 && remainingWeight > 0; i--)
    {
        if (dp[i][remainingWeight] != dp[i - 1][remainingWeight])
        {
            counts[i - 1]++;
            remainingWeight -= wt[i - 1];
            i++; // Reconsider the same object type
        }
    }

    // Print the counts of each object type included
    for (int i = 0; i < n; i++)
    {
        cout << counts[i] << " ";
    }
    cout << endl;

    return dp[n][W];
}

int main()
{
    int W = 2000;
    int wt[] = {70, 83, 69, 44, 99, 43, 58, 58};
    int val[] = {72, 84, 73, 46, 99, 43, 60, 60};
    int n = sizeof(val) / sizeof(val[0]);

    cout << "Maximum value that can be obtained: " << knapsack(W, wt, val, n) << endl;

    return 0;
}
