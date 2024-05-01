#include <iostream>
using namespace std;

int main()
{
    int w[] = {20, 25, 10};
    int val[] = {30, 35, 40};
    int W = 40;
    int n = sizeof(val) / sizeof(val[0]);
    float pw[n];

    // Calculate profit-to-weight ratio
    for (int i = 0; i < n; i++)
    {
        pw[i] = (float)val[i] / w[i];
        cout << "Profit-to-weight ratio of item " << i << ": " << pw[i] << endl;
    }

    // Initialize total weight and total value
    float weight = 0;
    int total_value = 0;

    // Greedy approach using the maximum profit-to-weight ratio
    while (W > 0)
    {
        float max_pw = 0; // Initialize max_pw to 0
        int index = -1;

        // Find the maximum profit-to-weight ratio
        for (int i = 0; i < n; i++)
        {
            if (pw[i] > max_pw && w[i] > 0)
            {
                max_pw = pw[i]; // Update max_pw if current pw[i] is greater
                index = i;
            }
        }

        if (index == -1)
            break; // No more items can be selected

        // Take the item with maximum profit-to-weight ratio
        if (weight + w[index] <= W)
        {
            weight += w[index];
            total_value += val[index];
            w[index] = 0; // Mark the item as taken
        }
        else
        {
            float fraction = (float)(W - weight) / w[index];
            weight += w[index] * fraction;
            total_value += val[index] * fraction;
            w[index] = 0; // Mark the item as taken
        }
    }

    cout << "Total value of items selected: " << total_value << endl;

    return 0;
}
