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
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main()
{
    int W = 8;
    int val[] = {
        6,
        2,
        1,
        5,
    };
    int wt[] = {5, 3, 2, 4};
    int n = sizeof(val) / sizeof(val[0]);

    cout << "Maximum value that can be obtained: " << knapsack(W, wt, val, n) << endl;

    return 0;
}
